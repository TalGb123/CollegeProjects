public class Payment {
    private String name;
    private int num;
    private double fuel;

    Payment(String name, int num, double fuel) {
        this.name = name;
        this.num = num;
        this.fuel = fuel;
    }

    public String getName() {
        return name;
    }

    public int getNum() {
        return num;
    }

    public double getFuel() {
        return fuel;
    }

    public String toString() {
        return "Payment{name='" + name + "', num=" + num + ", fuel=" + fuel + "}";
    }
}
