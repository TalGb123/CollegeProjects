#include "Worker.h"

class Doctor : public Worker {
      private:
            string department;
            bool professor;
            int positiveReviews;
      public:
            Doctor(const string firstName, const string lastName, const string id, int seniority, 
                   const string department, bool professor, int positiveReviews);
            Doctor(const Doctor& other);
            Doctor& operator=(const Doctor& other);
            ~Doctor();
            void printDetails() const override;
            bool excellentDoctor() const;
            double calculateSalary() const override;
};

