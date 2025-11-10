#include "Patient.h"
#include <iostream>
using namespace std;

// Constructor: initializes Patient with given details
Patient::Patient(const string firstName, const string lastName, const string id, const string department, int testsDone, int negTests)
                    : Human(firstName, lastName, id), department(department), testsDone(testsDone), negTests(negTests) {}

// Copy constructor: creates a new Patient as a copy of another
Patient::Patient(const Patient& other) : Human(other), department(other.department), testsDone(other.testsDone), negTests(other.negTests) {}

// Destructor: cleans up Patient (nothing special needed here)
Patient::~Patient() {}

// Prints all details of the patient
void Patient::printDetails() const {
    cout << "Patient Details:" << endl;
    cout << "Name: " << getFirstName() << " " << getLastName() << endl;
    cout << "ID: " << getId() << endl;
    cout << "Department: " << department << endl;
    cout << "Tests Done: " << testsDone << endl;
    cout << "Negative Tests: " << negTests << endl;
}