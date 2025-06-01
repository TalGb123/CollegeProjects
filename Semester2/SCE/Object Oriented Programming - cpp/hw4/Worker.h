#include "Human.h"

class Worker : public Human{
      private:
            int seniority;
      public:
            Worker(const string firstName, const string lastName, const string id, int seniority);
            ~Worker();
            Worker(const Worker& other);
            Worker& operator=(const Worker& other);
            int getSeniority() const;
            void printDetails() const override;
            virtual double calculateSalary() const;
            virtual bool excellentWorker(Worker* workers) const;
};