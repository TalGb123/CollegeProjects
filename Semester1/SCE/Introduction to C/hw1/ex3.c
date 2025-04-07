#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_ERROR 0

int main(){
    int num1;
    int flag = 0;
    printf("Enter a number:\n");
    scanf("%d", &num1);
    if ((num1 / 1000 == num1 % 10) && (num1 / 100 % 10 == num1 /10 % 10)){
        printf("The number is a palindrome");
        flag = 1;
    }
    if (flag == 0){
        printf("The number is not a palindrome");
    }
    return NO_ERROR;
}

