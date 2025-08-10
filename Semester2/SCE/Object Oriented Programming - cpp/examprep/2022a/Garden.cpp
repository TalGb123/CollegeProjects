#include "Apartment.h"
#include <iostream>
using namespace std;

class Garden : Apartment {
      private:
            int gardenSize;
            bool pool;
      public:
            Garden(int apartmentNum, int floor, double territorySize, int balcNum) : 
            Apartment(apartmentNum, floor, territorySize), gardenSize(gardenSize), pool(pool) {}

            ~Garden() {}

            int getPrice(){
                  return 600000 + getTerritorySize() * 600 + pool ? 100000 : 0;
            }

            void printApp(){
                  Apartment::printApp();
                  cout << getPrice() << endl;
            }
};