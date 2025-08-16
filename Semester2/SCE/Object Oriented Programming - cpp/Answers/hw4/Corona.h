#include "Nurse.h"
#include "Doctor.h"
#include "Patient.h"
#pragma once

class Corona {
      private:
            string hospital;
            Doctor** doctors;
            int numDoctors;
            Nurse** nurses;
            int numNurses;
            Patient** patients;
            int numPatients;
      public:
            Corona(const string hospital);
            Corona(const Corona& other);
            ~Corona();
            void addDoctor(Doctor* doctor);
            void addNurse(Nurse* nurse);
            void addPatient(Patient* patient);
            void printDetails() const;
            string getHospital() {return this->hospital;};
            Patient** getPatients() { return this->patients; };
            void removePatientById(const string& id);
};