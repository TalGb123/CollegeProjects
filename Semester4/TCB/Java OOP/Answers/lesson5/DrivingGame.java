import java.util.ArrayList;
import java.util.List;

public class DrivingGame {
      private final Map map;
      private final List<Vehicle> vehicles = new ArrayList<>();

      public DrivingGame(int junctionCount, int vehicleCount) {
            map = new Map(junctionCount);

            for (int i = 0; i < vehicleCount; i++) {
                  vehicles.add(new Vehicle(map));
            }
      }

      public void play(int turns) {
            for (int t = 1; t <= turns; t++) {
                  System.out.println("\nTurn " + t);

                  for (Vehicle v : vehicles) {
                  v.move();
                  }

                  for (TrafficLight tl : map.GetTrafficLights()) {
                  tl.check();
                  }
            }
      }
}
