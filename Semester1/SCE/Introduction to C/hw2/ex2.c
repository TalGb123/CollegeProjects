#include <stdio.h>
#define NO_ERROR 0

int ex1(num1,num2) {
    int res, len=1;
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    while (num2 > 0) {
        res += (num2 % 10) * len;
        len *= 10;
        num2 /= 10;
    }
    while (num1 > 0) {
        res += (num1 % 10) * len;
        len *= 10;
        num1 /= 10;
    }
    return res;
}