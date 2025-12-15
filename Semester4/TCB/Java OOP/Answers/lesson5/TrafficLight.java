public abstract class TrafficLight {
    protected Junction junction;
    protected int delay;
    protected int counter;
    protected Road currentGreen;

    public TrafficLight(Junction junction, int delay) {
        this.junction = junction;
        this.delay = delay;
        this.counter = delay;
    }

    public abstract void check();

    public Road GetCurrentGreen() {
        return currentGreen;
    }

    @Override
    public String toString() {
        return (this instanceof RandomTrafficLights ? 
                "Random TrafficLights " : 
                "Sequential TrafficLights ")
            + junction + ", delay= " + delay;
    }

}
