#include "EncryptedText.h"
#include <iostream>

// First is the encryption action and second is decryption action
enum ActionType {
      MOVE_LEFT_RIGHT = 1,
      MOVE_RIGHT_LEFT = 2,
      ADD_REMOVE = 3,
      COMPLEMENT = 4,
      REVERSE = 5,
};

EncryptedText::EncryptedText(char* text, bool status) {
      SetDefault();
      this->text = new Text(text);
      this->status = status;
}

EncryptedText::EncryptedText() {
      SetDefault();
}

void EncryptedText::SetDefault() {
      this->text = nullptr;
      this->status = false;
      this->key = nullptr;
      this->keySize = 0;
}

EncryptedText::~EncryptedText() {
      if (text != nullptr) {
            delete text;
      }
      if (key != nullptr) {
            delete[] key;
      }
}

void EncryptedText::operator+=(int* key) {
      if (this->key != nullptr) {
            delete[] this->key;
      }
      this->key = new int[keySize];
      for (int i = 0; i < keySize; i++) {
            this->key[i] = key[i];
      }
}

void EncryptedText::operator!() {
    ProcessKey(true); // encrypt
}

void EncryptedText::operator&() {
    ProcessKey(false); // decrypt
}

void EncryptedText::ProcessKey(bool encrypt) {
      if (key == nullptr){
            return;
      }
      int action;
      int selection;
      int param;
      for (int i = 0; i < this->keySize; i++) {
            if (this->key[i] == -2){
                  return;
            }
            else if ((i+1) % 3 == 0){
                  param = this->key[i];
                  if (selection == -1){
                        switch (action) {
                              case MOVE_LEFT_RIGHT:
                                    encrypt ? (*this->text) << param : (*this->text) >> param;
                                    break;
                              case MOVE_RIGHT_LEFT:
                                    encrypt ? (*this->text) >> param : (*this->text) << param;
                                    break;
                              case ADD_REMOVE:
                                    encrypt ? (*this->text) += param : (*this->text) -= param;
                                    break;
                              case COMPLEMENT:
                                    !(*this->text);
                                    break;
                              case REVERSE:
                                    &(*this->text);
                                    break;
                        }
                  }
                  else {
                        Word& w = (*this->text)[selection];
                        switch (action) {
                              case MOVE_LEFT_RIGHT:
                                    this->status ? w << param : w >> param;
                                    break;
                              case MOVE_RIGHT_LEFT:
                                    this->status ? w >> param : w << param;
                                    break;
                              case ADD_REMOVE:
                                    this->status ? w += param : w -= param;
                                    break;
                              case COMPLEMENT:
                                    !w;
                                    break;
                              case REVERSE:
                                    &w;
                                    break;
                        }
                  }
            }
            else if ((i+1) % 2 == 0){
                  selection = this->key[i];
            }
            else{
                  action = this->key[i];
            }
      }
}



