
import java.util.Scanner;

public class CircleArea {
      public static void main(String[] args) {
            double radius, area;
            Scanner scanner = new Scanner(System.in);
            System.out.print("Please enter radius: ");
            radius = scanner.nextDouble();
            area = Math.PI * radius * radius;
            System.out.printf("The area of the circle is %.15f%n", area);
      }
}
