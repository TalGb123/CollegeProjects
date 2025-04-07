#include <string.h>
#include <stdio.h>
#define NO_ERROR 0

int ex5(char string1[]){
    int len=0;
    for (int i=0; string1[i] != '\0'; i++){
        len++;
    }
    int dotCount = 0;
    int dotFlag = 0;
    int object = 0;
    int num2_index = 0;
    int N = 0;
    int M = 0;
    char operator;
    char num1[20];
    char num2[20];
    for (int i=0; i<len; i++){
        if (string1[i] == ' '){
            object++;
            dotFlag = 0;
            if (object == 1){
                operator = string1[i+1];
                i++;
            }
        }
        else if (object == 0){
            num1[i] = string1[i]; 
            if (string1[i] == '.'){
                dotCount++;
                dotFlag = 1;
            }
            else if (dotFlag == 1){
                M++;
            }
        }
        else if (object == 2){
            num2[num2_index] = string1[i];
            num2_index++;
            if (string1[i] == '.'){
                dotCount++;
                dotFlag = 1;
            }
            else if (dotCount == 2){
                N++;
            }
        }
    }
    num2[num2_index] = '\0';
    printf("num1: %s\n", num1);
    printf("M: %d\n", M);
    printf("operator: %c\n", operator);
    printf("num2: %s\n", num2);
    printf("N: %d\n", N);
    if (operator == '+'){
        if (M > N){
            printf("The result is %.%df", M, num1);
        }
    }
    else if (operator == '-'){
        if (M > N){
            printf("The result is %.%df", M, num1);
        }
    }
    else if (operator == '*'){
        int res = num1 * num2;
    }
    else if (operator == '/'){
        if (M > N){
            printf("The result is %.%df", M, num1);
        }
    }
    else{
        printf("Invalid operator\n");
        return -1;
    }
    if (dotCount == 2){
        if (M > N){
            printf("The result is %.%df", M, num1);
        }
    }
    return NO_ERROR;
}

int ex6(char string2[]){
    char new[80];
    int count = 0;
    int tempCount = 0;
    while (string2[count] != '\0'){
        if (string2[count] == ' ') {
            new[count] = ' '; 
            tempCount = 0;
        } else {
            new[count] = string2[count] - (tempCount + 1);
            tempCount++;
        }
        count++;
    }
    new[count] = '\0'; 
    printf("Decrypted string: %s\n", new);
    return NO_ERROR;
}

int main(){
    char string1[80];
    char string2[80];
    printf("Enter the calculator string: ");
    gets(string1);
    
    printf("Enter the decryption string: ");
    gets(string2);

    ex5(string1);
    // ex6(string2);
    return NO_ERROR;
}