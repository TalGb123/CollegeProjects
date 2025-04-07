# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_ERROR 0

int main(){
    int num1, num2, num3;
    printf("Enter three numbers:\n");
    scanf("%d %d %d",&num1, &num2, &num3);
    if (num1 > num2 && num2 > num3) { printf("Descending Order"); }
    else if (num1 < num2 && num2 < num3) { printf("Ascending Order"); }
    else{ printf("Not sorted"); }
    return NO_ERROR;
}

