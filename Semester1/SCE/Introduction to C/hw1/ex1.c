# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_ERROR 0

int main(){
    int num1;
    int num2;
    printf("Enter two numbers:\n ");
    scanf("%d %d",&num1, &num2);
    if (num1 % num2 == 0){
        printf("Divided without remainder %d", num1 / num2);
    }
    else{
        printf("Divided with remainder %d", num1 % num2);
    }
    return NO_ERROR;
}

