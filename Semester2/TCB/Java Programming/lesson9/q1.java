class q1 {
      public static void main(String[] args) {
            int[] arr = {4, 10, 13, 71, 10, 10, 71, 71, 2, 10};
            System.out.println(minNum(arr));
      }

      public static int dist(int[] arr, int num){
            if (arr == null || arr.length == 0) {
                  return 0;
            }
            int start = 0;
            int end = 0;
            boolean endFlag = false;
            boolean startFlag = false;
            for (int i=0; i<arr.length/2; i++) {
                  if (arr[i] == num && startFlag == false) {
                        start = i;
                        startFlag = true;
                  }
                  if (arr[arr.length-1-i] == num && endFlag == false) {
                        end = i;
                        endFlag = true;
                  }
            }
            if (start > 0 || end > 0) {
                  return end + start;
            }
            return -1;
      }

      public static int minNum(int[] arr) {
            if (arr == null || arr.length == 0) {
                  System.out.println("Array is empty or null");
                  return -1;
            }
            int minDist = Integer.MAX_VALUE;
            int minNum = -1;
            for (int i = 0; i < arr.length; i++) {
                  int tempDist = dist(arr, arr[i]);
                  if (tempDist != -1 && tempDist < minDist) {
                        minDist = tempDist;
                        minNum = arr[i];
                  }
            }
            return minNum;
      }
}