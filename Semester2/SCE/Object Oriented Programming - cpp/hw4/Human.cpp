#include "Human.h"
#include <iostream>
#include <cstring>

Human::Human(const string firstName, const string lastName, const string id) 
      : firstName(firstName), lastName(lastName), id(id) {}

Human::Human(const Human& other) 
      : firstName(other.firstName), lastName(other.lastName), id(other.id) {}

Human::~Human() {}

void Human::printDetails() const {
      cout << "First Name: " << firstName << "\n";
      cout << "Last Name: " << lastName << "\n";
      cout << "ID: " << id << "\n";
}