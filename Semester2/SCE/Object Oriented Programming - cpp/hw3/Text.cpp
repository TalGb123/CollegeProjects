#include "Text.h"
#include <iostream>

Text::Text(char* text) {
      SetDefault();
      int len = strlen(text);
      int count = 0;
      bool inWord = false;
      for (int i = 0; i <= len; i++) {
            if (text[i] != ' ' && text[i] != '\0') {
                  if (!inWord) {
                  count++;
                  inWord = true;
                  }
            } else {
                  inWord = false;
            }
      }
      this->wordCount = count;
      this->words = new Word[this->wordCount];
      int j = 0;
      int start = -1;
      for (int i = 0; i <= len; i++) {
            if (text[i] != ' ' && text[i] != '\0') {
                  if (start == -1) start = i;
            } else {
                  if (start != -1) {
                  int wlen = i - start;
                  char* buf = new char[wlen + 1];
                  for (int k = 0; k < wlen; k++) {
                        buf[k] = text[start + k];
                  }
                  buf[wlen] = '\0';
                  this->words[j++] = Word(buf);
                  delete[] buf;
                  start = -1;
                  }
            }
      }
}

Text::Text(){
      SetDefault();
}

void Text::SetDefault(){
      this->words = new Word[1];
      this->words[0] = "";
      this->wordCount = 0;
}

Text::~Text(){
      delete[] words;
}

void Text::operator!(){
      if (this->wordCount == 0) return;
      for (int i = 0; i < this->wordCount; i++){
            !this->words[i];
      }
}

void Text::operator&(){
      if (this->wordCount == 0) return;
      Word* temp = new Word[this->wordCount];
      for (int i=0; i<this->wordCount; i++){
            temp[i] = this->words[this->wordCount-i-1];
      }
      for (int i=0; i<this->wordCount; i++){
            this->words[i] = temp[i];
      }
      delete[] temp;
}

void Text::operator<<(int n){
      if (this->wordCount == 0) return;
      Word* temp = new Word[this->wordCount + 1];
      n = n % this->wordCount;
      for (int i=0; i<this->wordCount; i++){
            temp[i] = this->words[(i+n)%this->wordCount];
      }
      for (int i=0; i<this->wordCount; i++){
            this->words[i] = temp[i];
      }
      delete[] temp;
}

void Text::operator>>(int n){
      if (this->wordCount == 0) return;
      Word* temp = new Word[this->wordCount + 1];
      n = n % this->wordCount;
      for (int i=0; i<this->wordCount; i++){
            temp[i] = this->words[(i-n)%this->wordCount];
      }
      for (int i=0; i<this->wordCount; i++){
            this->words[i] = temp[i];
      }
      delete[] temp;
}

void Text::operator+=(int n){
      if (this->wordCount == 0) return;
      int r = rand() % 10;
      char* word = new char[r];
      for (int i=0; i<r; i++){
            word+=i;
      }
      Word* temp = new Word[this->wordCount + 2];
      int j = 0;
      for (int i = 0; i <= this->wordCount; i++) {
            if (i == n) {
                  temp[j++] = word;
            }
            if (j <= this->wordCount){
                  temp[j++] = this->words[i];
            }
      }
      delete[] temp;
      delete[] word;
}

void Text::operator-=(int n){
      if (this->wordCount == 0) return;
      if (n < 0)
            n = this->wordCount + n;
      if (n >= this->wordCount)
            n = this->wordCount - 1;    

      Word* temp = new Word[this->wordCount];
      int j = 0;
      for (int i = 0; i < this->wordCount; i++) {
            if (i != n){
                  temp[j++] = this->words[i];
            }
      }
      for (int i=0; i<this->wordCount; i++){
            this->words[i] = temp[i];
      }
      delete[] temp;
}

Word& Text::operator[](int n){
    return this->words[((n % this->wordCount) + this->wordCount) % this->wordCount];
}