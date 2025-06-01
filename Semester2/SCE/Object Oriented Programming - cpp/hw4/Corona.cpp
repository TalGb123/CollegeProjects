#include "Corona.h"
#include <iostream>
#include <cstring>
using namespace std;

Corona::Corona(const string hospital) : hospital(hospital), doctors(new Doctor*[3]), numDoctors(0), 
      nurses(new Nurse*[3]), numNurses(0), patients(new Patient*[10]), numPatients(0) {}

Corona::Corona(const Corona& other) : hospital(other.hospital), doctors(other.doctors), numDoctors(0), 
      nurses(other.nurses), numNurses(0), patients(other.patients), numPatients(0) {}

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
      cout << "Patients:\n";
      for (int i = 0; i < numPatients; ++i) {
            patients[i]->printDetails();
            cout << "------------------\n";
      }
}
