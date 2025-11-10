
import java.util.Scanner;

public class Fibonacci {
      public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the number of Fibonacci numbers to generate: ");
            int n = scanner.nextInt();
            int fib1 = 0, fib2 = 1, nextFib = 0;
            System.out.print(fib1 + " ");
            System.out.print(fib2 + " ");

            if (n > 1) {
                  for (int i=0; i<n-1; i++){
                        nextFib = fib1 + fib2;
                        System.out.print(nextFib + " ");
                        fib1 = fib2;
                        fib2 = nextFib;
                  }
            }
      }
}
