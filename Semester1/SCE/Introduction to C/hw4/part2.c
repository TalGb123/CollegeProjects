#include <stdio.h>
#include <stdlib.h>
#define NO_ERROR 0


int* SymmetricDiff(int* one, int sizeOne, int* two, int sizeTwo, int* pNewSize) {
    int* newArr = (int*)malloc((sizeOne + sizeTwo) * sizeof(int));
    if (newArr == NULL) {
        return NULL;
    }
    *pNewSize = 0;
    int found = 0;
    for (int i = 0; i < sizeOne; i++) {
        found = 0;
        for (int j = 0; j < sizeTwo; j++) {
            if (one[i] == two[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            newArr[*pNewSize] = one[i];
            (*pNewSize)++;
        }
    }
    for (int i = 0; i < sizeTwo; i++) {
        found = 0;
        for (int j = 0; j < sizeOne; j++) {
            if (two[i] == one[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            newArr[*pNewSize] = two[i];
            (*pNewSize)++;
        }
    }
    return newArr;
}

int main() {
    int one[] = {1, 3, 4, 6, 10, 13, 14, 7, 8, 9};
    int two[] = {2, 3, 6, 15, 16, 18, 20, 9, 11, 13};
    int newSize;
    int* result = SymmetricDiff(one, sizeof(one)/sizeof(one[0]), two, sizeof(two)/sizeof(two[0]), &newSize);

    if (result != NULL) {
        for (int i = 0; i < newSize; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    return NO_ERROR;
}