#include "Account.cpp"

class Osh : public Account{
      protected:
            double credit;
      public:
            Osh(int accNum, string id, double money, double credit) : Account(accNum, id, money), credit(credit) {}
            virtual void Withdraw(double wdrw) {
                  if (money + credit >= wdrw){
                        money -= wdrw;
                  }
                  else {
                        cout << "withdraw higher than money" << endl;
                  }
            }

            virtual void Print() const{
                  Account::Print();
                  cout << "credit: " << credit << endl;
            }
};