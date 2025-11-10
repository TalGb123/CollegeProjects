public class PrimeNumbers {
      public static void main(String[] args) {
            int limit = 200;
            for (int i = 2; i <= limit; i++) {
                  if (isPrime(i)) {
                        System.out.print(i + " ");
                  }
            }
      }

      public static boolean isPrime(int number) {
            if (number <= 1) {
                  return false;
            }
            for (int i = 2; i <= Math.sqrt(number); i++) {
                  if (number % i == 0) {
                        return false;
                  }
            }
            return true;
      }
}
