#include "Worker.h"
#pragma once

class Nurse : public Worker {
      private:
            string department;
            int courses;
      public:
            Nurse(const string firstName, const string lastName, const string id, int seniority,
                   const string department, const int courses);
            Nurse(const Nurse& other);
            Nurse& operator=(const Nurse& other);
            ~Nurse();
            void printDetails() const override;
            bool excellentWorker() const;
            double calculateSalary() const override;
};