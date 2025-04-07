# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_ERROR 0

int main(){
    int num1;
    printf("Enter a number:\n");
    scanf("%d",&num1);
    switch(num1){
        case 1: 
            printf("Day is Sunday and working hours are 8am to 6pm");
            break;
        case 2: 
            printf("Day is Monday and working hours are 8am to 6pm");
            break;
        case 3: 
            printf("Day is Tuesday and working hours are 8am to 4pm");
            break;
        case 4: 
            printf("Day is Wednesday and working hours are 8am to 6pm");
            break;
        case 5: 
            printf("Day is Thursday and working hours are 8am to 6pm");
            break;
        case 6: 
            printf("Day is Friday and working hours are 8am to 1pm");
            break;
        case 7: 
            printf("Day is Saturday and no working hours today");
            break;
        default:
            printf("Invalid input");
    }
    return NO_ERROR;
}

