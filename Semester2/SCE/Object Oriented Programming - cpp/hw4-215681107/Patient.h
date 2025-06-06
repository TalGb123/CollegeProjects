#include "Human.h"
#pragma once

class Patient : public Human {
      private:
            string department;
            int testsDone;
            int negTests;
      public:
            Patient(const string firstName, const string lastName, const string id, 
                    const string department, int testsDone, int negTests);
            Patient(const Patient& other);
            ~Patient();
            void printDetails() const override;
            int getNegTests() const { return this->negTests; };     
            int getTestsDone() const { return this->testsDone; };
            void setTestsDone(int testsDone) { this->testsDone = testsDone; };
            void setNegTests(int negTests) { this->negTests = negTests; };
            const string getHospital() const { return this->department;  };
};