package lesson1;
import java.util.*;
public class mymain {
	
	public static void MulBoard() {
		for (int i=1; i<11; i++) {
			for (int j=1; j<11; j++) {
				System.out.print(i*j + " ");
			}
			System.out.println();
		}
	}
	
	public static boolean isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
	
	public static void PrintPrime() {
		for (int i=1; i<21; i++) {
			if (isPrime(i)) {
				System.out.print(i + " ");
			}
		}
	}
	
	public static void PrintEqualHalves() {
		for (int i=1000; i<10000; i++) {
			int left = i / 100;
			int right = i % 100;
			if (Math.pow(left+right, 2) == i) {
				System.out.print(i + " ");
			}
		}
	}
	
	public static void Pascal() {
		Scanner console=new Scanner(System.in);
		System.out.print("enter rows:");
		int rows=console.nextInt();
		console.close();

		for (int i=1; i<=rows; i++) {
			for (int j=0; j<rows-i; j++) {
				System.out.print(" ");
			}
			for (int j=1; j<=i; j++) {
				System.out.print(j);
			}
			for (int j=i-1; j>=1; j--) {
				System.out.print(j);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		// MulBoard();
		// PrintPrime();
		// PrintEqualHalves();
		Pascal();
;	}
}
