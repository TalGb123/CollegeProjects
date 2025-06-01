#include "Worker.h"
#include <iostream>
#include <cstring>
using namespace std;

Worker::Worker(const string firstName, const string lastName, const string id, int seniority)
    : Human(firstName, lastName, id), seniority(seniority) {
      if (seniority < 0) {
            this->seniority = 0; 
      }
}

Worker::Worker(const Worker& other)
    : Human(other), seniority(other.seniority) {
      if (seniority < 0) {
            seniority = 0; 
      }
}

Worker::~Worker() {}

double Worker::calculateSalary() const {
      return seniority * 1000 + 6500;
}

bool Worker::excellentWorker(Worker* workers) const {
      for (int i = 0; i < sizeof(workers)/sizeof(Worker); ++i) {
            if (workers[i].seniority > 5) {
                  return true;
            }
      }
}

void Worker::printDetails() const {
      Human::printDetails();
      cout << "Seniority: " << this->seniority << "\n";
      cout << "Salary: " << calculateSalary() << "\n";
}

