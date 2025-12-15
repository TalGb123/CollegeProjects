import java.util.List;

public class SequentialTrafficLights extends TrafficLight {
    private int index = 0;

    public SequentialTrafficLights(Junction junction, int delay) {
        super(junction, delay);

        List<Road> incoming = junction.GetEnteringRoads();
        if (!incoming.isEmpty()) {
            currentGreen = incoming.get(0);
        }
    }

    @Override
    public void check() {
        List<Road> incoming = junction.GetEnteringRoads();
        if (incoming.isEmpty()) return;

        counter--;

        if (counter <= 0) {
            index = (index + 1) % incoming.size();
            currentGreen = incoming.get(index);
            counter = delay;

            System.out.println("Sequential TrafficLights Junction "
                + junction.toString().replace(" at Point", "")
                + ", delay= " + delay + ": green light on " + currentGreen);
        }
    }
}
