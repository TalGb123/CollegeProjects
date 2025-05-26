#include <ostream>
using namespace std;

class Word{
      private:
            char* word;
            int charCount;
      public:
            Word(char* word);
            Word(int size);
            Word();
            void SetDefault();
            Word(const Word& other);
            ~Word();
            void atbash();
            void operator!();
            void operator&();
            void operator<<(int n);
            void operator>>(int n);
            void operator+=(int n);
            void operator-=(int n);
            char& operator[](int n);
            Word& operator=(const Word& other);
            friend ostream& operator<<(ostream& out, const Word& other);
};