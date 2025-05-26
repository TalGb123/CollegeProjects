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
            friend ostream& operator<<(ostream& out, const EncryptedText& other);
};