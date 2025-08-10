#include "Animal.cpp"

class Land_Animal : public Animal {
      public:
            Land_Animal(string name, string type) : Animal(name, type){}
            virtual ~Land_Animal() {}

            virtual void Move(){
                  cout << "is running" << endl;
                  if (type == "Lion") cout << "the lion is walking slowly" << endl;
            }

            virtual void Eat(){
                  Animal::Eat();
                  if (type == "Lion") cout << "large mammals" << endl;
            }
};