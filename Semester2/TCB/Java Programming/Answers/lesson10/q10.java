class q10 {
      public static void main(String[] args) {
            int[] arr = {1, 2, 3, 4, 5};
            int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                  sum += arr[i];
            }
            System.out.println("Sum of array elements: " + sum);
      }

      public static int sumNum(int num) {
            int sum = 0;
            while (num > 0) {
                  sum += num % 10;
                  num /= 10;
            }
            return sum;
      }

      public static boolean weightArray(int[] arr) {
            for (int i=0; i < arr.length; i++) {
                  for (int j=i+1; j < arr.length; j++) {
                        if (sumNum(arr[i]) == sumNum(arr[j])) {
                              return false;
                        }
                  }
            }
            return true;
      }

      public static boolean SameWeight(int[] arr1, int[] arr2) {
            if (arr1.length != arr2.length) {
                  return false;
            }
            for (int i = 0; i < arr1.length; i++) {
                  for (int j = 0; j < arr2.length; j++) {
                        if (sumNum(arr1[i]) == sumNum(arr2[j])) {
                              break;
                        }
                        if (j == arr2.length - 1) {
                              return false;
                        }
                  }
            }
            return true;
      }

      // first is O(n) and second+third are O(n^2)

}