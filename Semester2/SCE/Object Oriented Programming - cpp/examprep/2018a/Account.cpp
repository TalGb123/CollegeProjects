#include <string>
#include <iostream>
using namespace std;

class Account {
      protected:
            int accNum;
            string id;  
            double money;

      public:
            Account(int accNum, string id, double money) : accNum(accNum), id(id), money(money) {}

            virtual void Deposit(double dep) {
                  money += dep;
            }

            virtual void Withdraw(double wdrw) {
                  money -= wdrw;
            }

            virtual void Print() const{
                  cout << "accNum: " << accNum << endl;
                  cout << "id: " << id << endl;
                  cout << "money: " << money << endl;
            }
};