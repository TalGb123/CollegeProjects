#include "Text.h"

class EncryptedText{
      private:
            Text* text;
            bool status;
            int* key;
            int keySize;
      public:
            EncryptedText(const char* text, bool status);
            EncryptedText(Text* text, bool status);
            EncryptedText();
            void SetDefault();
            ~EncryptedText();
            void setKeySize(int size) { keySize = size; }
            void ProcessKey(bool status);
            void operator!();
            void operator&();
            void operator<<(int n);
            void operator>>(int n);
            void operator+=(int* key);
            void operator-=(int n);
            Text& operator[](int n);
<<<<<<< HEAD:Semester2/SCE/Object Oriented Programming - cpp/hw3/EncryptedText.h
            friend ostream& operator<<(ostream& os, const EncryptedText& text);
=======
            friend ostream& operator<<(ostream& out, const EncryptedText& other);
>>>>>>> 0d53df1839303054d69a329efc98e905a98f3bbb:Semester2/SCE/Object Oriented Programming - cpp/hw3-215681107/practical/EncryptedText.h
};