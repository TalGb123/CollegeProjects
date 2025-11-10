// Assignment: 2
// Creator: Tal Gubenko, 215681107


#include "Card.h"

class Pile {
private:
    Card* pile;
    int pileSize;

public:
    Pile(int pileSize);
    ~Pile();
    void PrintPile();
    void PileFiller();
    void PileShuffle();
    void PileOpener();
    void CardOpener(int row, int col);
    Card* GetCard(int index) { return &this->pile[index]; }
    int GetPileSize() { return this->pileSize; }
};