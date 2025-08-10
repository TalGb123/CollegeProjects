#include "Animal.cpp"

class Sea_Animal : public Animal {
      public:
            Sea_Animal(string name, string type) : Animal(name, type){}
            virtual ~Sea_Animal() {}

            virtual void Move(){
                  cout << "is swimming" << endl;
                  if (type == "Shark") cout << "and i will never rest..." << endl;
            }

            virtual void Eat(){
                  Animal::Eat();
                  if (type == "Shark") cout << "fish and plankton" << endl;
            }
};