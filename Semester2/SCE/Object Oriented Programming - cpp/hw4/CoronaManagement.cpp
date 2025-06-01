#include "CoronaManagement.h"
#include <iostream>
#include <string>
using namespace std;

enum Actions{
      ADD_NURSE = 1,
      ADD_DOCTOR,
      ADD_DEPARTMENT,
      PRINT_DEPARTMENT_DETAILS,
      PRINT_DOCTORS_DETAILS,
      PRINT_SALARY_BY_ID,
      ADD_PATIENT,
      ADD_CORONA_TEST_TO_PATIENT_ID,
      RELEASING_PATIENTS,
      PRINT_EXCELLENCE_WORKER,
      PRINT_NURSE_DETAILS_WITH_SMALLEST_SALARY,
      EXIT
};

CoronaManagement::CoronaManagement() {
      Doctor d1  = Doctor("John", "Doe", "123456789", 10, "Soroka", true, 5);
      Nurse n1 = Nurse("Jane", "Smith", "987654321", 5, "Soroka", 4);
      Nurse n2 = Nurse("Alice", "Johnson", "456789123", 3, "Soroka", 2);
      this->workers = new Worker*[6];
      this->workers[0] = new Doctor(d1);
      this->workers[1] = new Nurse(n1);
      this->workers[2] = new Nurse(n2);
      this->numWorkers = 3;
      this->departments = new Corona*[5];
      this->departments[0] = new Corona("Soroka");
      this->numdDepartments = 1;
      this->departments[0]->addDoctor(new Doctor(d1));
      this->departments[0]->addNurse(new Nurse(n1));
      this->departments[0]->addNurse(new Nurse(n2));
      this->patients = new Patient*[10];
      this->numPatients = 0;
}     

// CoronaManagement::CoronaManagement(const CoronaManagement& other) {
//       this->numPatients = other.numPatients;
//       this->numdDepartments = other.numdDepartments;
//       this->numWorkers = other.numWorkers;

//       this->patients = new Patient*[this->numPatients];
//       for (int i = 0; i < this->numPatients; ++i) {
//             this->patients[i] = new Patient(*other.patients[i]);
//       }

//       this->departments = new Corona*[this->numdDepartments];
//       for (int i = 0; i < this->numdDepartments; ++i) {
//             this->departments[i] = new Corona(*other.departments[i]);
//       }

//       this->workers = new Worker*[this->numWorkers];
//       for (int i = 0; i < this->numWorkers; ++i) {
//             this->workers[i] = other.workers[i]->clone(); // Assuming clone() is implemented in Worker
//       }
// }

CoronaManagement::~CoronaManagement() {
      for (int i = 0; i < numWorkers; ++i) {
            delete workers[i];
      }
      delete[] workers;

      for (int i = 0; i < numdDepartments; ++i) {
            delete departments[i];
      }
      delete[] departments;

      for (int i = 0; i < numPatients; ++i) {
            delete patients[i];
      }
      delete[] patients;
}

void CoronaManagement::Menu()  {
      int option;
      bool run = true;
      while (run) {
            printOptions();
            cin >> option;
            string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka"};
            int size = sizeof(HospitalNames) / sizeof(HospitalNames[0]);
            for (int i=1; i<=size; i++){
                  cout << i << ". " << HospitalNames[i-1] << endl;
            }
            int chosenHospitalIndex;
            cout << "Enter an hospital number from the list above: " << endl;
            cin >> chosenHospitalIndex;
            string chosenHospitalName = HospitalNames[chosenHospitalIndex-1];
            switch (option) {
                  case ADD_NURSE:
                        AddNurse(chosenHospitalName, chosenHospitalIndex);
                        break;
                  case ADD_DOCTOR:
                        AddDoctor(chosenHospitalName, chosenHospitalIndex);
                        break;
                  case ADD_DEPARTMENT:
                        AddDepartment(chosenHospitalName, chosenHospitalIndex);
                        break;
                  case PRINT_DEPARTMENT_DETAILS:
                        PrintDepartmentDetails(chosenHospitalName, chosenHospitalIndex);
                        break;
                  case PRINT_DOCTORS_DETAILS:
                        PrintDoctorsDetails(chosenHospital);
                        break;
                  case PRINT_SALARY_BY_ID:
                        PrintSalary(chosenHospital);
                        break;
                  case ADD_PATIENT:
                        AddPatient(chosenHospital);
                        break;
                  case ADD_CORONA_TEST_TO_PATIENT_ID:
                        AddCoronaTestToPatientById(chosenHospital);
                        break;
                  case RELEASING_PATIENTS:
                        Releasing(chosenHospital);
                        break;
                  case PRINT_EXCELLENCE_WORKER:
                        PrintExcellenceWorker(chosenHospital);
                        break;
                  case PRINT_NURSE_DETAILS_WITH_SMALLEST_SALARY:
                        PrintNurseWithSmallestSalary(chosenHospital);
                        break;
                  case EXIT:
                        run = false;
                        break;
            }
      }
}

void CoronaManagement::printOptions() const {
      cout << "Menu: " << endl;
      cout << "1. ADD NURSE" << endl;
      cout << "2. ADD DOCTOR" << endl;
      cout << "3. ADD DEPARTMENT" << endl;
      cout << "4. PRINT DEPARTMENT DETAILS" << endl;
      cout << "5. PRINT DOCTORS DETAILS" << endl;
      cout << "6. PRINT SALARY BY ID" << endl;
      cout << "7. ADD PATIENT" << endl;
      cout << "8. ADD CORONA TEST TO PATIENT ID" << endl;
      cout << "9. RELEASING PATIENTS" << endl;
      cout << "10. PRINT EXCELLENCE WORKER" << endl;
      cout << "11. PRINT NURSE DETAILS WITH SMALLEST SALARY" << endl;
      cout << "12. EXIT" << endl;
}

void CoronaManagement::AddNurse(string hospitalName, int hospitalIndex) {
      string firstName, lastName, id;
      int seniority, courses;
      cout << "Enter first name: ";
      cin >> firstName;
      cout << "Enter last name: ";
      cin >> lastName;
      cout << "Enter ID: ";
      cin >> id;
      cout << "Enter seniority: ";
      cin >> seniority;
      cout << "Enter courses: ";
      cin >> courses;
      Nurse* newNurse = new Nurse(firstName, lastName, id, seniority, hospitalName, courses);
      addWorker(newNurse);
      departments[hospitalIndex-1]->addNurse(newNurse);
      cout << "SUCCESS Nurse added successfully!" << endl;
}

void CoronaManagement::AddDoctor(string hospitalName, int hospitalIndex) {
      string firstName, lastName, id;
      int seniority, positiveReviews;
      bool professor;
      cout << "Enter first name: ";
      cin >> firstName;
      cout << "Enter last name: ";
      cin >> lastName;
      cout << "Enter ID: ";
      cin >> id;
      cout << "Enter seniority: ";
      cin >> seniority;
      cout << "Is a professor (y/n): ";
      cin >> professor;
      cout << "Enter positive reviews: ";
      cin >> positiveReviews;
      Doctor* newDoctor = new Doctor(firstName, lastName, id, seniority, hospitalName, professor, positiveReviews);
      addWorker(newDoctor);
      departments[hospitalIndex-1]->addDoctor(newDoctor);
      cout << "SUCCESS Doctor added successfully!" << endl;
}

void CoronaManagement::AddDepartment(string hospitalName, int hospitalIndex) {
      for (int i=0; i<numdDepartments; i++){
            if (departments[i]->getHospital() == hospitalName) {
                  cout << "FAILED hospital already has a corona department.";
                  return;
            }
      }
      Corona* newDepartment = new Corona(hospitalName);
      departments[hospitalIndex-1] = newDepartment;
      AddDoctor(hospitalName, hospitalIndex);
      for (int i=0; i<2; i++){
            AddNurse(hospitalName, hospitalIndex);
      }
      cout << "SUCCESS Department added successfully!" << endl;
}



