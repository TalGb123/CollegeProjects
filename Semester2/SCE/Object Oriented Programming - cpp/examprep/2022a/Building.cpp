#include "Apartment.h"
#include <iostream>
using namespace std;

class Building {
      private:
            int size;
            Apartment** data;
      public:
            Building() : size(0), data(nullptr) {}

            ~Building() {}

            ostream& operator+=(Apartment* apartment){
                  for (int i=0; i<size; i++){
                        if (!data[i]) data[i] = apartment;
                  }
            }

            void Init(){
                  int size;
                  cin >> size;
                  for (int i=0; i<size; i++){
                        int apartmentNum, floor;
                        double landSize;
                        cin >> apartmentNum;
                        cin >> floor;
                        cin >> landSize;
                        Apartment* apartment = new Apartment(apartmentNum, floor, landSize);
                        *this += apartment;
                  }
            }

            void Report(double findArea, int findPrice){
                  for (int i=0; i<size; i++){
                        if (data[i]->getPrice() <= findPrice && data[i]->getTerritorySize() >= findArea){
                              data[i]->printApp();
                        }
                  }
            }
};