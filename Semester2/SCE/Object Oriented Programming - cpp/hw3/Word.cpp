#include "Word.h"
#include <cstring>
#include <iostream>
#include <cstdlib>

Word::Word(char* word){
      SetDefault();
      this->word = new char[strlen(word) + 1];
      strcpy(this->word, word);
      this->charCount = strlen(word);
}

Word::Word(){
      this->word = new char[1];
      this->word[0] = '\0';
      this->charCount = 0;
}

void Word::SetDefault(){
      this->word = new char[1];
      this->word[0] = '\0';
      this->charCount = 0;
}

Word::~Word(){
      delete[] word;
}

void Word::operator!(){
      for (int i=0; i<this->charCount; i++){
            if (isalpha(this->word[i])){
                  if (isupper(this->word[i])){
                        this->word[i] = tolower('Z' - this->word[i] + 'A');
                  }
                  else{
                        this->word[i] = toupper('z' - this->word[i] + 'a');
                  }
            }
            else if (isdigit(this->word[i])){
                  this->word[i] = '9' - this->word[i] - '0';
            }
      }
}

void Word::operator&(){
      for (int i=0; i<this->charCount/2; i++){
            char temp = this->word[i];
            this->word[i] = this->word[this->charCount-i-1];
            this->word[this->charCount-i-1] = temp;
      }
}

void Word::operator<<(int n){
      if (this->charCount == 0) return;
      char* temp = new char[this->charCount + 1];
      n = n % this->charCount;
      for (int i=0; i<this->charCount; i++){
            temp[i] = this->word[(i+n)%this->charCount];
      }
      temp[this->charCount] = '\0';
      strcpy(this->word, temp);
      delete[] temp;
}

void Word::operator>>(int n){
      if (this->charCount == 0) return;
      char* temp = new char[this->charCount + 1];
      n = n % this->charCount;
      for (int i=0; i<this->charCount; i++){
            temp[i] = this->word[(i - n + this->charCount) % this->charCount];
      }
      temp[this->charCount] = '\0';
      strcpy(this->word, temp);
      delete[] temp;
}

void Word::operator+=(int n){
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
    return this->word[((n % this->charCount) + this->charCount) % this->charCount];
}

