#include "Apartment.h"
#include <iostream>
using namespace std;

Apartment::Apartment(int apartmentNum, int floor, double territorySize) : apartmentNum(apartmentNum), floor(floor), territorySize(territorySize) {}

Apartment::Apartment() : apartmentNum(0), floor(0), territorySize(0) {}

Apartment::~Apartment() {}

int Apartment::getPrice() {}

void Apartment::printApp(){
      cout << "apartment number: " << apartmentNum << endl;
      cout << "apartment floor: " << floor << endl;
      cout << "apartment number: " << territorySize << endl;
}
