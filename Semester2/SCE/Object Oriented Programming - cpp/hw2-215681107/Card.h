// Assignment: 2
// Creator: Tal Gubenko, 215681107

class Card {
    private:
        char value;
        bool mode;

    public:
        Card(char val, bool mode);
        Card();
        void SetDefault();
        void ChangeMode();
        bool CompareCards(Card otherCard);
        void PrintCard();
        void SetCard(char val) { this->value = val; this->mode = false; };
        bool GetMode() { return this->mode; };
        char GetValue() { return this->value; }
};