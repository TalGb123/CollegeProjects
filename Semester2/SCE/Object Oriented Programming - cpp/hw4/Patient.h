#include "Human.h"

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
            int getNegTests() const;     
};