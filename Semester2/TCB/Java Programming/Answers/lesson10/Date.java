public class Date {
      private int day;
      private int month;
      private int year;

      public Date(int day, int month, int year) {
            this.day = day;
            this.month = month;
            this.year = year;
      }

      public boolean Equals(Date other) {
            return this.day == other.day && this.month == other.month && this.year == other.year;
      }

      public boolean Before(Date other) {
            if (this.year < other.year) {
                  return true;
            } 
            else if (this.year == other.year) {
                  if (this.month < other.month) {
                        return true;
                  } 
                  else if (this.month == other.month) {
                        return this.day < other.day;
                  }
            }
            return false;
      }
}
