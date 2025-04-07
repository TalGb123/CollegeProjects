#include <stdio.h>
#define NO_ERROR 0

int PrimeNumberSplit(num) {
    while (num > 1){
        if (num % 2 == 0){
            printf("2");
            num = num / 2;
        } 
        else if (num % 3 == 0){
            printf("3");
            num = num / 3;
        } 
        else if (num % 5 == 0){
            printf("5");
            num = num / 5;
        } 
        else if (num % 7 == 0){
            printf("7");
            num = num / 7;
        }
        else{
            num = 0;
        }
        if (num > 1){
            printf("*");
        }
    }
    return NO_ERROR;
}