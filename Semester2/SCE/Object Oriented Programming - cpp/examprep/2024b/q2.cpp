#include "Sea_Animal.cpp"
#include "Air_Animal.cpp"
#include "Land_Animal.cpp"

int main(){
      Animal** arr = new Animal*[3];
      arr[0] = new Land_Animal("ll", "Lion");
      arr[1] = new Sea_Animal("ss", "Shark");
      arr[2] = new Air_Animal("aa", "Eagle");

      arr[0]->Eat();
      arr[0]->Move();
      arr[1]->Eat();
      arr[1]->Move();
      arr[2]->Eat();
      arr[2]->Move();

      for (int i=0; i<3; i++){
            delete arr[i];
      }
      delete[] arr;

}