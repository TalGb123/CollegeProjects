/*
assignment: 5
name: Tal Gubenko
id: 215681107
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_ERROR 0

void printNumbers(int begin, int end, int skip);
int countOddDigits(long num);
void printLatinOnly(char inp[]);
int onlyLatin(char inp[]);
int consistDigits(char inp[]);
int isFibSeries(int arr[], int size);
int checkArrays(int arr1[], int arr2[], int size, int value);

int main() {
    char str1[] = "abc12DEF+3?4aa+a",str2[] = "abcaaa";
    int arr1[] = { 7,8,15,23,38,61,99,160,259 }, arr2[] = {7,8,16,23,38};
    int arr3[]={14,16,32,46,76};
    printNumbers(53, 89, 10);//53 63 73 83
    printf("\n%d\n", countOddDigits(6778987));//4
    printLatinOnly(str1);//abcDEFaaa
    printf("\n%d %d\n", onlyLatin(str1), onlyLatin(str2));//0 1
    printf("%d %d\n", consistDigits(str1), consistDigits(str2));//1 0
    printf("%d %d\n", isFibSeries(arr1, 9), isFibSeries(arr2, 5));//1 0
    printf("%d\n", checkArrays(arr2,arr3,5,2));//1
    return NO_ERROR;
}

// Function to print numbers from 'begin' to 'end' with a step of 'skip'
void printNumbers(int begin, int end, int skip) {
    // Base case: if 'begin' is greater than or equal to 'end', stop recursion
    if (begin >= end) {
        return;
    }
    // Print the current number
    printf("%d ", begin);
    // Recursive call to print the next number
    printNumbers(begin + skip, end, skip);
}

// Function to count the number of odd digits in a given number 'num'
int countOddDigits(long num) {
    // Base case: if 'num' is 0, return 0
    if (num == 0) {
        return 0;
    }
    // Initialize count to 0
    int count = 0;
    // Check if the last digit of 'num' is odd
    if (num % 10 % 2 != 0) {
        count++;
    }
    // Recursive call to process the next digit and add the count
    return count + countOddDigits(num / 10);
}

// Function to print only Latin letters from the input string 'inp'
void printLatinOnly(char* inp) {
    // Base case: if the end of the string is reached, stop recursion
    if (*inp == '\0') {
        return;
    }
    // Check if the current character is a Latin letter
    if ((inp[0] >= 'A' && inp[0] <= 'Z') || (inp[0] >= 'a' && inp[0] <= 'z')) {
        // Print the current character
        printf("%c", *inp);
    }
    // Recursive call to process the next character
    printLatinOnly(inp + 1);
}

// Function to check if the input string 'inp' contains only Latin letters
int onlyLatin(char* inp) {
    // Base case: if the end of the string is reached, return 1 (true)
    if (*inp == '\0') {
        return 1;
    }
    // Check if the current character is not a Latin letter
    if (!((inp[0] >= 'A' && inp[0] <= 'Z') || (inp[0] >= 'a' && inp[0] <= 'z'))) {
        // Return 0 (false) if a non-Latin letter is found
        return 0;
    }
    // Recursive call to process the next character
    return onlyLatin(inp + 1);
}

// Function to check if the input string 'inp' consists of digits only
int consistDigits(char* inp) {
    // Base case: if the end of the string is reached, return 0 (false)
    if (*inp == '\0') {
        return 0;
    }
    // Check if the current character is a digit
    if (inp[0] >= '0' && inp[0] <= '9') {
        // Return 1 (true) if a digit is found
        return 1;
    }
    // Recursive call to process the next character
    return consistDigits(inp + 1);
}

// Function to check if the array 'arr' of size 'size' is a Fibonacci series
int isFibSeries(int* arr, int size) {
    // Base case: if the size is less than 3, return 1 (true) because a Fibonacci series of size 2 or less is trivially true
    if (size < 3) {
        return 1;
    }
    // Check if the first three elements form a Fibonacci sequence
    if (arr[0] + arr[1] != arr[2]) {
        // Return 0 (false) if the sequence is not a Fibonacci series
        return 0;
    }
    // Recursive call to check the rest of the array
    return isFibSeries(arr + 1, size - 1);
}

// Function to check if elements in 'arr1' multiplied by 'value' match elements in 'arr2'
int checkArrays(int* arr1, int* arr2, int size, int value) {
    // Base case: if the size is 0, all elements have been checked and matched
    if (size == 0) {
        return 1;
    }
    // Check if the current element in 'arr1' multiplied by 'value' matches the current element in 'arr2'
    if (arr1[0] * value != arr2[0]) {
        // Return 0 (false) if the elements do not match
        return 0;
    }
    // Recursive call to check the next elements
    return checkArrays(arr1 + 1, arr2 + 1, size - 1, value);
}