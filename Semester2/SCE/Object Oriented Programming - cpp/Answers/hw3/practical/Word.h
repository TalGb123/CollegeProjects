<<<<<<< HEAD:Semester2/SCE/Object Oriented Programming - cpp/hw3/Word.h
=======
#include <ostream>
>>>>>>> 0d53df1839303054d69a329efc98e905a98f3bbb:Semester2/SCE/Object Oriented Programming - cpp/hw3-215681107/practical/Word.h
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
<<<<<<< HEAD:Semester2/SCE/Object Oriented Programming - cpp/hw3/Word.h
            friend ostream& operator<<(ostream& os, const Word& word);
=======
            Word& operator=(const Word& other);
            friend ostream& operator<<(ostream& out, const Word& other);
>>>>>>> 0d53df1839303054d69a329efc98e905a98f3bbb:Semester2/SCE/Object Oriented Programming - cpp/hw3-215681107/practical/Word.h
};