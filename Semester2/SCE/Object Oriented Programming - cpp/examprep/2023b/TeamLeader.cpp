#include "Employee.cpp"
#include "Programmer.cpp"

class TeamLeader : public Employee {
    protected:
        int teamSize;
    public:
        TeamLeader(string name, string id, int exp, int teamSize) :
        Employee(name, id, exp), teamSize(teamSize) {}

        virtual ~TeamLeader(){}

        virtual float Salary(){
            return 12000 + 700 * teamSize + 1000 * exp;
        }

        virtual void PrintEmp() {
            Employee::PrintEmp();
            cout << "salary" << Salary() << endl;
        }
};

int main(){
    Employee* emps[2];
    string langs1[] = {"hola"};
    emps[0] = new Programmer("ab", "123", 3, 1, langs1);
    emps[1] = new TeamLeader("bc", "234", 2, 3);
    for (int i=0; i<2; i++){
        emps[i]->PrintEmp();
        delete emps[i];
    }
    return 0;
}