#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(int pileSize) {
    if (pileSize < 4 || pileSize > 52) {
        cout << "Invalid number of cards. Defaulting to 20 cards." << endl;
        pileSize = 20;
    }
    this->pile = new Pile(pileSize);
    this->coupleFound = 0;
}

Game::~Game() {
    delete this->pile;
}

void Game::Run() {
    while (true){
        cout << "Get ready you have 10 seconds to memorize:" << endl;
        this->pile->PileOpener();
        this->pile->PrintPile();
        int row1, col1;
        cout << "Choose the first card by entering the row and col numbers" << endl;
        cout << " Row: ";
        cin >> row1;
        cout << " Col: ";
        cin >> col1;
        this->pile->CardOpener(row1, col1);
        this->pile->PrintPile();
        int row2, col2;
        cout << "Choose the second card by entering the row and col numbers" << endl;
        cout << " Row: ";
        cin >> row2;
        cout << " Col: ";
        cin >> col2;
        this->pile->CardOpener(row2, col2);
        this->pile->PrintPile();
        if (this->pile->GetCard((row1-1)*5+col1-1)->CompareCards(*this->pile->GetCard((row2-1)*5+col2-1))) {
            cout << "You found a couple!";
            this->coupleFound++;
            bool allFound = true;
            for (int i = 0; i < this->pile->GetPileSize(); i++) {
                if (!this->pile->GetCard(i)->GetMode()) {
                    allFound = false;
                    break;
                }
            }
            if (allFound) {
                cout << "\nCongratulations! You found all " << this->coupleFound << " couples!" << endl;
                return;
            }
        } else {
            cout << "Not a couple. Try again.";
            this->pile->CardOpener(row1, col1);
            this->pile->CardOpener(row2, col2);
        }
        cout << "Do you want to continue? 1-yes 0-no" << endl;
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 0) {
            cout << "Invalid choice. Please enter 1 to continue or 0 to exit." << endl;
            cin >> choice;
        }
        if (choice == 0) {
            cout << "You found " << this->coupleFound << " couples." << endl;
            break;
        }
        system("cls");
    }
    
    
}