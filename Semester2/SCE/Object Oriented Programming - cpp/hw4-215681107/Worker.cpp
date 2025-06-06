#include "Worker.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor: initializes Worker with given details, ensures non-negative seniority
Worker::Worker(const string firstName, const string lastName, const string id, int seniority)
    : Human(firstName, lastName, id), seniority(seniority) {
      if (seniority < 0) {
            this->seniority = 0; 
      }
}

// Copy constructor: copies another Worker, ensures non-negative seniority
Worker::Worker(const Worker& other)
    : Human(other), seniority(other.seniority) {
      if (seniority < 0) {
            seniority = 0; 
      }
}

// Virtual destructor (needed for polymorphism)
Worker::~Worker() {}

// Calculates salary based on seniority
double Worker::calculateSalary() const {
      return seniority * 1000 + 6500;
}

// Returns whether this worker is "excellent" (default: false, override in derived)
bool Worker::excellentWorker() const { return false; }

// Prints worker details, including those from Human
void Worker::printDetails() const {
      Human::printDetails();
      cout << "Seniority: " << this->seniority << "\n";
      cout << "Salary: " << calculateSalary() << "\n";
}

