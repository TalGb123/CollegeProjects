// Creator: Tal Gubenko
// ID: 215681107
// Assignment: 1

#include "Employee.h"
#include <string.h>
#include <iostream>
using namespace std;

// Checks if a given string contains only numeric characters
bool Employee::isNumeric(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

// Sets default values for an Employee object
void Employee::SetDefaults() {
    strcpy(this->name, "Unknown");
    strcpy(this->id, "000000000");
    this->seniority = 0;
    this->excellence = 0;
    this->hasDegree = false;
}

// Default constructor, initializes an Employee with default values
Employee::Employee() {
    SetDefaults();
}

// Parameterized constructor, initializes an Employee with given values
Employee::Employee(const char* name, const char* id, int seniority, int excellence, bool hasDegree) {
    if (name && strlen(name) < sizeof(this->name)) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }
    else strcpy(this->name, "Unknown");

    if (id && strlen(id) == 9 && id[0] != '0' && isNumeric(id)) {
        strncpy(this->id, id, sizeof(this->id) - 1);
        this->id[sizeof(this->id) - 1] = '\0';
    }
    else strcpy(this->id, "000000000");

    if (seniority > 0) this->seniority = seniority; 
    else this->seniority = 0;
    if (excellence > 0) this->excellence = excellence;
    else this->excellence = 0;
    if (hasDegree) this->hasDegree = true;
    else this->hasDegree = false;
}

// Copy constructor, creates a new Employee object as a copy of another
Employee::Employee(const Employee& other) {; 
    strcpy(this->name, other.name);
    strcpy(this->id, other.id);
    this->seniority = other.seniority;
    this->excellence = other.excellence;
    this->hasDegree = other.hasDegree;
}

// Sets the name of the Employee
void Employee::SetName(char* name) {
    strncpy(this->name, name, sizeof(this->name) - 1);
    this->name[sizeof(this->name) - 1] = '\0'; 
}

// Sets the ID of the Employee
void Employee::SetId(char* id) {
    strncpy(this->id, id, sizeof(this->id) - 1);
    this->id[sizeof(this->id) - 1] = '\0';
}

// Sets the seniority of the Employee
void Employee::SetSeniority(int seniority) {
    this->seniority = seniority;
}

// Sets the excellence score of the Employee
void Employee::SetExcellence(int excellence) {
    this->excellence = excellence;
}

// Sets whether the Employee has a degree
void Employee::SetHasDegree(bool hasDegree) {
    this->hasDegree = hasDegree;
}

// Returns the name of the Employee
char* Employee::GetName() {
    return this->name;
}

// Returns the ID of the Employee
char* Employee::GetId() {
    return this->id;
}

// Returns the seniority of the Employee
int Employee::GetSeniority() {
    return this->seniority;
}

// Returns the excellence score of the Employee
int Employee::GetExcellence() {
    return this->excellence;
}

// Returns whether the Employee has a degree
bool Employee::GetHasDegree() {
    return this->hasDegree;
}

// Calculates the bonus for the Employee based on excellence
int Employee::BonusCalculation() {
    int bonus = this->excellence * 550;
    if (bonus > 3000){
        bonus = 3000;
    }
    return bonus;
}

// Calculates the salary for the Employee based on seniority, degree, and bonus
int Employee::SalaryCalculation() {
    int salary = 6000 + this->seniority * 1000 + BonusCalculation();
    if (this->hasDegree) {
        salary += 2000;
    }
    return salary;
}

// Prints the Employee's information, including bonus and salary
void Employee::PrintEmployeeInfo() {
    cout << "-----Output-----" << endl;
    cout << "Employee Name: " << this->name 
         << ", ID: " << this->id  
         << ", Seniority: " << this->seniority 
         << ", Excellence: " << this->excellence 
         << ", Degree: " << (this->hasDegree ? "Yes" : "No") << endl;
    cout << "Bonus: " << BonusCalculation() << endl;
    cout << "Salary: " << SalaryCalculation() << endl;
}