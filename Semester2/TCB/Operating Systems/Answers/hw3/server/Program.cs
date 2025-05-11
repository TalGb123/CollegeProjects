using System.IO.MemoryMappedFiles;
using System.Text.Json;

class Program
{ 
  static void GetMessageBytesFromMMF(Stream stream, byte[] buffer, int offset, int count)
  {
    int read, total = 0;
    while (total < count && (read = stream.Read(buffer, offset + total, count - total)) > 0)
      total += read;
    if (total < count)
      throw new EndOfStreamException();
  }

  static void WriteBufferToMMF(MemoryMappedFile mmf, byte[] jsonBytes)
  {
    using (var stream = mmf.CreateViewStream())
    {
      stream.Write(jsonBytes, 0, jsonBytes.Length);
    }
  }

  static void Main(string[] args){
    bool createdNew;
    using (EventWaitHandle clientToServer = new EventWaitHandle(false, EventResetMode.AutoReset, "clientToServerEvent", out createdNew))
    using (EventWaitHandle serverToClient = new EventWaitHandle(false, EventResetMode.AutoReset, "serverToClientEvent", out createdNew))
    {
      Console.WriteLine("Server waiting for signal from client...");
      clientToServer.WaitOne(); 
      Console.WriteLine("Signal received from client!");
      try{
        if (!OperatingSystem.IsWindows())
        {
          throw new PlatformNotSupportedException("Memory-mapped files are only supported on Windows.");
        }
        using (MemoryMappedFile mmf = MemoryMappedFile.OpenExisting("testmap"))
        {
          Order? order;
          using (var stream = mmf.CreateViewStream())
          {
            byte[] lengthBytesRead = new byte[4];
            GetMessageBytesFromMMF(stream, lengthBytesRead, 0, 4);
            int jsonLength = BitConverter.ToInt32(lengthBytesRead, 0); 
            byte[] jsonOrderBytes = new byte[jsonLength];
            GetMessageBytesFromMMF(stream, jsonOrderBytes, 0, jsonLength);
            string jsonOrder = System.Text.Encoding.UTF8.GetString(jsonOrderBytes);
            order = JsonSerializer.Deserialize<Order>(jsonOrder);
            Console.WriteLine($"Server received order: {order}");
          }
          Response responseToSend = new Response(true, DateTime.Now.AddDays(3));
          Console.WriteLine($"Server send response: {responseToSend}");
          string responseJson = JsonSerializer.Serialize(responseToSend);
          byte[] responseBytes = new byte[responseJson.Length + 4];
          byte[] responseLengthBytes = BitConverter.GetBytes(responseJson.Length);
          Array.Copy(responseLengthBytes, 0, responseBytes, 0, 4);
          System.Text.Encoding.UTF8.GetBytes(responseJson, 0, responseJson.Length, responseBytes, 4);
          WriteBufferToMMF(mmf, responseBytes);
        }
        serverToClient.Set(); 
      }
      catch (FileNotFoundException ex)
      {
        Console.WriteLine("Memory-mapped file not found. Please ensure the client has created it.");
        Console.WriteLine(ex.Message);
      }
      catch (EndOfStreamException ex)
      {
        Console.WriteLine("Error reading from memory-mapped file: " + ex.Message);
      }
      catch (JsonException ex)
      {
        Console.WriteLine("Error deserializing JSON: " + ex.Message);
      }
      catch (Exception ex)
      {
        Console.WriteLine("An unexpected error occurred: " + ex.Message);
      }
    }
  }
}

internal record Response(
  bool Accepted,
  DateTime EstimatedSupplyDate
);

internal record Order(
  decimal MoneyAmount,
  string Currency,
  string Product,
  int ProductAmount
);
