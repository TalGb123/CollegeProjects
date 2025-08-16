public class Main {
      public static void main(String[] args) {
            // q2
            // Clock flight1 = new Clock(23, 59);
            // Clock flight2 = new Clock(20, 59);
            // int f1LandingTime = flight1.GetInterval();
            // int f2LandingTime = flight2.GetInterval();
            // System.out.println("Interval: " + f1LandingTime + " minutes");
            // System.out.println("Interval: " + f2LandingTime + " minutes");
            // if (f1LandingTime > f2LandingTime) {
            //       System.out.println("Flight 1 lands first");
            // } else if (f1LandingTime < f2LandingTime) {
            //       System.out.println("Flight 2 lands first");
            // } else {
            //       System.out.println("Both flights land at the same time");
            // }

            // q4
            // int[] arr={22,56,123,12,10,-4,2};
            // System.out.println(isBalanced(arr));
      }

      public static boolean isBalanced(int[] arr){
            if (arr.length < 3) {
                  System.out.println("Array length is less than 3");
                  return false;
            }
            if (arr.length % 2 == 0) {
                  System.out.println("Array length is even");
                  return false;
            }
            int midIndex = arr.length / 2;
            int mid = arr[midIndex];
            for (int i = 0; i < arr.length; i++) {
                  if (i < midIndex) {
                        if (arr[i] <= mid) {
                              System.out.println("Left side is not greater than mid");
                              return false;
                        }
                  } else if (i > midIndex) {
                        if (arr[i] >= mid) {
                              System.out.println("Right side is not lesser than mid");
                              return false;
                        }
                  }
            }
            return true;
      }
}
