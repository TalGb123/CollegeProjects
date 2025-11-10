#include "Human.h"
#include <iostream>
#include <cstring>

// Constructor: initializes Human with given details
Human::Human(const string firstName, const string lastName, const string id) 
      : firstName(firstName), lastName(lastName), id(id) {}

// Copy constructor: creates a new Human as a copy of another
Human::Human(const Human& other) 
      : firstName(other.firstName), lastName(other.lastName), id(other.id) {}

// Destructor: cleans up Human (nothing special needed here)
Human::~Human() {}

// Prints all details of the human
void Human::printDetails() const {
      cout << "First Name: " << firstName << "\n";
      cout << "Last Name: " << lastName << "\n";
      cout << "ID: " << id << "\n";
}