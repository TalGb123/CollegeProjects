#include "Nurse.h"
#include <iostream>
#include <cstring>
using namespace std;

Nurse::Nurse(const string firstName, const string lastName, const string id, int seniority,
             const string department, const int courses)
    : Worker(firstName, lastName, id, seniority), department(department), courses(courses) {}

Nurse::Nurse(const Nurse& other)
    : Worker(other), department(other.department), courses(other.courses) {}

// Nurse& Nurse::operator=(const Nurse& other) {
//       if (this != &other) {
//             Worker::operator=(other);
//             delete[] this->department;
//             this->department = new char[strlen(other.department) + 1];
//             strcpy(this->department, other.department);
//             this->courses = other.courses;
//       }
//       return *this;
// }

Nurse::~Nurse() {  }

bool Nurse::excellentNurse() const {
      return this->courses >= this->getSeniority();
}

double Nurse::calculateSalary() const {
      return 6500 + this->courses * 50;
}

void Nurse::printDetails() const {
      Worker::printDetails();
      cout << "Department: " << this->department << "\n";
      cout << "Courses: " << this->courses << "\n";
      cout << "Salary: " << this->calculateSalary() << "\n";
}