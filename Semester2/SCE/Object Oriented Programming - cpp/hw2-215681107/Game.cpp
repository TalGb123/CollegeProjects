// Assignment: 2
// Creator: Tal Gubenko, 215681107

#include "Game.h"
#include <iostream>
using namespace std;

// Constructor: Initializes the game with a pile of cards
Game::Game(int pileSize) {
    if (pileSize < 4 || pileSize > 52) {
        cout << "Invalid number of cards. Defaulting to 20 cards." << endl;
        pileSize = 20;
    }
    this->pile = new Pile(pileSize);
    this->coupleFound = 0;
}

// Destructor: Cleans up the pile memory
Game::~Game() {
    delete this->pile;
}

// Main game loop: handles the memory game logic and user interaction
void Game::Run() {
    cout << "Get ready you have 10 seconds to memorize:" << endl;
    this->pile->PileOpener();
    while (true){
        this->pile->PrintPile();
        // First card selection and validation
        int row1, col1;
        cout << "Choose the first card by entering the row and col numbers" << endl;
        cout << " Row: ";
        cin >> row1;
        cout << " Col: ";
        cin >> col1;
        while ((row1 > ((this->pile->GetPileSize()+4)/5) || row1 < 1) ||
            (((row1-1)*5+col1-1) >= this->pile->GetPileSize()) ||
                (this->pile->GetCard((row1-1)*5+col1-1)->GetMode())){
            cout << "Invalid choice. Please choose a different card for the first one." << endl;
            cout << " Row: ";
            cin >> row1;
            cout << " Col: ";
            cin >> col1;    
        }
        this->pile->CardOpener(row1, col1);
        this->pile->PrintPile();
        // Second card selection and validation
        int row2, col2;
        cout << "Choose the second card by entering the row and col numbers" << endl;
        cout << " Row: ";
        cin >> row2;
        cout << " Col: ";
        cin >> col2;
        while ((row2 > ((this->pile->GetPileSize()+4)/5) || row2 < 1) ||
            (((row2-1)*5+col2-1) >= this->pile->GetPileSize()) ||
                (this->pile->GetCard((row2-1)*5+col2-1)->GetMode())){
            cout << "Invalid choice. Please choose a different card for the second one." << endl;
            cout << " Row: ";
            cin >> row2;
            cout << " Col: ";
            cin >> col2;
        }
        this->pile->CardOpener(row2, col2);
        this->pile->PrintPile();
        // Check if the two selected cards are a match
        if (this->pile->GetCard((row1-1)*5+col1-1)->CompareCards(*this->pile->GetCard((row2-1)*5+col2-1))) {
            cout << "You found a couple!";
            this->coupleFound++;
            bool allFound = true;
            // Check if all pairs have been found
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
            // Not a match: hide both cards again
            cout << "Not a couple. Try again.";
            this->pile->CardOpener(row1, col1);
            this->pile->CardOpener(row2, col2);
        }
        // Ask the user if they want to continue or exit
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