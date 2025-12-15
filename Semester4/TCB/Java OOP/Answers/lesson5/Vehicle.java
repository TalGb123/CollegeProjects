import java.util.List;
import java.util.Random;

public class Vehicle {
      private static int nextId = 1;
      private final int id;
      private final int speed;
      private List<Road> path;
      private int currentRoadIndex = 0;
      private double distanceOnRoad = 0;
      private boolean finished = false;
      private Map map;

      private static final Random rand = new Random();

      public Vehicle(Map map) {
            this.id = nextId++;
            this.speed = 30 + rand.nextInt(91);
            this.map = map;
            Junction start = map.GetRandomJunction();
            this.path = map.CreateRandomPath(start);

            System.out.println("Creating Vehicle " + id + ",speed: " + speed + ", path: " + buildPathString());
      }

      private String buildPathString() {
            String s = "[";
            for (int i = 0; i < path.size(); i++) {
                  s += path.get(i).toString();
                  if (i < path.size() - 1) s += ", ";
            }
            s += "]";
            return s;
      }

      public void move() {
            if (finished) return;

            Road currentRoad = path.get(currentRoadIndex);
            distanceOnRoad += speed;

            // reached end of road
            if (distanceOnRoad >= currentRoad.GetLength()) {
                  Junction end = currentRoad.GetEnd();

                  // last road?
                  if (currentRoadIndex == path.size() - 1) {
                        finished = true;
                        System.out.println("Vehicle " + id 
                        + " arrived to it's destination: " 
                        + end);
                        return;
                  }

                  // want to enter next road
                  Road nextRoad = path.get(currentRoadIndex + 1);

                  // check for traffic light
                  TrafficLight tl = map.getTrafficLightOf(end);

                  if (tl != null && tl.GetCurrentGreen() != nextRoad) {
                        // RED LIGHT → WAIT
                        System.out.println("Vehicle " + id 
                        + " is waiting for green light at " 
                        + end);
                        return; // STOP here!
                  }

                  // GREEN LIGHT → MOVE ON
                  currentRoadIndex++;
                  distanceOnRoad = 0;
                  System.out.println("Vehicle " + id 
                        + " is moving on the " 
                        + nextRoad);
            }
            else {
                  // still on same road
                  System.out.println("Vehicle " + id 
                        + " is moving on the " 
                        + currentRoad);
            }
            }

}
