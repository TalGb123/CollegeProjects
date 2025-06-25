using System.IO.MemoryMappedFiles;
using System.Timers;
using Manager;
using SuperSimpleTcp;
using Timer = System.Timers.Timer;

const string mmfGuid = "FlightsMMF";
const byte departure = 0x5D;
const byte weAreTooRichNow = 0x7A;
const byte allFlightsSoldOut = 0x9E;
const int weAreTooRichThreshold = 60000; 
const int departureTimeoutMs = 5000; 
object consoleLock = new object();

MemoryMappedFile mmf = MemoryMappedFile.CreateOrOpen(mmfGuid, 1024);
Mutex mmfMutex = new Mutex(false, $"Global\\{mmfGuid}");
SimpleTcpClient tcpClient = new SimpleTcpClient("127.0.0.1:17000");
Timer mmfReadTimer = new Timer(1000); 
Timer departureTimer = new Timer(departureTimeoutMs); 

int totalRevenue = 0;
int totalClientsServed = 0;
bool endOfOperationCalled = false;
object endOfOperationLock = new object();

PrintWithLock("Manager starting...");
PrintWithLock($"WeAreTooRich threshold: {weAreTooRichThreshold}");
PrintWithLock($"Departure timeout: {departureTimeoutMs}ms");

PrintWithLock("Attempting to connect to Sales TCP server at 127.0.0.1:17000...");
tcpClient.Events.DataReceived += OnDataReceived;
tcpClient.Events.Connected += OnConnected;
tcpClient.Events.Disconnected += OnDisconnected;

try
{
    tcpClient.Connect();
    PrintWithLock("Successfully connected to Sales server!");
}
catch (Exception ex)
{
    PrintWithLock($"Failed to connect to Sales server: {ex.Message}");
    Console.ReadLine();
    return;
}

mmfReadTimer.Elapsed += ReadMmfEverySecond;
mmfReadTimer.AutoReset = true;
mmfReadTimer.Start();

departureTimer.Elapsed += DepartureTimerOnElapsed;
departureTimer.AutoReset = false; 
departureTimer.Start();

Console.WriteLine("Manager started. Monitoring sales...");
Console.WriteLine("Press Enter to stop...");
Console.ReadLine();
return;

void OnConnected(object? sender, ConnectionEventArgs e)
{
    PrintWithLock($"Connected to Sales server: {e.IpPort}");
}

void OnDisconnected(object? sender, ConnectionEventArgs e)
{
    PrintWithLock($"Disconnected from Sales server: {e.IpPort}");
}

void OnDataReceived(object? sender, DataReceivedEventArgs e)
{
    if (e.Data.Count != 1) 
    {
        PrintWithLock($"[OnDataReceived] Unexpected data length: {e.Data.Count}");
        return;
    }
    byte code = e.Data[0];
    PrintWithLock($"[OnDataReceived] Received byte code: 0x{code:X2}");
    if (code == allFlightsSoldOut)
    {
        PrintWithLock($"[OnDataReceived] [Manager] Received code from Sales: AllFlightsSoldOut");
        EndOfOperation(Reason.SoldOut);
    }
    else if (code == departure)
    {
        PrintWithLock($"[OnDataReceived] [Manager] Received code from Sales: Departure");
        EndOfOperation(Reason.Departure);
    }
    else if (code == weAreTooRichNow)
    {
        PrintWithLock($"[OnDataReceived] [Manager] Received code from Sales: WeAreTooRich");
        EndOfOperation(Reason.TooRich);
    }
    else
    {
        PrintWithLock($"[OnDataReceived] Unknown code received: 0x{code:X2}");
    }
}

void EndOfOperation(Reason reason)
{
    lock (endOfOperationLock)
    {
        if (endOfOperationCalled) return;
        endOfOperationCalled = true;
    }
    mmfReadTimer.Stop();
    departureTimer.Stop();
    string reasonText = reason switch
    {
        Reason.Departure => "DEPARTURE",
        Reason.TooRich => "WE ARE TOO RICH NOW",
        Reason.SoldOut => "ALL FLIGHTS SOLD OUT",
        _ => reason.ToString()
    };
    PrintWithLock($"END OF PROGRAM: {reasonText}");
    tcpClient.Disconnect();
}

void DepartureTimerOnElapsed(object? sender, ElapsedEventArgs e)
{
    lock (endOfOperationLock)
    {
        if (endOfOperationCalled) return;
    }
    PrintWithLock($"[DepartureTimerOnElapsed] [Manager] Departure timer elapsed: sending Departure code to Sales");
    try
    {
        tcpClient.Send(new byte[] { departure });
        PrintWithLock("Departure code sent successfully");
    }
    catch (Exception ex)
    {
        PrintWithLock($"Failed to send departure code: {ex.Message}");
    }
    EndOfOperation(Reason.Departure);
}

void ReadMmfEverySecond(object? sender, ElapsedEventArgs e)
{
    try
    {
        ReadMmf();
        PrintWithLock($"[ReadMmfEverySecond] [Manager] Reading mmf data : TotalClientsServed={totalClientsServed}, TotalRevenue={totalRevenue}");
        if (totalRevenue >= weAreTooRichThreshold)
        {
            PrintWithLock("[ReadMmfEverySecond] [Manager] We are so rich now... Sending WeAreTooRichNow code to Sales");
            try
            {
                tcpClient.Send(new byte[] { weAreTooRichNow });
                PrintWithLock("WeAreTooRichNow code sent successfully");
            }
            catch (Exception ex)
            {
                PrintWithLock($"Failed to send WeAreTooRichNow code: {ex.Message}");
            }
            EndOfOperation(Reason.TooRich);
        }
    }
    catch (Exception ex)
    {
        PrintWithLock($"Error in ReadMmfEverySecond: {ex.Message}");
    }
}

void ReadMmf()
{

    bool mutexAcquired = false;
    try
    {
        mutexAcquired = mmfMutex.WaitOne(5000); 
        if (!mutexAcquired)
        {
            PrintWithLock("Warning: Failed to acquire MMF mutex within 5 seconds");
            return;
        }

        using var accessor = mmf.CreateViewAccessor(0, 8);
        totalRevenue = accessor.ReadInt32(0);
        totalClientsServed = accessor.ReadInt32(4);
    }
    catch (Exception ex)
    {
        PrintWithLock($"Error reading MMF: {ex.Message}");
    }
    finally
    {
        if (mutexAcquired)
        {
            mmfMutex.ReleaseMutex();
        }
    }
}

void PrintWithLock(string message)
{
    lock (consoleLock)
    {
        Console.WriteLine(message);
    }
}