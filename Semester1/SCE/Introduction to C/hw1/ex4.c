# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_ERROR 0

int main(){
    int num1, num2, num3;
    printf("Enter three numbers:\n");
    scanf("%d %d %d",&num1, &num2, &num3);
    if (num1 > num2 && num2 > num3) { printf("%d %d %d", num3, num2, num1); }
    if (num3 > num2 && num2 > num1) { printf("%d %d %d", num1, num2, num3); }
    if (num2 > num1 && num1 > num3) { printf("%d %d %d", num3, num1, num2); }
    if (num2 > num3 && num3 > num1) { printf("%d %d %d", num1, num3, num2); }
    if (num1 > num3 && num3 > num2) { printf("%d %d %d", num2, num3, num1); }
    if (num3 > num1 && num1 > num2) { printf("%d %d %d", num2, num1, num3); }
    return NO_ERROR;
}

