#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkNameInput(char* name) {
    for (int i = 0; i < strlen(name); i++) {
        if (i == 0 && (name[i] < 'A' || name[i] > 'Z')) {
            return 0;
        } else if (i > 0 && (name[i] < 'a' || name[i] > 'z')) {
            return 0;
        }
    }
    return 1;
}

int checkGradeInput(int grade) {
    if (grade < 0 || grade > 100) {
        return 0;
    }
    return 1;
}

// need to add a check for name input if name already exists
void Init(char*** names, int** grades, int* size) {
    printf("Enter the number of students: ");
    scanf("%d", size);
    *names = (char**)malloc(*size * sizeof(char*));
    *grades = (int*)malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        (*names)[i] = (char*)malloc(50 * sizeof(char));
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", (*names)[i]);
        while (!checkNameInput((*names)[i])) {
            printf("Wrong, enter the name of student %d: ", i + 1);
            scanf("%s", (*names)[i]);
        }
        printf("Enter the grade of student %d: ", i + 1);
        scanf("%d", &(*grades)[i]);
        while (!checkGradeInput((*grades)[i])) {
            printf("Wrong, enter the grade of student %d: ", i + 1);
            scanf("%d", &(*grades)[i]);
        }
    }
}



int main() {
    char** names;
    int* grades;
    int size;

    Init(&names, &grades, &size);

    printf("Student Information:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d: Name = %s, Grade = %d\n", i + 1, names[i], grades[i]);
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(names[i]);
    }
    free(names);
    free(grades);

    return 0;
}