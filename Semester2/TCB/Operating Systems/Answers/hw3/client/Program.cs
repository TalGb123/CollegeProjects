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

  static void Main(string[] args)
  {
    using (MemoryMappedFile mmf = MemoryMappedFile.CreateNew("testmap", 10000))
    {
      Order order = new Order(100, "USD", "ProductA", 2);
      Console.WriteLine($"Client send order: {order}");
      string json = JsonSerializer.Serialize(order);
      byte[] jsonBytes = new byte[json.Length + 4];
      byte[] lengthBytesWrite = BitConverter.GetBytes(json.Length);
      Array.Copy(lengthBytesWrite, 0, jsonBytes, 0, 4); 
      System.Text.Encoding.UTF8.GetBytes(json, 0, json.Length, jsonBytes, 4);
      WriteBufferToMMF(mmf, jsonBytes);
      bool createdNew;
      using (EventWaitHandle clientToServer = new EventWaitHandle(false, EventResetMode.AutoReset, "clientToServerEvent", out createdNew))
      using (EventWaitHandle serverToClient = new EventWaitHandle(false, EventResetMode.AutoReset, "serverToClientEvent", out createdNew))
      {
            Console.WriteLine("Signaling server...");
            clientToServer.Set(); 
            Console.WriteLine("Waiting for signal from server...");
            serverToClient.WaitOne(); 
            Console.WriteLine("Signal received from server, continuing...");
            using (var stream = mmf.CreateViewStream())
            {    
                  byte[] lengthBytesRead = new byte[4];
                  GetMessageBytesFromMMF(stream, lengthBytesRead, 0, 4);
                  int jsonLength = BitConverter.ToInt32(lengthBytesRead, 0); 
                  byte[] jsonResponseBytes = new byte[jsonLength];
                  GetMessageBytesFromMMF(stream, jsonResponseBytes, 0, jsonLength);
                  string jsonResponse = System.Text.Encoding.UTF8.GetString(jsonResponseBytes);
                  Response response = JsonSerializer.Deserialize<Response>(jsonResponse)!;
                  Console.WriteLine($"Client received response: {response}");
            }
      }
     }      
   }
}

internal record Order(
      decimal MoneyAmount,
      string Currency,
      string Product,
      int ProductAmount
);

internal record Response(
    bool Accepted,
    DateTime EstimatedSupplyDate
);
