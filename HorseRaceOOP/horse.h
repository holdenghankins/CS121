//Horse.h
#ifndef HORSE_H_EXISTS
#define HORSE_H_EXISTS
#include <string>
#include <stdbool.h>
#include <iostream>

class Horse {
private:
    int name;
    int flipChance;
    int position;
    static const int TRACK_LEN = 15;

public:
    Horse();
    Horse(int name, int flipChance);
    int getName();
    void moveToStart();
    void advance();
    bool hasWon();
    void printLane();
    void turn(int coinFlipNumber);
    int GET_TRACK_LEN();
};
#endif