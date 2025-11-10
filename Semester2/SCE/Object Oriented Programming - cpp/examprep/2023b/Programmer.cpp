#include "Employee.cpp"

class Programmer : public Employee {
    protected:
        string* arr;
        int size;
    public:
        Programmer(string name, string id, int exp, int size, string* arr) :
        Employee(name, id, exp), size(size) {
            this->arr = new string[size];
            for (int i = 0; i < size; ++i) {
                this->arr[i] = arr[i];
            }
        }

        virtual ~Programmer() {
            delete[] arr;
        }

        virtual float Salary() {
            return 8000 + 500 * exp + 1000 * size;
        }

        virtual void PrintEmp(){
            Employee::PrintEmp();
            cout << "salary: " << Salary();
        }
};