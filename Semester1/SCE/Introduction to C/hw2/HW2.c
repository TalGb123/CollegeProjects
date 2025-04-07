#include <stdio.h>
#define NO_ERROR 0

// Assignmen: 2
// Author: Tal Gubenko
// ID: 215681107

int HighestThreeNumbers();
int ComposeTwoNumbers(int num1, int num2);
int PrimeNumberSplit(int num);
int checkLength(int num);
int idChecker(int id);
int spacer(int n);
int diamondPrinter(int inp);

// Main function to run the program with a menu
int main() {
    int flag = 1;
    while (flag == 1){
        printf("Choose an option:\n");
        printf("1 - Third\n");
        printf("2 - Compose\n");
        printf("3 - Primes\n");
        printf("4 - ID\n");
        printf("5 - Diamond\n");
        printf("6 - Quit\n");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                HighestThreeNumbers();
                break;
            case 2:
            int num1, num2;
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                ComposeTwoNumbers(num1, num2);
                break;
            case 3:
                int num;
                printf("Enter a number:\n");
                scanf("%d", &num);
                PrimeNumberSplit(num);
                break;
            case 4:
                int id; 
                printf("Enter ID with or without check digit:\n");
                scanf("%d", &id);
                idChecker(id);
                break;
            case 5:
                int inp;
                printf("Enter a number: ");
                scanf("%d", &inp);
                diamondPrinter(inp);
                break;
            case 6:
                printf("You chose Quit\n");
                flag = 0;
                break;
            default:
                printf("You chose Invalid option\n");
        }
    }
    return NO_ERROR;
}

// Function to find and print the highest three numbers from a loop of inputs
int HighestThreeNumbers(){
    int inp=0, num1=0, num2=0, num3=0;
    while (inp >= 0) {
        printf("Enter a number (negative number for exit):\n ");
        scanf("%d", &inp);
        if (inp > num1) {
            num3 = num2;
            num2 = num1;
            num1 = inp;
        } else if (inp > num2) {
            num3 = num2;
            num2 = inp;
        } else if (inp > num3) {
            num3 = inp;
        }
    }
    printf("Highest three numbers: %d, %d, %d\n", num1, num2, num3);
    return NO_ERROR;
}

// Function to compose two numbers into a single number
int ComposeTwoNumbers(int num1, int num2){
    int res, len=1;
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
    printf("Composed number: %d\n", res);
    return NO_ERROR;
}

// Function to split a number into its prime factors
int PrimeNumberSplit(int num) {
    printf("Prime factors: ");
    int first = 1; 
    while (num % 2 == 0) {
        if (!first) {
            printf(" * ");
        }
        printf("2");
        num = num / 2;
        first = 0;
    }
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            if (!first) {
                printf("*");
            }
            printf("%d", i);
            num = num / i;
            first = 0;
        }
    }
    if (num > 1) {
        if (!first) {
            printf("*");
        }
        printf("%d\n", num);
        printf("Split is comeplete");
    } 
    printf("\n");
    return NO_ERROR;
}

// Function to check the length (number of digits) of a number
int checkLength(int num) {
    int length = 0;
    while (num >= 1) {
        num /= 10;
        length++;
    }
    return length;
}

// Function to validate an ID based on certain criteria
int idChecker(int id) {
    int flag = 0;
    int temp = -1;
    if (checkLength(id) == 8 || checkLength(id) == 9) {
        if (checkLength(id) == 9) {
            temp = id % 10;
            id /= 10;
            flag = 1;
        }
        int res = 0;
        for (int i=0; i < 8; i++) {
            if (i % 2 == 0) {
                if ((id % 10) * 2 > 9){
                    int temp = (id % 10) * 2;
                    res += (temp % 10) + (temp / 10);
                }
                else {
                    res += (id % 10) * 2;
                }
            } 
            else {
                res += (id % 10);
            }
            id /= 10;
        }
        int check = -1;
        if (res >= 31){
            int nearest_multiple_of_10 = ((res + 9) / 10) * 10;
            check = nearest_multiple_of_10 - res;
        }
        else {
            check = 30 - res;
        }
        if (flag == 1){
            if (check == temp){
                printf("Valid ID when 9 digits\n");
            }
            else {
                printf("Invalid ID when 9 digits\n");
            }
        }
        else{
            printf("Check digit when 8 digits: %d\n", check);
        }
    } 
    else {
        printf("Invalid ID\n");
    }
    return NO_ERROR;
}

// Function to print n spaces
int spacer(int n){
    for (int i=0; i<n; i++){
        printf(" ");
    }
    return NO_ERROR;
}

// Function to print a diamond shape with asterisks
int diamondPrinter(int inp) {
    spacer(inp);
    printf("*\n");
    for (int i=1; i!=inp; i++){
        spacer(inp-i);
        printf("*");
        spacer(i*2-1);
        printf("*\n");
    }
    for (int i=inp-1; i!=0; i--){
        spacer(inp-i);
        printf("*");
        spacer(i*2-1);
        printf("*\n");
    }
    spacer(inp);
    printf("*\n");
    return NO_ERROR;
}