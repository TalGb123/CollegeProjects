#include "Nurse.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor: initializes Nurse with given details
Nurse::Nurse(const string firstName, const string lastName, const string id, int seniority,
             const string department, const int courses)
    : Worker(firstName, lastName, id, seniority), department(department), courses(courses) {}

// Copy constructor: creates a new Nurse as a copy of another
Nurse::Nurse(const Nurse& other)
    : Worker(other), department(other.department), courses(other.courses) {}

// Destructor: cleans up Nurse (nothing special needed here)
Nurse::~Nurse() {  }

// Returns true if the nurse is "excellent" (number of courses >= seniority)
bool Nurse::excellentWorker() const {
      return this->courses >= this->getSeniority();
}

// Calculates nurse's salary based on a base and number of courses
double Nurse::calculateSalary() const {
      return 6500 + this->courses * 50;
}

// Prints all details of the nurse, including inherited Worker details
void Nurse::printDetails() const {
      Worker::printDetails();
      cout << "Department: " << this->department << "\n";
      cout << "Courses: " << this->courses << "\n";
      cout << "Salary: " << this->calculateSalary() << "\n";
}