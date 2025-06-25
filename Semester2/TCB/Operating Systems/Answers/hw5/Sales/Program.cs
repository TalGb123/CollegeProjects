using System.Collections.Concurrent;
using System.IO.MemoryMappedFiles;
using System.Timers;
using Sales;
using SuperSimpleTcp;
using Timer = System.Timers.Timer;


const string mmfGuid = "FlightsMMF";
const byte departure = 0x5D;
const byte weAreTooRichNow = 0x7A;
const byte allFlightsSoldOut = 0x9E;
const int nWorkers = 5;
const int nFlights = 3;
string? managerIpPort = null;
object consoleLock = new object();
bool endOfSalesCalled = false;
Timer clientCreationTimer = new Timer();
CancellationTokenSource cts = new CancellationTokenSource();
ConcurrentQueue<Client> clientQueue = new ConcurrentQueue<Client>();

List<Flight> flights = new List<Flight>();
for (int i = 0; i < nFlights; i++)
{
    flights.Add(new Flight());
}

MemoryMappedFile mmf = MemoryMappedFile.CreateOrOpen(mmfGuid, 1024);
SimpleTcpServer tcpServer = new SimpleTcpServer("127.0.0.1:17000");
Mutex mmfMutex = new Mutex(false, $"Global\\{mmfGuid}");
SalesStat salesStat = new SalesStat();

InitializeSharedMemory();
StartTcpServer();
Console.WriteLine("Press any key when manager process ready..");
Console.ReadKey();
StartClientFactory();
StartWorkerThreads();
Console.ReadLine();
return;

void InitializeSharedMemory()
{
    mmfMutex.WaitOne();
    try
    {
        using var accessor = mmf.CreateViewAccessor(0, 8);
        accessor.Write(0, salesStat.TotalRevenue);
        accessor.Write(4, salesStat.TotalClientsServed);
    }
    finally
    {
        mmfMutex.ReleaseMutex();
    }
}

void StartTcpServer()
{
    tcpServer.Events.DataReceived += TcpServerOnDataReceived;
    tcpServer.Events.ClientConnected += TcpServerOnClientConnected;
    tcpServer.Start();
    Console.WriteLine("TCP Server started on 127.0.0.1:17000");
}

void TcpServerOnDataReceived(object? sender, DataReceivedEventArgs e)
{
    if (e.Data.Count != 1)
    {
        return;
    }
    var code = e.Data[0];
    if (code == weAreTooRichNow)
    {
        EndOfSales(Reason.TooRich);
    }
    else if (code == departure)
    {
        EndOfSales(Reason.Departure);
    }
}

void TcpServerOnClientConnected(object? sender, ConnectionEventArgs e)
{
    managerIpPort = e.IpPort;
    PrintWithLock($"Manager connected: {managerIpPort}");
    PrintWithLock("Sales system is now ready to start processing clients!");
}

void UpdateSharedMemory()
{
    mmfMutex.WaitOne();
    try
    {
        using var accessor = mmf.CreateViewAccessor(0, 8);
        accessor.Write(0, salesStat.TotalRevenue);
        accessor.Write(4, salesStat.TotalClientsServed);
    }
    finally
    {
        mmfMutex.ReleaseMutex();
    }
}

void Sell(object? obj)
{
    Worker worker = (Worker)obj!;
    while (!cts.Token.IsCancellationRequested)
    {
        if (clientQueue.TryDequeue(out Client? client))
        {
            bool sold = false;
            foreach (var flight in flights)
            {
                if (flight.TryBookSeat(out int cost))
                {
                    sold = true;
                    string seatType = cost == Flight.FirstClassCost ? "First class" : "Economy class";
                    PrintWithLock($"[Sell] [{worker.Id}]Worker sold {seatType} to [{client.Id}]Client");
                    salesStat.TotalClientsServed++;
                    salesStat.TotalRevenue += cost;
                    UpdateSharedMemory();
                    break;
                }
            }
            if (!sold)
            {
                bool allSoldOut = true;
                foreach (var flight in flights)
                {
                    if (flight.FirstClassSeats > 0 || flight.EconomyClassSeats > 0)
                    {
                        allSoldOut = false;
                        break;
                    }
                }
                if (allSoldOut)
                {
                    EndOfSales(Reason.SoldOut);
                    return;
                }
            }
        }
        else
        {
            Thread.Sleep(50);
        }
    }
}

void EndOfSales(Reason reason)
{
    if (endOfSalesCalled) return;
    endOfSalesCalled = true;
    cts.Cancel();
    clientCreationTimer.Stop();
    string reasonText = reason switch
    {
        Reason.Departure => "DEPARTURE",
        Reason.TooRich => "WE ARE TOO RICH",
        Reason.SoldOut => "ALL FLIGHTS SOLD OUT",
        _ => reason.ToString()
    };
    PrintWithLock($"END OF SALES: {reasonText}");
    if (reason == Reason.SoldOut && managerIpPort != null)
    {
        var data = new byte[] { allFlightsSoldOut };
        tcpServer.Send(managerIpPort, data);
    }
}

void StartWorkerThreads()
{
    for (int i = 0; i < nWorkers; i++)
    {
        var worker = new Worker(cts.Token);
        Thread workerThread = new Thread(Sell);
        workerThread.Start(worker);
    }
}

void StartClientFactory()
{
    clientCreationTimer.Interval = 100;
    clientCreationTimer.Elapsed -= CreateClient;
    clientCreationTimer.Elapsed += CreateClient;
    clientCreationTimer.AutoReset = true;
    clientCreationTimer.Start();
}

void CreateClient(object? sender, ElapsedEventArgs e)
{
    if (endOfSalesCalled) return;
    Client client = new Client();
    PrintWithLock($"[CreateClient] [{client.Id}]Client created");
    clientQueue.Enqueue(client);
}

void PrintWithLock(string message)
{
    lock (consoleLock)
    {
        Console.WriteLine(message);
    }
}