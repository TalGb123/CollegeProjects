import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Map {
      private final List<Junction> junctions;
      private final List<Road> roads;
      private final List<TrafficLight> trafficLights = new ArrayList<>();
      private static final Random rand = new Random();

      public Map(int n) {
            junctions = new ArrayList<>();
            roads = new ArrayList<>();

            // create random junctions
            for (int i = 0; i < n; i++) {
                  junctions.add(new Junction());
            }

            // create random roads
            for (Junction from : junctions) {
                  int outgoing = 1 + rand.nextInt(Math.max(1, n / 2));

                  for (int i = 0; i < outgoing; i++) {
                        Junction to = junctions.get(rand.nextInt(n));
                        roads.add(new Road(from, to));
                  }
            }

            addTrafficLightsRandomly();
      }

      public Map(List<Junction> junctions, List<Road> roads) {
            this.junctions = junctions;
            this.roads = roads;

            for (Road r : roads) {
                  if (!r.GetStart().GetExitingRoads().contains(r))
                        r.GetStart().GetExitingRoads().add(r);
                  if (!r.GetEnd().GetEnteringRoads().contains(r))
                        r.GetEnd().GetEnteringRoads().add(r);
            }

            addTrafficLightsRandomly();
      }

      private void addTrafficLightsRandomly() {
            for (Junction j : junctions) {
                  if (j.GetEnteringRoads().size() > 1) {
                  if (rand.nextDouble() <= 0.25) {
                        int delay = 2 + rand.nextInt(3); // 2,3,4
                        boolean randomType = rand.nextBoolean();

                        TrafficLight tl;

                        if (randomType) {
                              tl = new RandomTrafficLights(j, delay);
                              trafficLights.add(tl);
                              System.out.println("Random TrafficLights "
                              + j.toString().replace(" at Point", "")
                              + ", delay= " + delay + ": green light on " + tl.GetCurrentGreen());

                        } else {
                              tl = new SequentialTrafficLights(j, delay);
                              trafficLights.add(tl);
                              System.out.println("Sequential TrafficLights "
                              + j.toString().replace(" at Point", "")
                              + ", delay= " + delay + ": green light on " + tl.GetCurrentGreen());
                        }
                  }
                  }
            }
      }

      public Junction GetRandomJunction() {
            return junctions.get(rand.nextInt(junctions.size()));
      }

      public List<Road> CreateRandomPath(Junction start) {
            List<Road> path = new ArrayList<>();
            Junction current = start;

            while (path.size() < 4 && !current.GetExitingRoads().isEmpty()) {
                  Road r = current.GetExitingRoads().get(rand.nextInt(current.GetExitingRoads().size()));
                  path.add(r);
                  current = r.GetEnd();
            }

            return path;
      }

      public List<TrafficLight> GetTrafficLights() { return trafficLights; }

      public TrafficLight getTrafficLightOf(Junction j) {
            for (TrafficLight tl : trafficLights) {
                  if (tl.junction == j)
                        return tl;
            }
            return null;
      }

}
