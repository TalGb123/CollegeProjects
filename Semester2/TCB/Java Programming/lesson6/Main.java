public class Main {
    public static void main(String[] args) {
        Apartment ap = new Apartment("Standard", 2, 80.0, 3);
        Penthouse ph = new Penthouse("Luxury", 5, 120.0, 4, 30.0);
        GroundAp ga = new GroundAp("GardenView", 90.0, 3, true, 40.0);

        System.out.println(ap);
        System.out.println(ph);
        System.out.println(ga);
    }
}