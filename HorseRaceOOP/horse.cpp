#include <string>
#include <stdbool.h>
#include <iostream>
#include "horse.h"

Horse::Horse()
    : name(-1), flipChance(0), position(0) {}

Horse::Horse(int name, int flipChance)
    : name(name), flipChance(flipChance), position(0) {}

int Horse::getName() {
    return name;
}

/**
 * Following 2 control position of horse on track
 */

void Horse::advance() {
    position++;
}

void Horse::moveToStart() {
    position = 0;
}

/**
 * Identifies if horse has exceded track limits
 */
bool Horse::hasWon() {
    return position >= TRACK_LEN;
}

/**
 * Prints the lane in format of [ 15 dots ] with dot of current location replaced name
 */
void Horse::printLane() {
        std::string lane = "[ ";
    for (int i = 0; i < TRACK_LEN; i++) {
        if (i == position) {
            lane += std::to_string(name) + " ";
        } else {
            lane += ". ";
        }
    }
    std::cout << lane << "]" << std::endl;

    // Horse reaches end of path
    if (position >= TRACK_LEN) {
        printf("H O R S E  %i  W I N S ! ! ! \n", name);
    }
}

/**
 * If coin flip is less than flip chance + 1, advance
 * This allows flip chance to be a percentage chance
 * coinFlipNumber is obtained in Track
 */
void Horse::turn(int coinFlipNumber) {
    if (coinFlipNumber <= flipChance) {
        advance();
    }
    printLane();
}

/**
 * @returns universal track length
 */
int Horse::GET_TRACK_LEN() {
    return TRACK_LEN;
}