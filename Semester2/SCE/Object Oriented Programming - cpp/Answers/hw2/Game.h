// Assignment: 2
// Creator: Tal Gubenko, 215681107

#include "Pile.h"

class Game{
    private:
        Pile* pile;
        int coupleFound;

    public:
        Game(int pileSize);
        ~Game();
        void Run();
        int GetCoupleFound() { return this->coupleFound; }
};