#include "Text.h"
#define _CRT_SECURE_NO_WARNINGS


Text::Text(Word** words, int len) {
      // Construct Text from array of Word pointers
      SetDefault();
      this->wordCount = len;
      this->words = new Word*[len];
      for (int i = 0; i < len; i++) {
            this->words[i] = nullptr;
      }
}

Text::Text(){
      // Default constructor
      SetDefault();
}

void Text::SetDefault() {
      // Initialize members to default values
      this->words = nullptr;
      this->wordCount = 0;
}

Text::Text(const Text& other){
      // Copy constructor: deep copy of all words
      int len = other.wordCount;
      this->wordCount = len;
      this->words = new Word * [len];
      for (int i = 0; i < len; ++i) {
            if (other.words[i]) {
                  this->words[i] = new Word(*other.words[i]);
            }
            else {
                  this->words[i] = nullptr;
            }
      }
}

Text::~Text(){
      // Destructor: free all words and the array
      if (this->words != nullptr) {
            for (int i = 0; i < this->wordCount; ++i) {
                  delete this->words[i];
            }
            delete[] this->words;
            this->words = nullptr;
            this->wordCount = 0;
      } 
}

void Text::setWord(int idx, const char* word) {
      // Set the word at index idx to a new value
      if (idx >= 0 && idx < wordCount) {
            delete words[idx];
            words[idx] = new Word((char*)word);
      } 
}

int Text::getWordCount() const {
      // Return the number of words
      return wordCount;
}

Text& Text::operator!(){
      // Apply Atbash to all words in the text
      if (this->wordCount == 0) return *this;
      for (int i = 0; i < this->wordCount; i++) {
            if (this->words[i]) {
                  this->words[i]->atbash();
            }
      }
      return *this;
}

Text& Text::operator&() {
      // Reverse the order of words in the text
      for (int i = 0, j = wordCount - 1; i < j; ++i, --j) {
            Word* temp = words[i];
            words[i] = words[j];
            words[j] = temp;
      }
      return *this;
}

// Shift words left by n positions
Text& Text::operator<<(int n) {
      if (wordCount == 0) return *this;
      n = ((n % wordCount) + wordCount) % wordCount;
      Word** temp = new Word*[wordCount];
      for (int i = 0; i < wordCount; ++i) {
            temp[i] = words[(i + n) % wordCount];
      }
      for (int i = 0; i < wordCount; ++i) {
            words[i] = temp[i];
      }
      delete[] temp;
      return *this;
}

// Shift words right by n positions
Text& Text::operator>>(int n) {
      if (wordCount == 0) return *this;
      n = ((n % wordCount) + wordCount) % wordCount;
      Word** temp = new Word*[wordCount];
      for (int i = 0; i < wordCount; ++i) {
            temp[i] = words[(i - n + wordCount) % wordCount];
      }
      for (int i = 0; i < wordCount; ++i) {
            words[i] = temp[i];
      }
      delete[] temp;
      return *this;
}

Text& Text::operator+=(int n) {
      // Insert a random word at position n
      if (n < 0) n = 0;
      if (n > wordCount) n = wordCount;
      int r = rand() % 10 + 1;
      char* buf = new char[r + 1];
      if (r > 0) {
            buf[0] = 'A' + rand() % 26; // First letter uppercase
            for (int i = 1; i < r; ++i)
                  buf[i] = 'a' + rand() % 26; // Rest lowercase
      }
      buf[r] = '\0';

      Word** temp = new Word*[wordCount + 1];
      int j = 0;
      for (int i = 0; i <= wordCount; ++i) {
            if (i == n) temp[j++] = new Word(buf);
            if (i < wordCount) temp[j++] = words[i];
      }
      delete[] words;
      words = temp;
      wordCount++;
      delete[] buf;
      return *this;
}

Text& Text::operator-=(int n) {
      // Remove the word at position n
      if (wordCount == 0) return *this;
      if (n < 0) n += wordCount;
      if (n >= wordCount) n = wordCount - 1;

      Word** temp = new Word*[wordCount - 1];
      int j = 0;
      for (int i = 0; i < wordCount; ++i) {
            if (i != n) temp[j++] = words[i];
            else delete words[i]; 
      }
      delete[] words;
      words = temp;
      wordCount--;
      return *this;
}

Word& Text::operator[](int n) {
      // Access word at position n (with wrap-around)
      return *this->words[((n % this->wordCount) + this->wordCount) % this->wordCount];
}

ostream& operator<<(ostream& out, const Text& other) {
      // Output all words separated by space, ending with a period and newline
      for (int i = 0; i < other.wordCount; i++) {
            if (other.words[i]) {
                  out << *(other.words[i]);
                  if (i < other.wordCount - 1)
                  out << " ";
            }
      }
      out << "." << endl;
      return out;
}