/*
assignment: 5
name: Tal Gubenko
id: 215681107
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_ERROR 0

// Define the Course structure
typedef struct {
    char courseName[50];
    int grade;
} Course;

// Define the Student structure
typedef struct {
    char studentName[50];
    int size; // Number of courses
    Course* course_arr; // Array of courses
} Student;

void InputCourse(Course* pCourse);
void PrintCourse(Course course);
void InputStudent(Student* pSt);
void PrintStudent(Student st);
Student* Build(int* pSize);
void FreeAll(Student* pSt, int size);
void PrintAll(Student* arrSt, int size);
void CourseList(Student* arrSt, int size, char* CourseName);


int main() {
    int size;
    // Build the array of students
    Student* students = Build(&size);

    // Print all students
    PrintAll(students, size);

    // List students who passed a specific course
    CourseList(students, size, "Math");

    // Free all allocated memory
    FreeAll(students, size);
    return 0;
}

// Function to input course details
void InputCourse(Course* pCourse) {
    printf("Enter course name: ");
    scanf("%s", pCourse->courseName);
    printf("Enter grade: ");
    scanf("%d", &pCourse->grade);
}

// Function to print course details
void PrintCourse(Course course) {
    printf("Course: %s, Grade: %d\n", course.courseName, course.grade);
}

// Function to input student details
void InputStudent(Student* pSt) {
    printf("Enter student name: ");
    scanf("%s", pSt->studentName);
    printf("Enter number of courses: ");
    scanf("%d", &(*pSt).size);
    // Allocate memory for the array of courses
    pSt->course_arr = (Course*)malloc((*pSt).size * sizeof(Course));
    if ((*pSt).course_arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // Input details for each course
    for (int i = 0; i < pSt->size; i++) {
        InputCourse(&(*pSt).course_arr[i]);
    }
}

// Function to print student details
void PrintStudent(Student st) {
    printf("Name: %s\n", st.studentName);
    for (int i = 0; i < st.size; i++) {
        PrintCourse(st.course_arr[i]);
    }
}

// Function to build an array of students
Student* Build(int* pSize) {
    printf("Enter how many students you want to enter: ");
    scanf("%d", pSize);
    // Allocate memory for the array of students
    Student* arr = (Student*)malloc(*pSize * sizeof(Student));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // Input details for each student
    for (int i = 0; i < *pSize; i++) {
        InputStudent(&arr[i]);
    }
    return arr;
}

// Function to free all allocated memory
void FreeAll(Student* pSt, int size) {
    for (int i = 0; i < size; i++) {
        free(pSt[i].course_arr);
    }
    free(pSt);
}

// Function to print all students
void PrintAll(Student* arrSt, int size) {
    for (int i = 0; i < size; i++) {
        PrintStudent(arrSt[i]);
    }
}

// Function to list students who passed a specific course
void CourseList(Student* arrSt, int size, char* CourseName) {
    printf("\nThose who passed course %s: ", CourseName);
    for (int i = 0; i < size; i++) {
        Student* stdnt = &arrSt[i];
        Course* crsArr = stdnt->course_arr;
        for (int j = 0; j < stdnt->size; j++) {
            if (strcmp(crsArr[j].courseName, CourseName) == 0 && crsArr[j].grade > 55) {
                printf("%s, ", stdnt->studentName);
            }
        }
    }
    printf("\n");
}


