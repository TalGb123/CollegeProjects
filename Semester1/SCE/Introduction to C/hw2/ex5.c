#include <stdio.h>
#define NO_ERROR 0

void spacer(int n){
    for (int i=0; i<n; i++){
        printf(" ");
    }
}

int main() {
    int inp;
    printf("Enter a number: ");
    scanf("%d", &inp);
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
    printf("*");
    
    return NO_ERROR;
}

