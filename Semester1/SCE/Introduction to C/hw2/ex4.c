#include <stdio.h>
#define NO_ERROR 0

int check_length(int num) {
    int length = 0;
    while (num >= 1) {
        num /= 10;
        length++;
    }
    return length;
}

int main() {
    int id = 329358899;
    int flag = 0;
    int temp = -1;
    if (check_length(id) == 8 || check_length(id) == 9) {
        if (check_length(id) == 9) {
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
                printf("Valid ID when 9\n");
            }
            else {
                printf("Invalid ID when 9\n");
            }
        }
        else{
            printf("Check num when 8: %d\n", check);
        }
    } 
    else {
        printf("Invalid ID\n");
    }

    return NO_ERROR;
}