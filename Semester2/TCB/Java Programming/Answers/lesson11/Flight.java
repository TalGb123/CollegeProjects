public class Flight {
    private String code;
    private String destination;
    private Time departureTime;
    private int duration;
    private int numOfPassengers;
    private boolean isFull;
    private static final int MAX_PASSENGERS = 10;

    public Flight(String code, String destination, Time departureTime, int duration) {
        this.code = code;
        this.destination = destination;
        this.departureTime = departureTime;
        this.duration = duration;
        this.numOfPassengers = 0;
        this.isFull = this.numOfPassengers >= MAX_PASSENGERS;
    }

    public boolean addPassengers (int num) {
        if (this.isFull) {
            return false;
        }
        this.numOfPassengers += num;
        if (this.numOfPassengers >= MAX_PASSENGERS) {
            this.isFull = true;
        }
        return true;
    }

    public Time getArrivalTime() {
        int totalMinutes = this.departureTime.getHours() * 60 + this.departureTime.getMinutes() + this.duration;
        int arrivalHours = totalMinutes / 60;
        int arrivalMinutes = totalMinutes % 60;

        // Handle overflow for hours
        if (arrivalHours >= 24) {
            arrivalHours = arrivalHours % 24;
        }

        return new Time(arrivalHours, arrivalMinutes);
    }

    public String getCode() {
        return this.code;
    }

    public String getDestination() {
        return this.destination;
    }

    public Time getDepartureTime() {
        return this.departureTime;
    }

    public int getDuration() {
        return this.duration;
    }

    public int getNumOfPassengers() {
        return this.numOfPassengers;
    }

    public boolean isFull() {
        return this.isFull;
    }
}
