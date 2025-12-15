package q9;
public class Employee {
    protected String name;
    protected int num;
    private static int counter = 1; 

    public Employee(String name) {
        this.name = name;
        this.num = counter;
        counter++;
    }
}





