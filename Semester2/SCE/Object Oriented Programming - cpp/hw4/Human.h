#include <string>
using namespace std;

class Human {
      private:
            string firstName;
            string lastName;
            string id;
      public:
            Human(const string firstName, const string lastName, const string id);
            ~Human();
            Human(const Human& other);
            Human& operator=(const Human& other);
            const string getFirstName() const;
            const string getLastName() const;
            const string getId() const;
            virtual void printDetails() const;
};

