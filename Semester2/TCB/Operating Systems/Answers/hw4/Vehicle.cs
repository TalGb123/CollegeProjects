internal class Vehicle
{
      public CancellationToken CancellationToken;
      private static int id = 1;
      private static object idLock = new();
      private int _idValue;
      public int Id
      {
            get
            {
                  lock (idLock)
                  {
                        return _idValue;
                  }
            }
      }
      
      public Vehicle(CancellationToken token)
      {
            lock (idLock)
            {
                  _idValue = id++;
            }
            CancellationToken = token;
      }
}