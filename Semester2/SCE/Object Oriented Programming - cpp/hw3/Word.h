class Word{
      private:
            char* word;
            int charCount;
      public:
            Word(char* word);
            Word();
            void SetDefault();
            ~Word();
            void operator!();
            void operator&();
            void operator<<(int n);
            void operator>>(int n);
            void operator+=(int n);
            void operator-=(int n);
            char& operator[](int n);
            friend std::ostream& operator<<(std::ostream& os, const Word& word);
};