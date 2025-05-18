#include "Text.cpp"

class EncryptedText{
      private:
            Text* text;
            bool status;
            int* key;
            int keySize;
      public:
            EncryptedText(char* text, bool status);
            EncryptedText();
            void SetDefault();
            ~EncryptedText();
            void ProcessKey(bool status);
            void operator!();
            void operator&();
            void operator<<(int n);
            void operator>>(int n);
            void operator+=(int* key);
            void operator-=(int n);
            Text& operator[](int n);
            friend std::ostream& operator<<(std::ostream& os, const EncryptedText& text);
};