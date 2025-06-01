public class q1 {
      public static void RecursiveTriangle(int n) {
            if (n == 0) {
                  return;
            }
            for (int i = n; i > 0; i--) {
                  System.out.print("*");
            }
            System.out.println();
            RecursiveTriangle(n - 1);
      }

      public static void ReversedText(String str){
            if (str.isEmpty()) {
                  return;
            }
            ReversedText(str.substring(1));
            System.out.print(str.charAt(0));
      }

      public static int howManyChar(String s, char c){
            if (s.isEmpty()) {
                  return 0;
            }
            int count = (s.charAt(0) == c) ? 1 : 0;
            return count + howManyChar(s.substring(1), c);
      }

      public static boolean newOrder(int n) {
            if (n == 0) {
                  return true;
            }
            int lastDigit = n % 10;
            n /= 10;
            if (n % 10 > lastDigit) {
                  return false;
            }
            return newOrder(n);
      }

      public static void main(String[] args) {
            RecursiveTriangle(5);
            ReversedText("Hello");
<<<<<<< HEAD:Semester2/TCB/Java Programming/lesson7/q1.java
            System.out.println(howManyChar("Hello", 'l'));
            System.out.println(newOrder(12345));
=======
            System.out.print(howManyChar("hello", 'l'));
            System.out.print(newOrder(13333));
>>>>>>> 0d53df1839303054d69a329efc98e905a98f3bbb:Semester2/TCB/Java Programming/lesson7/lesson7.java
      }
}