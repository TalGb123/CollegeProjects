#include "Animal.cpp"

class Air_Animal : public Animal {
      public:
            Air_Animal(string name, string type) : Animal(name, type){}
            virtual ~Air_Animal() {}

            virtual void Move(){
                  cout << " is flying" << endl;
                  if (type == "Eagle") cout << "i am very fast" << endl;
            }

            virtual void Eat(){
                  Animal::Eat();
                  if (type == "Eagle") cout << "small birds and insects" << endl;
            }
};