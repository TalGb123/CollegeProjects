//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static int LeftDigit(int num){
        while (num/10 != 0){
            num /= 10;
        }
        return num;
    }

    public static boolean NumEqualizer(int[] nums){
        for (int i=0; i<nums.length-1; i++){
            if (LeftDigit(nums[i+1]) != nums[i]%10){
                return false;
            }
        }
        return true;
    }

    public static int method(int x){
        int[] count = {0,0,0,0,0,0,0,0,0,0};
        while (x != 0){
            count[x%10]++;
            x /= 10;
        }
        int maxC = 0;
        int maxN = 0;
        for (int i=0; i<10; i++){
            if (count[i] > maxC){
                maxN = i;
                maxC = count[i];
            }
        }
        return maxN;
    }

    public static int method1(int[] nums){
        int num = nums[0];
        int streakCount = 1;
        int maxStreak = 1;
        int maxNum = nums[0];
        for (int i=1; i<nums.length; i++){
            if (nums[i] == num){
                streakCount++;
            }
            else{
                if (streakCount > maxStreak){
                    maxStreak = streakCount;
                    maxNum = num;
                }
                num = nums[i];
                streakCount = 1;
            }
        }
        if (streakCount > maxStreak) {
            maxStreak = streakCount;
            maxNum = num;
        }
        return maxNum;
    }

    public static int method2(int[][] mtr){
        int[] minNums = new int[mtr[0].length];
        for (int i=0; i<mtr[0].length; i++){
            int minNum = 10000000;
            for (int j=0; j<mtr.length; j++){
                if (mtr[j][i] < minNum){
                    minNum = mtr[j][i];
                }
            }
            minNums[i] = minNum;
        }
        int maxNum = 0;
        for (int i=0; i< minNums.length; i++){
            if (minNums[i] > maxNum){
                maxNum = minNums[i];
            }
        }
        return maxNum;
    }

    public static void main(String[] args) {
        int[] ex1 = {134, 43, 31, 1259, 93, 345, 510};
        int[] ex2 = {1, 2, 2, 1, 1, 3};
        int[][] ex4 = {{45, 81, 65, 12, 12}, {98, 12, 88, 45, 12}, {11, 22, 12, 90, 35}, {2, 13, 0, 11, 77}, {12, 3, 7, 82, 12}};
        //System.out.println(NumEqualizer(ex1));
        //System.out.println(method(10100));
        //System.out.println(method1(ex2));
        //System.out.println(method2(ex4));

    }
}