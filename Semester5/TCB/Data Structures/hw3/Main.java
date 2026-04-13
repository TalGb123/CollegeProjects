
public class Main {
    public static int[] getIntersection(int[] arr1, int[] arr2) {
        int[] temp = new int[Math.min(arr1.length, arr2.length)];
        int count = 0;
        for (int i = 0; i < arr1.length; i++) {
            for (int j = 0; j < arr2.length; j++) {
                if (arr1[i] == arr2[j]) {
                    temp[count] = arr1[i];
                    count++;
                    break;
                }
            }
        }
        return temp;
    }

    public static boolean isUpperTriangular(int[][] mtrx) {
        int n = mtrx.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (mtrx[i][j] != 0) {
                    return false; 
                }
            }
        }
        return true;
    }

    public static boolean isMainDiagonalNonZero(int[][] mtrx) {
        int n = mtrx.length;
        for (int i = 0; i < n; i++) {
            if (mtrx[i][i] == 0) {
                return false;
            }
        }
        return true;
    }
}
