#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_ERROR 0
int main(){
    float num1, num2, num3;
    int flag = 0;
    printf("Enter three numbers:\n");
    scanf("%f %f %f", &num1, &num2, &num3);
    if (num1 >= 0 && num2 >= 0 && num3 >= 0) {
        if (num1 + num2 >= num3 && num1 + num3 >= num2 && num2 + num3 >= num1) {
            printf("A triangle");
            flag+=1;
        }
    }
    if (flag == 0) {
        printf("Not a triangle");
    }
    
    return NO_ERROR;
}

