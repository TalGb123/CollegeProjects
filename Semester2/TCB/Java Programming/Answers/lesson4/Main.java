


public class Main {
    public static void main(String[] args) {
//        Client client1 = new Client("John", "Doe", 25, 1, 2, 5);
//        Client client2 = new Client(client1);
//
//        System.out.println("Client 1: " + client1.Print());
//        System.out.println("Client 2: " + client2.Print());
//
//        double dollar = 3.6; // Example dollar value
//        System.out.println("Client 1 Payment: " + client1.Pay(dollar));
//        System.out.println("Client 2 Payment: " + client2.Pay(dollar));
//
//        System.out.println("Client 1 Discount: " + client1.Discount());
//        System.out.println("Client 2 Discount: " + client2.Discount());

        Time time1 = new Time(7, 30, 0);
        Time time2 = new Time(time1);

        System.out.println("Time 1: " + time1.Print());
        System.out.println("Time 2: " + time2.Print());
        time2.SetHour(15);
        System.out.println("Time 2 after setting hour to 15: " + time2.Print());
    }
}