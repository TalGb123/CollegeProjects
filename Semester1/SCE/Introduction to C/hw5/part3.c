/*
assignment: 5
name: Tal Gubenko
id: 215681107
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_ERROR 0

// Function to calculate the average grade from a file
int AvgFromFile(char* filename, double* pAvg);

int main() {
    double average;
    char filename[30];
    
    // Prompt the user to enter the file name
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // Call the function to calculate the average grade from the file
    int result = AvgFromFile(filename, &average);
    
    // Check the result and print the appropriate message
    if (result == NO_ERROR) {
        printf("Average grade: %.2f\n", average);
    } else if (result == 1) {
        printf("Error: File not found\n");
    } else if (result == -1) {
        printf("Error: No valid grades found\n");
    }
    
    return 0;
}

// Function to calculate the average grade from a file
int AvgFromFile(char* filename, double* pAvg) {
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        // Return 1 if the file is not found
        return 1;
    }
    
    int count = 0;
    double sum = 0;
    double grade;
    
    // Read grades from the file and calculate the sum and count of valid grades
    while (fscanf(fptr, "%lf", &grade) == 1) {
        if (grade >= 0 && grade <= 100) {
            sum += grade;
            count++;
        }
    }
    
    fclose(fptr);
    
    // Return -1 if no valid grades are found
    if (count == 0) {
        return -1;
    }
    
    // Calculate the average and store it in pAvg
    *pAvg = sum / count;
    
    // Return 0 to indicate success
    return NO_ERROR;
}