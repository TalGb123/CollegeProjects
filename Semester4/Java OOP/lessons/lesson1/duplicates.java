public class duplicates {
      public static void main(String[] args) {
            int num = 265455125;     
            DuplicatesSum(num);
      }

      public static int[] DuplicateCount(int num) {
            int[] digitCount = new int[10];
            for (int i = 0; i < String.valueOf(num).length(); i++) {
                  int digit = Character.getNumericValue(String.valueOf(num).charAt(i));
                  digitCount[digit]++;
            }
            return digitCount;
      }

      public static void DuplicatesSum(int num) {
            int[] counts = DuplicateCount(num);
            int sum = 0;
            String oddDigits = "";
            for (int i=0; i<counts.length; i++) {
                  if (counts[i] % 2 == 0 && counts[i] != 0) {
                        
                        System.out.print(i + ",");
                  }
                  else if (counts[i] % 2 != 0 && counts[i] != 0) {
                        sum += i;
                        oddDigits += i + " ";
                  }
            }
            System.out.print(" sum:" + sum);
            
      }
}
