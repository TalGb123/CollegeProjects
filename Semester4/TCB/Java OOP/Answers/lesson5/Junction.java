import java.util.ArrayList;
import java.util.List;

public class Junction extends Point {
      private static int nextId = 1;
      private final int id;
      private final List<Road> enteringRoads = new ArrayList<>();
      private final List<Road> exitingRoads = new ArrayList<>();

      public Junction() {
            super();
            this.id = nextId++;
            System.out.println("Creating Junction " + id + " at Point " + super.toString());
      }

      public Junction(double x, double y) {
            super(x, y);
            this.id = nextId++;
            System.out.println("Creating Junction " + id + " at Point " + super.toString());
      }

      public List<Road> GetEnteringRoads() { return enteringRoads; }
      public List<Road> GetExitingRoads() { return exitingRoads; }

      @Override
      public String toString() {
            return "Junction " + id;
      }
}
