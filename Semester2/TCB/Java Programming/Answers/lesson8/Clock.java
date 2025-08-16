public class Clock
{
      private final int hour;
      private final int min;

      public Clock(int h, int m)
      {
            this.hour = h;
            this.min = m;
      }

      public int GetInterval(){
            return (24*60 - (hour * 60 + min));
      }
}