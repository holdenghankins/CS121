#include "horse.h"
#include "track.h"
#include <random>
#include <iostream>
#include <string>
using namespace std;


Track::Track(int oddsArray[NUM_OF_HORSES]) {
    for (int i = 0; i < NUM_OF_HORSES; i++) {
        horseArray[i] = Horse(i, oddsArray[i]);
    }
}

/**
 * Creates horse array and greets user
 */
void Track::startGame() {
    // Turn 0
    for (int i = 0; i < NUM_OF_HORSES; i++) {
        horseArray[i].printLane();
    }

    // With multiple runs and an optional extension, a start message seemed nice to have
    std::cout << "Press Enter to start game...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

/**
 * @return a random int between 1 and 100 inclusive
 */
int Track::flipCoinSeed() {
    static std::random_device rd;
    static std::uniform_int_distribution<int> dist(1, 100);
    return dist(rd);
}

/**
 * Flips a coin for all horses one time
 */
void Track::gameTurn() {
    for (int i = 0; i < NUM_OF_HORSES; i++) {
        horseArray[i].turn(flipCoinSeed());
    }
}

/**
 * Goes through an entire game until a horse has wob, waiting for user inputs between turns
 * @returns name of winning horse
 */
int Track::runGame() {
    startGame();
    bool repeat = true;
    int loopCounter = 0;
    while (repeat && loopCounter < 1000) {
        gameTurn();
        for (int i = 0; i < NUM_OF_HORSES; i++) {
            if (horseArray[i].hasWon()) {
                return horseArray[i].getName();
            }
        }

        // Waits for user's input
        std::cout << "Press Enter for another turn...";
        std::cin.get();
        loopCounter++;
    }

    // If time (somehow) expires, no one wins!
    return 5;
}

/**
 * Moves all horses to space 0
 */
void Track::resetGame() {
    for (int i = 0; i < NUM_OF_HORSES; i++) {
        horseArray[i].moveToStart();
    }
}

/**
 * I honestly have no clue if you want a second game since the example still had "click for turn"
 * So I'll just ask the player
 */
bool Track::askNewGame() {
    for (int i = 0; i < 1000; i++) { // Loops till valud response generated
        printf("\n Do you want to play again? 0: No, 1: Yes ");
        int newGameInt;
        cin >> newGameInt;
        switch (newGameInt)
        {
            case 0:
                return false;
            case 1:
                resetGame(); // Sets game up for next run
                return true;
            default:
                printf("\nInvalid input");
        }
    }
    /**
     * Breaks after 1000 attempts
     * Not really a stretch goal, just robustness
     */
    return false;
}