#include <stdio.h>
#define NO_ERROR 0

int main() {
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
    printf("%d %d %d\n", num1, num2, num3);

    return NO_ERROR;
}