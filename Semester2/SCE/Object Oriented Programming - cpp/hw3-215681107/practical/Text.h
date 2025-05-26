#include <ostream>
#include "Word.h"


class Text{
      private:
            Word** words;
            int wordCount;
      public:
            Text(Word** words, int len);
            Text();
            void SetDefault();
            ~Text();
            Text(const Text& other);
            void setWord(int idx, const char* word);
            int getWordCount() const;
            Text& operator!();
            Text& operator&();
            Text& operator<<(int n);
            Text& operator>>(int n);
            Text& operator+=(int n);
            Text& operator-=(int n);
            Word& operator[](int n);
            friend ostream& operator<<(ostream& out, const Text& other);
};