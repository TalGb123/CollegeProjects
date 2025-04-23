// Assignment: 2
// Creator: Tal Gubenko, 215681107

#include "Pile.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Constructor: Initializes the pile with a given size, fills and shuffles it
Pile::Pile(int pileSize) {
    srand(time(0));
    if (pileSize >= 4 && pileSize <= 52) {
        this->pileSize = (pileSize % 2 == 0) ? pileSize : pileSize - 1;
    } else {
        this->pileSize = 20;
    }
    this->pile = new Card[this->pileSize];
    PileFiller();
    PileShuffle();
}

// Destructor: Releases the memory allocated for the pile
Pile::~Pile() {
    delete[] this->pile;
}

// Fills the pile with pairs of cards (A, B, C, ...)
void Pile::PileFiller() {
    for (int i = 0; i < this->pileSize; i += 2) {
        char cardValue = 'A' + (i / 2);
        this->pile[i].SetCard(cardValue);
        this->pile[i + 1].SetCard(cardValue);
    }
}

// Shuffles the pile randomly
void Pile::PileShuffle() {
    for (int i = this->pileSize - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Card temp = this->pile[i];
        this->pile[i] = this->pile[j];
        this->pile[j] = temp;
    }
}

// Temporarily reveals all cards for 10 seconds, then hides them again
void Pile::PileOpener() {
    for (int i = 0; i < this->pileSize; i++) {
        this->pile[i].ChangeMode();
    }
    PrintPile();
    int sec = 10;
    clock_t start_time = clock();
    clock_t end_time = sec * 1000 + start_time;
    while (clock() < end_time) {}
    for (int i = 0; i < this->pileSize; i++) {
        this->pile[i].ChangeMode();
    }
    system("cls");
}

// Prints the pile in a 5-column grid format
void Pile::PrintPile() {
    cout << "        ";
    for (int i = 0; i < 5; i++) {
        cout << "      " << i + 1 << "     " ;
    }
    cout << endl;
    for (int i = 0; i < this->pileSize; i++) {
        if (i % 5 == 0) { 
            if (i != 0) {
                cout << endl;
            }
            cout << (i / 5) + 1 << "         "; 
        }
        this->pile[i].PrintCard(); 
        cout << "   ";
    }
    cout << endl;
}

// Reveals or hides a specific card at the given row and column
void Pile::CardOpener(int row, int col) {
    int index = (row - 1) * 5 + (col - 1);
    if (index >= 0 && index < this->pileSize) {
        this->pile[index].ChangeMode();
    } else {
        cout << "Invalid card selection." << endl;
    }
}