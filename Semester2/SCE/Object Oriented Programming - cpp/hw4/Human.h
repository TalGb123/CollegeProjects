#include <string>
using namespace std;
#pragma once

class Human {
      private:
            string firstName;
            string lastName;
            string id;
      public:
            Human(const string firstName, const string lastName, const string id);
            virtual ~Human();
            Human(const Human& other);
            Human& operator=(const Human& other);
            const string getFirstName() const { return this->firstName; };
            const string getLastName() const { return this->lastName; };
            const string getId() const { return this->id; };
            virtual void printDetails() const;
};