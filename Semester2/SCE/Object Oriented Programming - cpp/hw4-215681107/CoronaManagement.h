#include "Patient.h"
#include "Nurse.h"
#include "Doctor.h"
#include "Worker.h"
#include "Corona.h"
#pragma once

class CoronaManagement {
      private:
            Patient** patients;
            int numPatients;
            Corona** departments; 
            int numDepartments; 
            Worker** workers;
            int numWorkers;
      public:
            CoronaManagement();
            CoronaManagement(const CoronaManagement& other);
            ~CoronaManagement();
            void addPatient(Patient* patient);
            void addHuman(Human* human);
            void addWorker(Worker* worker);
            void printDetails() const;
            int getNumPatients() const;
            int getNumHumans() const;
            int getNumWorkers() const;
            void Menu();
            void printOptions() const;
            void AddNurse(string HospitalName, int HospitalIndex);
            void AddDoctor(string HospitalName, int HospitalIndex);
            void AddDepartment(string HospitalName, int HospitalIndex);
            void PrintDepartmentDetails(string HospitalName, int HospitalIndex) const;
            void PrintAllDoctors() const;
            void PrintWorkerSalary() const;
            void AddPatient(string hospitalName, int hospitalIndex);
            void AddCoronaTestToPatientById();
            void Releasing();
            void PrintExcellenceWorker() const;
            void PrintNurseWithSmallestSalary() const;
            void PrintAllDepartments() const;
};