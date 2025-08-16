public class Airport {
    private Flight[] flights;
    private int numOfFlights;

    public Airport(int maxFlights) {
        this.flights = new Flight[maxFlights];
        this.numOfFlights = 0;
    }

    public Time firstFlightToPlace(String place) {
        Time earliestTime = null;

        for (int i = 0; i < numOfFlights; i++) {
            Flight flight = flights[i];
            if (flight.getDestination().equals(place)) {
                Time departureTime = flight.getDepartureTime();
                if (earliestTime == null || departureTime.before(earliestTime)) {
                    earliestTime = departureTime;
                }
            }
        }

        return earliestTime;
    }

    public boolean movePassengers(String codeF, int num){
        for (int i = 0; i < numOfFlights; i++) {
            if (flights[i].getCode().equals(codeF)) {
                String dest = flights[i].getDestination();
                Time arrivalTime = flights[i].getArrivalTime();
                Time firstFlightTime = firstFlightToPlace(dest);
                if (firstFlightTime == arrivalTime) {
                    return false;
                }
                else {
                    for (int j = 0; j < numOfFlights; j++) {
                        if (flights[j].getDestination().equals(dest) && (flights[j].getDepartureTime().before(arrivalTime) || 
                        flights[j].getDepartureTime().getHours() == arrivalTime.getHours() && flights[j].getDepartureTime().getMinutes() < arrivalTime.getMinutes())) {
                            if (flights[j].addPassengers(num)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
}
