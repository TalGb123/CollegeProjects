public class Point {
      private double x;
      private double y;

      public Point(double x, double y) {
            boolean replaced = false;
            double rx = x;
            double ry = y;

            if (x < 0 || x > 800) {
                  System.out.println(x + " is illegal value for x and has been replaced with");
                  rx = Math.random() * 800;
                  System.out.println(rx);
                  replaced = true;
            }
            if (y < 0 || y > 600) {
                  System.out.println(y + " is illegal value for y and has been replaced with");
                  ry = Math.random() * 600;
                  System.out.println(ry);
                  replaced = true;
            }

            this.x = rx;
            this.y = ry;

            System.out.println("Creating Point (" + String.format("%.2f", this.x) +
                  ", " + String.format("%.2f", this.y) + ")");
      }   
      
      public Point() {
            this.x = Math.random() * 800;
            this.y = Math.random() * 600;
      }

      public double CalcDistance(Point other) {
          double dx = this.x - other.x;
          double dy = this.y - other.y;
          return Math.sqrt(dx * dx + dy * dy);
      }

      public double GetX() {return x;}
      public double GetY() {return y;}
      public void SetX(double x) {this.x = x;}
      public void SetY(double y) {this.y = y;}

      @Override
      public String toString() {
            return "(" + String.format("%.2f", x) + ", " + String.format("%.2f", y) + ")";
      }
}
