# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_ERROR 0

int main(){
    int num1;
    printf("Enter a number:\n");
    scanf("%d",&num1);
    switch (num1){
        case 0:
            printf("-----");
            break;
        case 1:
            printf(".----");
            break;
        case 2:
            printf("..---");
            break;
        case 3:
            printf("...--");
            break;
        case 4:
            printf("....-");
            break;
        case 5:
            printf(".....");
            break;
        case 6:
            printf("-....");
            break;
        case 7:
            printf("--...");
            break;
        case 8:
            printf("---..");
            break;
        case 9:
            printf("----.");
            break;
    }
    return NO_ERROR;
}

