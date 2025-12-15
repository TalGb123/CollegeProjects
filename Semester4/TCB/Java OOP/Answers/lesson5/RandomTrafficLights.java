import java.util.List;
import java.util.Random;

public class RandomTrafficLights extends TrafficLight {
    private static final Random rand = new Random();

    public RandomTrafficLights(Junction junction, int delay) {
        super(junction, delay);
        chooseNewGreen();
    }

    private void chooseNewGreen() {
        List<Road> incoming = junction.GetEnteringRoads();
        if (incoming.isEmpty()) {
            currentGreen = null;
        } else {
            currentGreen = incoming.get(rand.nextInt(incoming.size()));
        }
    }

    @Override
    public void check() {
        List<Road> incoming = junction.GetEnteringRoads();
        if (incoming.isEmpty()) return;

        counter--;

        if (counter == 0) {
            chooseNewGreen();
            counter = delay;
            System.out.println("Random TrafficLights Junction " 
                + junction.toString().replace(" at Point", "") 
                + ", delay= " + delay + ": green light on " + currentGreen);
        }
    }
}
