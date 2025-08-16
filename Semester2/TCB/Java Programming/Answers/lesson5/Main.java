//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Point p1 = new Point(0, 10);
        Point p2 = new Point(8, 0);
        Line line = new Line(p1, p2);
        System.out.println("Equation of the line: " + line.getEquation());
        System.out.println("Distance between the points: " + line.distance());
    }
}