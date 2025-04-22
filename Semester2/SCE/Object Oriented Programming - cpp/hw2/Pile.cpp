#include "Pile.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

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

Pile::~Pile() {
    delete[] this->pile;
}

void Pile::PileFiller() {
    for (int i = 0; i < this->pileSize; i += 2) {
        char cardValue = 'A' + (i / 2);
        this->pile[i].SetCard(cardValue);
        this->pile[i + 1].SetCard(cardValue);
    }
}

void Pile::PileShuffle() {
    for (int i = this->pileSize - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Card temp = this->pile[i];
        this->pile[i] = this->pile[j];
        this->pile[j] = temp;
    }
}

void Pile::PileOpener() {
    static Pile* prevOpened = new Pile(this->pileSize);
    int j = 0;
    for (int i = 0; i < this->pileSize; i++) {
        if (!this->pile[i].GetMode()) {
            this->pile[i].ChangeMode();
            prevOpened->pile[j].SetCard(this->pile[i].GetValue());
            j++;
        }
    }
    PrintPile();
    int sec = 10;
    clock_t start_time = clock();
    clock_t end_time = sec * 1000 + start_time;
    while (clock() < end_time) {}
    for (int i = 0; i < this->pileSize; i++) {
        bool found = false;
        for (int k = 0; k < j; k++) { 
            if (this->pile[i].GetValue() == prevOpened->pile[k].GetValue() && this->pile[i].GetMode()) {
                found = true;
                break;
            }
        }
        if (found) {
            this->pile[i].ChangeMode();
        }
    }
    system("cls");
}

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

void Pile::CardOpener(int row, int col) {
    int index = (row - 1) * 5 + (col - 1);
    if (index >= 0 && index < this->pileSize) {
        this->pile[index].ChangeMode();
    } else {
        cout << "Invalid card selection." << endl;
    }
}