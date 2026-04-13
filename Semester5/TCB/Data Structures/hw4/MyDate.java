public class MyDate {
    private int day;
    private int month;
    private int year;

    public MyDate(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public int compareTo(MyDate other) {
    if (this.year != other.year) return this.year - other.year;
    if (this.month != other.month) return this.month - other.month;
    return this.day - other.day;
}

    public static void bubbleSort(MyDate[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j].compareTo(arr[j + 1]) > 0) {
                    MyDate temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void selectionSort(MyDate[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int index_max = 0;
            for (int j = 1; j < arr.length - i; j++) {
                if (arr[j].compareTo(arr[index_max]) > 0) {
                    index_max = j;
                }
            }
            MyDate temp = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = arr[index_max];
            arr[index_max] = temp;
        }
    }

    public static void insertionSort(MyDate[] arr) {
        for (int i = 1; i < arr.length; i++) {
            MyDate key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j].compareTo(key) > 0) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    public static MyDate[] mergeArrays(MyDate[] arr1, MyDate[] arr2) {
        MyDate[] merged = new MyDate[arr1.length + arr2.length];
        int i = 0, j = 0, k = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[i].compareTo(arr2[j]) <= 0) {
                merged[k++] = arr1[i++];
            } 
            else {
                merged[k++] = arr2[j++];
            }
        }
        while (i < arr1.length) {
            merged[k++] = arr1[i++];
        }
        while (j < arr2.length) {
            merged[k++] = arr2[j++];
        }
        return merged;
    }

    public static void mergeSort(MyDate[] arr) {
        MyDate[] helper = new MyDate[arr.length];
        mergeSortRecursive(arr, 0, arr.length - 1, helper);
    }

    private static void mergeSortRecursive(MyDate[] arr, int low, int high, MyDate[] helper) {
        if (low < high) {
            int middle = (low + high) / 2;
            mergeSortRecursive(arr, low, middle, helper);
            mergeSortRecursive(arr, middle + 1, high, helper);
            merge(arr, low, middle, high, helper);
        }
    }

    private static void merge(MyDate[] arr, int low, int middle, int high, MyDate[] helper) {
        for (int i = low; i <= high; i++) {
            helper[i] = arr[i];
        }

        int i = low;
        int j = middle + 1;
        int k = low;      

        while (i <= middle && j <= high) {
            if (helper[i].compareTo(helper[j]) <= 0) {
                arr[k] = helper[i];
                i++;
            } 
            else {
                arr[k] = helper[j];
                j++;
            }
            k++;
        }
        while (i <= middle) {
            arr[k] = helper[i];
            k++;
            i++;
        }
    }
    public static void quickSort(MyDate[] arr) {
        quicksortRecursive(arr, 0, arr.length - 1);
    }

    private static void quicksortRecursive(MyDate[] arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            quicksortRecursive(arr, low, pivotIndex - 1);
            quicksortRecursive(arr, pivotIndex + 1, high);
        }
    }

    private static int partition(MyDate[] arr, int low, int high) {
        MyDate pivotValue = arr[low];
        int left = low + 1;
        int right = high;
        while (left <= right) {
            while (left <= high && arr[left].compareTo(pivotValue) <= 0) {
                left++;
            }
            while (right > low && arr[right].compareTo(pivotValue) > 0) {
                right--;
            }
            if (left < right) {
                swap(arr, left, right);
            }
        }
        swap(arr, low, right);
        return right;
    }

    private static void swap(MyDate[] arr, int i, int j) {
        MyDate temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public int getDay() { return day; }
    public int getMonth() { return month; }
    public int getYear() { return year; }

    public String toString() {
        return day + "/" + month + "/" + year;
    }
}
