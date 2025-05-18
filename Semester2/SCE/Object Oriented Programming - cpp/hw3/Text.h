#include "Word.cpp"
#include <iostream>

class Text{
      private:
            Word* words;
            int wordCount;
      public:
            Text(char* text);
            Text();
            void SetDefault();
            ~Text();
            void operator!();
            void operator&();
            void operator<<(int n);
            void operator>>(int n);
            void operator+=(int n);
            void operator-=(int n);
            Word& operator[](int n);
            friend std::ostream& operator<<(std::ostream& os, const Text& text);
};