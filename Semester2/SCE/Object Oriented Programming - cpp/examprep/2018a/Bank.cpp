#include "account.cpp"
#include "Osh.cpp"
#include "Savings.cpp"
#include <iostream>
using namespace std;

class Bank {
      private:
            int size;
            Account** data;
      
      public:
            Bank() : size(0), data(nullptr) {}

            ~Bank() {
                  if (size){
                        for (int i=0; i<size; i++){
                              delete data[i];
                        }
                        delete[] data;
                  }
            }

            Bank& operator+=(Account* acc){
                  Account** temp = new Account*[++size];
                  for (int i=0; i<size - 1; i++){
                        temp[i] = data[i];
                  }
                  temp[size-1] = acc;
                  delete[] data;
                  data = temp;
                  return *this;
            }

            Account* InitAcc() {
                  string id;
                  double money;
                  int accNum;
                  
                  int choice = 1;
                  cout << "type 1 for osh and type 2 for savings";
                  cin >> choice;
                  Account* temp = nullptr;
                  if (choice == 1) {
                        double credit = 0;
                        cout << "enter accnum id money credit: ";
                        cin >> accNum >> id >> money >> credit;
                        temp = new Osh(accNum, id, money, credit);
                        return temp;
                  }
                  if (choice == 2) {
                        cout << "enter accnum id money: ";
                        cin >> accNum >> id >> money;
                        temp = new Savings(accNum, id, money);
                        return temp;
                  }
                  
            }

            void Init(){
                  int count;
                  cout << "how many accs: ";
                  cin >> count;
                  for (int i=0; i<count; i++){
                        Account* acc = InitAcc();
                        *this += acc;
                  }
                  
            }

            void Transaction() {
                  for (int i=0; i<size; i++){
                        if (typeid(*data[i]) == typeid(Osh)) data[i]->Deposit(50);
                        data[i]->Withdraw(10);
                        data[i]->Print();
                  }
            }
};