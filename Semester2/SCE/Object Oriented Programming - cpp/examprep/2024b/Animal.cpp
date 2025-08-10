#include <string>
#include <iostream>
using namespace std;

class Animal {
      protected:
            const string name;
            const string type;
      public:
            Animal(string name, string type) : name(name), type(type){}
            virtual ~Animal() {}
            
            virtual void Eat(){
                  cout << name << " the " << type << " is eating: ";
            }

            virtual void Move() {}
};