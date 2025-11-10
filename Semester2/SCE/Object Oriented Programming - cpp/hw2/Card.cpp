// Assignment: 2
// Creator: Tal Gubenko, 215681107

#include "Card.h"
#include <iostream>
using namespace std;

// Initialize card with value and mode (face up or down)
Card::Card(char val, bool mode) {
    this->value = val;
    this->mode = mode;
}

// Default constructor: sets card to default state
Card::Card() {
    SetDefault();
}

// Set card to default value and mode (hidden)
void Card::SetDefault() {
    this->value = '1';
    this->mode = false;
}

// Flip the card (show/hide)
void Card::ChangeMode() {
    this->mode = !this->mode;
}

// Compare this card to another by value
bool Card::CompareCards(Card other) {
    if (this->value == other.value){
        return true;
    } 
    return false;
}

// Print the card (shows value if revealed, '?' if hidden)
void Card::PrintCard() {
    cout << "[   " << (this->mode ? this->value : '?') << "   ]";
}
