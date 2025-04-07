#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_ERROR 0


char* NewString(char* str) {
    int len = strlen(str);
    char* newStr = (char*)malloc(len * 10 + 1); // Allocate enough memory for the worst case
    if (newStr == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    int newIndex = 0; int k = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int num = str[i] - '0';
            for (int j = 0; j < num; j++) {
                newStr[newIndex] = str[i];
                newIndex++;
            }
        } else if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            newStr[newIndex] = '*';
            newIndex++;
            k = i;
            while (str[k] >= 'A' && str[k] <= 'Z' || str[k] >= 'a' && str[k] <= 'z') {
                k++;
            }
            i = k-1;
        } else if (str[i] == ' ') {
            newStr[newIndex] = '-';
            newIndex++;
        }
    }
    newStr[newIndex] = '\0'; // Null-terminate the new string
    return newStr;
}

int main(){
    //char myString[] = "42 qqq231 hh 425 abc 1023";
    char* myString[50];
    char* copiedString = NewString(myString);
    if (copiedString != NULL) {
        printf("%s\n", copiedString); // Output: A333B22
        free(copiedString); // Don't forget to free the allocated memory
    }
    return NO_ERROR;
}