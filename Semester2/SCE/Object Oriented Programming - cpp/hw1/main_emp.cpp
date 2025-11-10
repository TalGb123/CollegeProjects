// Creator: Tal Gubenko
// ID: 215681107
// Assignment: 1

#include "Employee.cpp"

int main(){
    string name;
    string id;
    int seniority;
    int excellence;
    char hasDegreeChar;
    bool hasDegree = false;

     // Loop to handle input and operations for two employees
    for (int i=0; i < 2; i++){
        cout << "-----Input-----" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Years of Seniority: ";
        cin >> seniority;
        cout << "Excellence: ";
        cin >> excellence;
        cout << "Degree (Y/N): ";
        cin >> hasDegreeChar;
        if (hasDegreeChar == 'Y' || hasDegreeChar == 'y') hasDegree = true;

        // Create an Employee object and print its information
        Employee emp(name.c_str(), id.c_str(), seniority, excellence, hasDegree);
        emp.PrintEmployeeInfo();

        // Update seniority and print updated information
        cout << "-----Input-----" << endl;
        cout << "Update Years of Seniority: ";
        cin >> seniority;
        emp.SetSeniority(seniority);
        emp.PrintEmployeeInfo();

        // Update excellence and print updated information
        cout << "-----Input-----" << endl;
        cout << "Update Excellence: ";
        cin >> excellence;
        emp.SetExcellence(excellence);
        emp.PrintEmployeeInfo();

        // Store the employee object for later use (if needed)
        if (i == 0) Employee emp1 = emp;
        else if (i == 1) Employee emp2 = emp;
    }
    return 0;
}