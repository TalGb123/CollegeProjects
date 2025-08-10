#include "account.cpp"

class Savings : public Account {
      public:
            Savings(int accNum, string id, double money) : Account(accNum, id, money) {}
            virtual void Withdraw(double wdrw){
                  if (money >= wdrw) {
                        money -= wdrw;
                  }
                  else {
                        cout << "withdraw higher than money" << endl;
                  }
            }
};