#include "CoronaManagement.h"
#include <iostream>
#include <string>
using namespace std;

// Enum for menu actions
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
      PRINT_ALL_DEPARTMENTS,
      EXIT
};

// Constructor: initializes arrays and counters
CoronaManagement::CoronaManagement() {
      this->workers = new Worker*[6];
      for (int i = 0; i < 6; ++i) {
            this->workers[i] = nullptr;
      }
      this->numWorkers = 0;
      this->departments = new Corona*[5];
      for (int i = 0; i < 5; ++i) {
            this->departments[i] = nullptr;
      }
      this->numDepartments = 0;
      this->patients = new Patient*[10];
      this->numPatients = 0;
}     

// Destructor: cleans up all dynamic allocations
CoronaManagement::~CoronaManagement() {
      for (int i = 0; i < numWorkers; ++i) {
            delete workers[i];
      }
      delete[] workers;

      for (int i = 0; i < numDepartments; ++i) {
            delete departments[i];
      }
      delete[] departments;

      for (int i = 0; i < numPatients; ++i) {
            delete patients[i];
      }
      delete[] patients;
}

// Main menu loop: handles user input and dispatches to actions
void CoronaManagement::Menu()  {
      int option;
      bool run = true;
      while (run) {
            printOptions();
            cout << "Enter your option: ";
            cin >> option;
            while (option < 1 || option > 13) {
                  cout << "[FAILED] Invalid input. Please enter a number between 1 and 12: ";
                  cin >> option;
            }
            int chosenHospitalIndex;
            string chosenHospitalName;
            // For actions that require a hospital, prompt for hospital selection
            if (option < 5 || option == 7) {
                  string HospitalNames[] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka"};
                  int size = sizeof(HospitalNames) / sizeof(HospitalNames[0]);
                  for (int i=1; i<=size; i++){
                        cout << i << ". " << HospitalNames[i-1] << endl;
                  }
                  cout << "Enter an hospital number from the list above: ";
                  cin >> chosenHospitalIndex;
                  while (chosenHospitalIndex < 1 || chosenHospitalIndex > size) {
                        cout << "[FAILED] Invalid hospital number. Please try again: " << endl;
                        cin >> chosenHospitalIndex;
                  }
                  chosenHospitalName = HospitalNames[chosenHospitalIndex-1];
            }
            // Dispatch to the selected action
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
                        PrintAllDoctors();
                        break;
                  case PRINT_SALARY_BY_ID:
                        PrintWorkerSalary();
                        break;
                  case ADD_PATIENT:
                        AddPatient(chosenHospitalName, chosenHospitalIndex);
                        break;
                  case ADD_CORONA_TEST_TO_PATIENT_ID:
                        AddCoronaTestToPatientById();
                        break;
                  case RELEASING_PATIENTS:
                        Releasing();
                        break;
                  case PRINT_EXCELLENCE_WORKER:
                        PrintExcellenceWorker();
                        break;
                  case PRINT_NURSE_DETAILS_WITH_SMALLEST_SALARY:
                        PrintNurseWithSmallestSalary();
                        break;
                  case PRINT_ALL_DEPARTMENTS:
                        PrintAllDepartments();
                        break;
                  case EXIT:
                        run = false;
                        break;
            }
      }
}

// Prints the menu options
void CoronaManagement::printOptions() const {
      cout << "\nMenu: " << endl;
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
      cout << "12. PRINT ALL DEPARTMENTS" << endl;
      cout << "13. EXIT" << endl;
}

// Adds a worker to the workers array
void CoronaManagement::addWorker(Worker* worker) {
      if (numWorkers >= 6) {
            cout << "[FAILED] Cannot add more workers, maximum limit reached." << endl;
            return;
      }
      workers[numWorkers++] = worker;
      cout << "[SUCCESS] Worker added successfully!" << endl;
}

// Adds a nurse to a department and to the workers array
void CoronaManagement::AddNurse(string hospitalName, int hospitalIndex) {
      if (!departments[hospitalIndex-1]) {
            cout << "[FAILED] No department exists for this hospital. Please add the department first." << endl;
            return;
      }
      if (numWorkers >= 6) {
            cout << "[FAILED] Cannot add more workers, maximum limit reached." << endl;
            return;
      }
      string firstName, lastName, id;
      int seniority, courses;
      cout << "Adding Nurse to " << hospitalName << " Hospital:" << endl;
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
      cout << "[SUCCESS] Nurse added successfully!" << endl;
}

// Adds a doctor to a department and to the workers array
void CoronaManagement::AddDoctor(string hospitalName, int hospitalIndex) {
      if (!departments[hospitalIndex-1]) {
            cout << "[FAILED] No department exists for this hospital. Please add the department first." << endl;
            return;
      }
      if (numWorkers >= 6) {
            cout << "[FAILED] Cannot add more workers, maximum limit reached." << endl;
            return;
      }
      cout << "Adding Doctor to " << hospitalName << " Hospital:" << endl;
      string firstName, lastName, id;
      int seniority, positiveReviews;
      string professor;
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
      bool boolProfessor;
      if (professor == "y" || professor == "Y" || professor == "yes" || professor == "Yes") {
            boolProfessor = true;
      } 
      else if (professor == "n" || professor == "N" || professor == "no" || professor == "No") {
            boolProfessor = false;
      } 
      else {
            while (professor != "y" && professor != "Y" && professor != "yes" && professor != "Yes" &&
                   professor != "n" && professor != "N" && professor != "no" && professor != "No") {
                  cout << "[FAILED] Invalid input for professor status. Please enter 'y' or 'n': ";
                  cin >> professor;
            }
      }
      cout << "Enter positive reviews: ";
      cin >> positiveReviews;
      Doctor* newDoctor = new Doctor(firstName, lastName, id, seniority, hospitalName, boolProfessor, positiveReviews);
      addWorker(newDoctor);
      departments[hospitalIndex-1]->addDoctor(newDoctor);
      cout << "[SUCCESS] Doctor added successfully!" << endl;
}

// Adds a new department and automatically adds a doctor and two nurses to it
void CoronaManagement::AddDepartment(string hospitalName, int hospitalIndex) {
      // Prevent duplicate departments for the same hospital
      for (int i=0; i<numDepartments; i++){
            if (departments[i]->getHospital() == hospitalName) {
                  cout << "[FAILED] hospital already has a corona department.";
                  return;
            }
      }
      Corona* newDepartment = new Corona(hospitalName);
      departments[hospitalIndex-1] = newDepartment;
      numDepartments++;
      AddDoctor(hospitalName, hospitalIndex);
      for (int i=0; i<2; i++){
            AddNurse(hospitalName, hospitalIndex);
      }
      cout << "[SUCCESS] Department added successfully!" << endl;
}

// Prints details for a specific department
void CoronaManagement::PrintDepartmentDetails(string hospitalName, int hospitalIndex) const {
      if (hospitalIndex < 1 || hospitalIndex > numDepartments) {
            cout << "[FAILED] Invalid hospital index." << endl;
            return;
      }
      Corona* department = departments[hospitalIndex - 1];
      cout << "Department Details for " << hospitalName << ":" << endl;
      department->printDetails();
      cout << "[SUCCESS] Department details printed successfully!" << endl;
}

// Prints details for all doctors
void CoronaManagement::PrintAllDoctors() const {
      cout << "All Doctors Details:\n" << endl;
      if (numWorkers == 0) {
            cout << "[FAILED] No workers available." << endl;
            return;
      }
      for (int i = 0; i < numWorkers; ++i) {
            if (dynamic_cast<Doctor*>(workers[i])) {
                  workers[i]->printDetails();
                  cout << "------------------------" << endl;
            }
      }
      cout << "[SUCCESS] All doctors printed successfully!" << endl;
}

// Prints salary details for a worker by ID
void CoronaManagement::PrintWorkerSalary() const {
      cout << "Enter worker id: ";
      string id;
      cin >> id;
      for (int i = 0; i < numWorkers; ++i) {
            if (workers[i]->getId() == id) {
                  cout << "[SUCCESS] Worker found!" << endl;
                  cout << "Worker Name: " << workers[i]->getFirstName() << " " << workers[i]->getLastName() << endl;
                  cout << "Worker ID: " << workers[i]->getId() << endl;
                  cout << "Worker Salary: " << workers[i]->calculateSalary() << endl;
                  return;
            }
      }
      cout << "[FAILED] Worker with ID " << id << " not found." << endl;
}

// Adds a patient to a department and to the patients array
void CoronaManagement::AddPatient(string hospitalName, int hospitalIndex) {
      if (numPatients >= 10) {
            cout << "[FAILED] Cannot add more patients, maximum limit reached." << endl;
            return;
      }
      if (!departments[hospitalIndex-1]) {
            cout << "[FAILED] No department exists for this hospital. Please add the department first." << endl;
            return;
      }
      cout << "Adding Patient to " << hospitalName << " Hospital:" << endl;
      string firstName, lastName, id;
      int testsDone, negTests;
      cout << "Enter first name: ";
      cin >> firstName;
      cout << "Enter last name: ";
      cin >> lastName;
      cout << "Enter ID: ";
      cin >> id;
      cout << "Enter number of tests done: ";
      cin >> testsDone;
      cout << "Enter number of negative tests: ";
      cin >> negTests;
      Patient* newPatient = new Patient(firstName, lastName, id, hospitalName, testsDone, negTests);
      departments[hospitalIndex - 1]->addPatient(newPatient);
      patients[numPatients++] = newPatient;
      cout << "[SUCCESS] Patient added successfully!" << endl;
}

// Adds a corona test to a patient by ID
void CoronaManagement::AddCoronaTestToPatientById() {
      string id;
      cout << "Enter patient ID: ";
      cin >> id;
      for (int i = 0; i < numPatients; ++i) {
            if (patients[i]->getId() == id) {
                  int testsDone = patients[i]->getTestsDone();
                  patients[i]->setTestsDone(testsDone + 1);
                  cout << "[SUCCESS] Corona test added to patient with ID: " << id << endl;
                  return;
            }
      }
      cout << "[FAILED] Patient with ID " << id << " not found." << endl;
}

// Releases patients with at least 2 negative tests from both the main and department lists
void CoronaManagement::Releasing() {
      int newNumPatients = 0;
      Patient** newPatients = new Patient*[numPatients];

      for (int i = 0; i < numPatients; ++i) {
            if (patients[i]->getNegTests() < 2) {
                  newPatients[newNumPatients++] = patients[i];
            } 
            else {
                  cout << "Patient with ID: " << patients[i]->getId() << " has been released." << endl;
                  bool removed = false;
                  // Remove patient from their department
                  for (int j = 0; j < numDepartments; ++j) {
                        if (departments[j] && departments[j]->getHospital() == patients[i]->getHospital()) {
                              cout << "Removing patient from department: " << departments[j]->getHospital() << endl;
                              departments[j]->removePatientById(patients[i]->getId());
                              removed = true;
                              break;
                        }
                  }
                  if (!removed) {
                        cout << "[WARNING] Patient not found in any department: " << patients[i]->getId() << endl;
                  }
                  delete patients[i];
            }
      }
      delete[] patients;
      patients = newPatients;
      numPatients = newNumPatients;
      cout << "[SUCCESS] Patients released successfully!" << endl;
}

// Prints all workers considered "excellent" (by their own logic)
void CoronaManagement::PrintExcellenceWorker() const {
      cout << "Excellence Workers:\n" << endl;
      if (numWorkers == 0) {
            cout << "[FAILED] No workers available." << endl;
            return;
      }
      for (int i = 0; i < numWorkers; ++i) {
            if (workers[i]->excellentWorker()) {
                  if (dynamic_cast<Doctor*>(workers[i])) {
                        cout << "Job: Doctor" << endl;
                  } 
                  else if (dynamic_cast<Nurse*>(workers[i])) {
                        cout << "Job: Nurse" << endl;
                  } 
                  workers[i]->printDetails();
                  cout << "------------------------" << endl;
            }
      }
      cout << "[SUCCESS] Excellence workers printed successfully!" << endl;
}

// Finds and prints the nurse with the smallest salary
void CoronaManagement::PrintNurseWithSmallestSalary() const {
      if (numWorkers == 0) {
            cout << "[FAILED] No workers available." << endl;
            return;
      }
      double lowestSalary = -1;
      Nurse* nurseWithLowestSalary = nullptr;
      for (int i=0; i<numWorkers; i++){
            if (workers[i] == nullptr) continue;
            if (Nurse* nurse = dynamic_cast<Nurse*>(workers[i])) {
                  cout << "Checking Nurse: " << nurse->getFirstName() << " " << nurse->getLastName() << endl;
                  if (nurse->calculateSalary() < lowestSalary || lowestSalary == -1) {
                        lowestSalary = nurse->calculateSalary();
                        cout << "New lowest salary found: " << lowestSalary << endl;
                        nurseWithLowestSalary = nurse;
                  }
            }
      }
      if (nurseWithLowestSalary) {
            cout << "[SUCCESS] Nurse with the smallest salary:\n";
            nurseWithLowestSalary->printDetails();
      } 
      else {
            cout << "[FAILED] No nurses available." << endl;
      }
}

// Prints details for all departments
void CoronaManagement::PrintAllDepartments() const {
      cout << "All Departments Details:\n" << endl;
      if (numDepartments == 0) {
            cout << "[FAILED] No departments available." << endl;
            return;
      }
      for (int i = 0; i < numDepartments; ++i) {
            if (departments[i]) {
                  departments[i]->printDetails();
                  cout << "------------------------" << endl;
            }
      }
      cout << "[SUCCESS] All departments printed successfully!" << endl;
}

