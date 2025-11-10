#include "Doctor.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor: initializes Doctor with given details
Doctor::Doctor(const string firstName, const string lastName, const string id, int seniority, 
               const string department, bool professor, int positiveReviews)
    : Worker(firstName, lastName, id, seniority), department(department), 
    professor(professor), positiveReviews(positiveReviews) {}

// Copy constructor: creates a new Doctor as a copy of another
Doctor::Doctor(const Doctor& other)
    : Worker(other), department(department), professor(other.professor), positiveReviews(other.positiveReviews) {}

// Destructor: cleans up Doctor (nothing special needed here)
Doctor::~Doctor() {}

// Prints all details of the doctor, including inherited Worker details
void Doctor::printDetails() const {
	Worker::printDetails();
	cout << "Department: " << this->department << "\n";
	cout << "Professor: " << (this->professor ? "Yes" : "No") << "\n";
	cout << "Positive Reviews: " << this->positiveReviews << "\n";
	cout << "Salary: " << this->calculateSalary() << "\n";
}

// Calculates doctor's salary based on seniority, reviews, and professor status
double Doctor::calculateSalary() const {
	return 6500 + 200*this->getSeniority() + 50*this->positiveReviews + (this->professor ? 2000 : 0);
}

// Returns true if the doctor is "excellent" (10 or more positive reviews)
bool Doctor::excellentWorker() const{
	return this->positiveReviews >= 10;
}



