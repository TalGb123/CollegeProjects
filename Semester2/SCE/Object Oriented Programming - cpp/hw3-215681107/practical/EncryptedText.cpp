#include "EncryptedText.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

// First is the encryption action and second is decryption action
enum ActionType {
      MOVE_LEFT_RIGHT = 1,   // Shift left (enc) / right (dec)
      MOVE_RIGHT_LEFT = 2,   // Shift right (enc) / left (dec)
      ADD_REMOVE = 3,        // Add random word (enc) / remove word (dec)
      COMPLEMENT = 4,        // Atbash cipher
      REVERSE = 5,           // Reverse order
};

// Construct from Text object and status
EncryptedText::EncryptedText(Text* text, bool status) {
      SetDefault();
      this->text = new Text(*text);
      this->status = status;
}

// Construct from C-string and status
EncryptedText::EncryptedText(const char* text, bool status) {
      SetDefault();
      // Count words in input string
      int wordCount = 0;
      bool inWord = false;
      for (int i = 0; text[i] != '\0'; i++) {
            if (!isspace(text[i]) && text[i] != '.' && text[i] != ',' && text[i] != '!' && text[i] != '?') {
                  if (!inWord) {
                        inWord = true;
                        wordCount++;
                  }
            }     
            else {
                  inWord = false;
            }
      }
      // Allocate array of empty Words
      Word** words = new Word*[wordCount];
      for (int i = 0; i < wordCount; ++i) {
            words[i] = new Word();
      }
      this->text = new Text(words, wordCount);
      for (int i = 0; i < wordCount; ++i) {
            delete words[i];
      }
      delete[] words;
      // Fill each Word with the corresponding substring
      int startIndex = -1;
      int wordIndex = 0;
      for (int i = 0; ; i++) {
            char c = text[i];
            bool isWordChar = (c != '\0' && !isspace(c) && c != '.' && c != ',' && c != '!' && c != '?');
            if (isWordChar) {
                  if (startIndex == -1) startIndex = i;
            }
            if (!isWordChar || c == '\0') {
                  if (startIndex != -1) {
                        int wordLength = i - startIndex;
                        if (wordLength > 0 && wordIndex < this->text->getWordCount()) {
                              char* word = new char[wordLength + 1];
                              strncpy(word, &text[startIndex], wordLength);
                              word[wordLength] = '\0';
                              this->text->setWord(wordIndex, word);
                              delete[] word;
                              wordIndex++;
                        }
                        startIndex = -1;
                  }
                  if (c == '\0') break;
            }
      }
      this->status = status;
}

// Default constructor
EncryptedText::EncryptedText() {
      SetDefault();
}

// Set all members to default/null
void EncryptedText::SetDefault() {
      this->text = nullptr;
      this->status = false;
      this->key = nullptr;
      this->keySize = 0;
}

// Destructor: free memory
EncryptedText::~EncryptedText() {
      if (text != nullptr) {
            delete text;
      }
      if (key != nullptr) {
            delete[] key;
      }
}

// Set the key array (must set keySize before calling this)
void EncryptedText::operator+=(int* key) {
      if (this->key != nullptr) {
            delete[] this->key;
      }
      this->key = new int[keySize]; 
      for (int i = 0; i < keySize; i++) {
            this->key[i] = key[i];
      }
}

// Apply encryption: process key if set, otherwise Atbash
void EncryptedText::operator!() {
      if (key && keySize > 0) {
            ProcessKey(true);
      } 
      else if (this->text) {
            (*this->text).operator!();
      }
      this->status = true;
}

// Apply decryption: process key if set, otherwise Atbash
void EncryptedText::operator&() {
      if (key && keySize > 0) {
            ProcessKey(false);
      } 
      else if (this->text) {
            (*this->text).operator!();
      }
      this->status = false;
}

// Apply all key operations in order (encrypt=true) or reverse order (encrypt=false)
void EncryptedText::ProcessKey(bool encrypt) {
      int i,j;
      if (key == nullptr) return;
      if (encrypt) {
            i = 0;
            j = 3;
      }
      else {
            i = this->keySize - 4; // Start at last triplet for decryption
            j = -3;
      }
      int action = 0, selection = -1, param = 0;
      for (; (encrypt ? i < keySize : i >= 0); i += j) {
            action = key[i];
            if (action == -2) break; // Sentinel: stop processing
            selection = key[i + 1];
            param = key[i + 2];
            switch (action) {
                  case MOVE_LEFT_RIGHT:
                        // Shift words left/right or shift characters in a word
                        if (selection == -1)
                              encrypt ? (*text) << param : (*text) >> param;
                        else {
                              Word& w = (*text)[selection];
                              encrypt ? w << param : w >> param;
                        }
                        break;
                  case MOVE_RIGHT_LEFT:
                        // Shift words right/left or shift characters in a word
                        if (selection == -1)
                              encrypt ? (*text) >> param : (*text) << param;
                        else {
                              Word& w = (*text)[selection];
                              encrypt ? w >> param : w << param;
                        }
                        break;
                  case ADD_REMOVE:
                        // Add random word (enc) or remove word (dec)
                        if (selection == -1)
                              encrypt ? (*text) += param : (*text) -= param;
                        else {
                              Word& w = (*text)[selection];
                              encrypt ? w += param : w -= param;
                        }
                        break;
                  case COMPLEMENT:
                        // Atbash cipher (all words or one word)
                        if (selection == -1)
                              !(*text);
                        else {
                              Word& w = (*text)[selection];
                              !w;
                        }
                        break;
                  case REVERSE:
                        // Reverse order of words or reverse a word
                        if (selection == -1)
                              &(*text);
                        else {
                              Word& w = (*text)[selection];
                              &w;
                        };
                        break;
                  default:
                        break;
            }
      }
}

// Output the text and key in required format
ostream& operator<<(ostream& out, const EncryptedText& text) {
      out << "The " << (text.status ? "encrypted" : "decrypted") << " text: ";
      out << *(text.text) << endl;
      out << "The key: ";
      if (text.key == nullptr || text.keySize == 0) {
            out << "empty" << endl;
      } 
      else {
            for (int i = 0; i < text.keySize; i++) {
                  out << text.key[i];
                  if ((i + 1) % 3 == 0 || i == text.keySize - 1)
                  out << endl;
                  else
                  out << " ";
            }
      }
      return out;
}