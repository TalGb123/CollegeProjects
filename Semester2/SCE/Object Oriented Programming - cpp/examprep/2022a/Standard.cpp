#include "Apartment.h"

class Standard : Apartment{
      private:
            int balcNum;
      public:
            Standard(int apartmentNum, int floor, double territorySize, int balcNum) : Apartment(apartmentNum, floor, territorySize), balcNum(balcNum) {}
            ~Standard() {}

            int getPrice(){
                  return 500000 + 12000 * balcNum + 300 * floor + 500 * getTerritorySize();
            }



};