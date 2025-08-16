#include "Corona.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor: initializes Corona department with hospital name and empty staff/patient arrays
Corona::Corona(const string hospital) : hospital(hospital), doctors(new Doctor*[3]), numDoctors(0), 
      nurses(new Nurse*[3]), numNurses(0), patients(new Patient*[10]), numPatients(0) {}

// Copy constructor: (shallow copy, be careful with ownership if used)
Corona::Corona(const Corona& other) : hospital(other.hospital), doctors(other.doctors), numDoctors(0), 
      nurses(other.nurses), numNurses(0), patients(other.patients), numPatients(0) {}

// Destructor: deletes all doctors, nurses, and patients, then their arrays
Corona::~Corona() {
      for (int i = 0; i < numDoctors; ++i) {
            delete doctors[i];
      }
      delete[] doctors;
      for (int i = 0; i < numNurses; ++i) {
            delete nurses[i];
      }
      delete[] nurses;
      for (int i = 0; i < numPatients; ++i) {
            delete patients[i];
      }
      delete[] patients;
}

// Adds a doctor to the department, resizing the array as needed
void Corona::addDoctor(Doctor* doctor) {
      Doctor** newDoctors = new Doctor*[numDoctors + 1];
      for (int i = 0; i < numDoctors; ++i) {
            newDoctors[i] = doctors[i];
      }
      newDoctors[numDoctors] = doctor;
      delete[] doctors;
      doctors = newDoctors;
      numDoctors++;
}

// Adds a nurse to the department, resizing the array as needed
void Corona::addNurse(Nurse* nurse) {
      Nurse** newNurses = new Nurse*[numNurses + 1];
      for (int i = 0; i < numNurses; ++i) {
            newNurses[i] = nurses[i];
      }
      newNurses[numNurses] = nurse;
      delete[] nurses;
      nurses = newNurses;
      numNurses++;
}

// Adds a patient to the department, only if there is at least 1 doctor and 2 nurses
void Corona::addPatient(Patient* patient) {
      if (this->numDoctors < 1 || this->numNurses < 2) {
            cout << "Cannot add patient: No doctors or nurses available.\n";
            return;
      }
      Patient** newPatients = new Patient*[numPatients + 1];
      for (int i = 0; i < numPatients; ++i) {
            newPatients[i] = patients[i];
      }
      newPatients[numPatients] = patient;
      delete[] patients;
      patients = newPatients;
      numPatients++;
}

// Prints all details of the department: hospital name, doctors, nurses, and patient count
void Corona::printDetails() const {
      cout << "Hospital: " << hospital << "\n";
      cout << "Doctors:\n";
      for (int i = 0; i < numDoctors; ++i) {
            doctors[i]->printDetails();
            cout << "------------------\n";
      }
      cout << "Nurses:\n";
      for (int i = 0; i < numNurses; ++i) {
            nurses[i]->printDetails();
            cout << "------------------\n";
      }
      cout << "Patients amount: " << numPatients << "\n";

}

// Removes a patient by ID from the department's patient array (does not delete the object)
void Corona::removePatientById(const string& id) {
      int index = -1;
      for (int i = 0; i < numPatients; ++i) {
            if (patients[i]->getId() == id) {
                  index = i;
                  break;
            }
      }
      if (index == -1) {
            cout << "[FAILED] Patient with ID " << id << " not found in department." << endl;
            return;
      }
      // Shift all patients after the removed one left by one position
      for (int i = index; i < numPatients - 1; ++i) {
            patients[i] = patients[i + 1];
      }
      numPatients--;
}