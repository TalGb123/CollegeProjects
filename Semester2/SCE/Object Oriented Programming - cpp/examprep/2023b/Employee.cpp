#include <string>
using namespace std;
#include <iostream>

class Employee {
    protected:
        string name;
        string id;
        int exp;
    public:
        Employee(string name, string id, int exp) : name(name), id(id), exp(exp) {}

        virtual ~Employee() {}

        virtual float Salary() { return 0; }

        virtual void PrintEmp() {
            cout << "name: " << name << endl;
            cout << "id: " << id << endl;
            cout << "exp: " << exp << endl;
        }
};