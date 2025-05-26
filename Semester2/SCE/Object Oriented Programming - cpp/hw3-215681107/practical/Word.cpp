#include "Word.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS


Word::Word(char* word){
      // Construct Word from C-string
      SetDefault();
      this->word = new char[strlen(word) + 1];
      strcpy(this->word, word);
      this->charCount = strlen(word);
}

Word::Word(int size){
      // Construct random word of given size (lowercase letters)
      this->word = new char[size + 1];
      for (int i = 0; i < size; ++i) {
            this->word[i] = 'a' + (rand() % 26);
      }
      this->word[size] = '\0';  
}

Word::Word(){
      // Default constructor
      SetDefault();
}

void Word::SetDefault(){
      // Initialize members to default values
      this->word = nullptr;
      this->charCount = 0;
}

Word::~Word(){
      // Destructor: free memory
      delete[] word;
}

Word::Word(const Word& other) {
      // Copy constructor: deep copy
      this->charCount = other.charCount;
      this->word = new char[this->charCount + 1];
      strcpy(this->word, other.word);
}

Word& Word::operator=(const Word& other) {
      // Assignment operator: deep copy
      if (this == &other) return *this;
      delete[] this->word;
      this->charCount = other.charCount;
      this->word = new char[this->charCount + 1];
      strcpy(this->word, other.word);
      return *this;
}

void Word::atbash() {
      // Apply Atbash cipher to each letter, preserving case
      for (int i = 0; i < charCount; ++i) {
            if (isupper(word[i]))
                  word[i] = tolower('Z' - (word[i] - 'A'));
            else if (islower(word[i]))
                  word[i] = toupper('z' - (word[i] - 'a'));
      }
}

void Word::operator!() {
      // Apply Atbash cipher (same as atbash)
      for (int i = 0; i < charCount; ++i) {
            if (isupper(word[i]))
                  word[i] = tolower('Z' - (word[i] - 'A'));
            else if (islower(word[i]))
                  word[i] = toupper('z' - (word[i] - 'a'));
      }
}

void Word::operator&(){
      // Reverse the characters in the word
      for (int i=0; i<this->charCount/2; i++){
            char temp = this->word[i];
            this->word[i] = this->word[this->charCount-i-1];
            this->word[this->charCount-i-1] = temp;
      }
}

void Word::operator<<(int n) {
      // Shift characters left by n positions
      if (charCount == 0) return;
      n = ((n % charCount) + charCount) % charCount;
      char* temp = new char[charCount + 1];
      for (int i = 0; i < charCount; ++i) {
            temp[i] = word[(i + n) % charCount];
      }
      temp[charCount] = '\0';
      strcpy(word, temp);
      delete[] temp;
}

void Word::operator>>(int n) {
      // Shift characters right by n positions
      if (charCount == 0) return;
      n = ((n % charCount) + charCount) % charCount;
      char* temp = new char[charCount + 1];
      for (int i = 0; i < charCount; ++i) {
            temp[i] = word[(i - n + charCount) % charCount];
      }
      temp[charCount] = '\0';
      strcpy(word, temp);
      delete[] temp;
}

void Word::operator+=(int n){
      // Insert a random character at position n
      char randomChar;
      int r = rand() % 62;
      if (r < 26)
            randomChar = 'A' + r; // 'A'-'Z'
      else if (r < 52)
            randomChar = 'a' + (r - 26); // 'a'-'z'
      else
            randomChar = '0' + (r - 52); // '0'-'9'
      if (n < 0){
            n = this->charCount + n;
      }
      if (n > this->charCount){
            n = this->charCount;
      }
      char* temp = new char[this->charCount + 2];
      int j = 0;
      for (int i = 0; i <= this->charCount; i++) {
            if (i == n) {
                  temp[j++] = randomChar;
            }
            if (j <= this->charCount){
                  temp[j++] = this->word[i];
            }
      }
      temp[this->charCount + 1] = '\0';
      strcpy(this->word, temp);
      this->charCount++;
      delete[] temp;
}

void Word::operator-=(int n){
      // Remove character at position n
      if (this->charCount == 0) return;
      if (n < 0)
            n = this->charCount + n;
      if (n >= this->charCount)
            n = this->charCount - 1;    

      char* temp = new char[this->charCount];
      int j = 0;
      for (int i = 0; i < this->charCount; i++) {
            if (i != n){
                  temp[j++] = this->word[i];
            }
      }
      temp[this->charCount - 1] = '\0';
      strcpy(this->word, temp);
      this->charCount--;
      delete[] temp;
}

char& Word::operator[](int n){
      // Access character at position n (with wrap-around)
      return this->word[((n % this->charCount) + this->charCount) % this->charCount];
}

ostream& operator<<(ostream& out, const Word& other){
      // Output the word (no newline)
      out << other.word;
      return out;
}