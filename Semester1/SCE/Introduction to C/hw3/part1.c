#include <stdio.h>
#define NO_ERROR 0

// need to check if i need to check what array is bigger
int ex1 (int arr1[], int arr2[], int len1, int len2){
    int count = 0;
    if (len1 > len2){
        for (int i=0; i<len1; i++){
            if (arr1[i] == arr2[0]){
                for (int j=0; j<len2; j++){
                    if (arr1[i+j] != arr2[j]){
                        count = 0;
                        break; // need to change it later
                    }
                    else{
                        count++;
                    }
                }
                if (count == len2){
                    return i;
                }
            }
        }
    }
    else{
        for (int i=0; i<len2; i++){
            if (arr2[i] == arr1[0]){
                for (int j=0; j<len1; j++){
                    if (arr2[i+j] != arr1[j]){
                        count = 0;
                        break; // need to change it later
                    }
                    else{
                        count++;
                    }
                }
                if (count == len1){
                    return i;
                }
            }
        }
    }
    return -1;
}

int ex2(int arr[], int len){
    int streaksCount = 0;
    int count = 0;
    int longestCount = 2;
    int longestIndex = 0;
    int flag = 0; // 0 - no streak, 1 - increasing
    for (int i=1; i<len; i++){
        if (flag == 0){
            if (arr[i] > arr[i-1]){
                flag = 1;
                count = 2;
                streaksCount++;
            }
        }
        else {
            if (arr[i] <= arr[i-1]){
                flag = 0;
                if (count > longestCount){
                    longestCount = count;
                    longestIndex = i - count;
                }
            }
            else {
                count++;
            }
        }
    }
    for (int i=longestIndex; i<longestIndex+longestCount; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return streaksCount;
}

int main(){
    // ex1
    // int arr1[] = {2, 4, 61, 5, 8, 5, 56, 89, 3, -2};
    // int arr2[] = {5, 56, 89, 3, -2};

    // ex2
    // int arr[] = {-3, 8, 23, -60, -54, 6, 87, -43, 12, -7};
    #define N 10
    #define M 5
    int One[N], Two[M];
    printf("first array\n");    
    for (int i=0; i<N; i++){
        printf("Enter a number for index #%d: ", i+1);
        scanf("%d", &One[i]);
    }
    printf("second array\n");
    for (int i=0; i<M; i++){
        printf("Enter a number for index #%d: ", i+1);
        scanf("%d", &Two[i]);
    }
    printf("The sub-array starts at index %d\n", ex1(One, Two, N, M));
    printf("The number of streaks is %d\n", ex2(One, N));
    return NO_ERROR;
}
