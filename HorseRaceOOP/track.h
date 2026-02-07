#ifndef TRACK_H_EXISTS
#define TRACK_H_EXISTS

#include "horse.h"

class Track {
    private:
        const static int NUM_OF_HORSES = 5;
        Horse horseArray[NUM_OF_HORSES];

    public:
        Track(int oddsArray[NUM_OF_HORSES]);
        void startGame();
        int flipCoinSeed();
        bool askNewGame();
        void gameTurn();
        void resetGame();
        int runGame();
};
#endif