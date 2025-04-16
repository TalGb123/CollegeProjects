#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(char val, bool mode) {
    this->value = val;
    this->mode = mode;
}

Card::Card() {
    SetDefault();
}

void Card::SetDefault() {
    this->value = '1';
    this->mode = false;
}

void Card::ChangeMode() {
    this->mode = !this->mode;
}

bool Card::CompareCards(Card other) {
    if (this->value == other.value){
        return true;
    } 
    return false;
}

void Card::PrintCard() {
    cout << "[   " << (this->mode ? this->value : '?') << "   ]";
}
