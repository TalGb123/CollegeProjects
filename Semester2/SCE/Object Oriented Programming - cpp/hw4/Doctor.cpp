#include "Doctor.h"
#include <iostream>
#include <cstring>
using namespace std;

Doctor::Doctor(const string firstName, const string lastName, const string id, int seniority, 
               const string department, bool professor, int positiveReviews)
    : Worker(firstName, lastName, id, seniority), department(department), 
    professor(professor), positiveReviews(positiveReviews) {}

Doctor::Doctor(const Doctor& other)
    : Worker(other), department(department), professor(other.professor), positiveReviews(other.positiveReviews) {}

Doctor::~Doctor() {}

void Doctor::printDetails() const {
	Worker::printDetails();
	cout << "Department: " << this->department << "\n";
	cout << "Professor: " << (this->professor ? "Yes" : "No") << "\n";
	cout << "Positive Reviews: " << this->positiveReviews << "\n";
	cout << "Salary: " << this->calculateSalary() << "\n";
}

double Doctor::calculateSalary() const {
	return 6500 + 200*this->getSeniority() + 50*this->positiveReviews + (this->professor ? 2000 : 0);
}

bool Doctor::excellentDoctor() const {
	return this->positiveReviews >= 10;
}



