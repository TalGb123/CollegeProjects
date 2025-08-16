#include "Human.h"
#pragma once

class Worker : public Human{
      private:
            int seniority;
      public:
            Worker(const string firstName, const string lastName, const string id, int seniority);
            virtual ~Worker();
            Worker(const Worker& other);
            int getSeniority() const { return this->seniority; }
            void printDetails() const override;
            virtual double calculateSalary() const;
            virtual bool excellentWorker() const;
};
