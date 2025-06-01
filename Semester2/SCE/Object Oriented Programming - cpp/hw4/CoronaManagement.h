#include "Patient.h"
#include "Nurse.h"
#include "Doctor.h"
#include "Worker.h"
#include "Corona.h"

class CoronaManagement {
      private:
            Patient** patients;
            int numPatients;
            Corona** departments; 
            int numdDepartments; 
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
            void AddNurse(string chosenHospitalName, int chosenHospitalIndex);
            void AddDoctor(string chosenHospitalName, int chosenHospitalIndex);
            void AddDepartment(string chosenHospitalName, int chosenHospitalIndex);
};