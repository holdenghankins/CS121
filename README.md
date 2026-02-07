# CS121-OOPHorseRace

My final code of course diviated from this, but I want to preserve my original thought process
classDiagram

class Horse {
    - int name
    - int flipChance
    - int TRACK_LENGTH
    - array[TRACK_LENGTH]
    - int position
    + int getName()
    + int getFlipChance()
    + void advance()
    + void printLane()
    + bool hasWon(Horse horse)
}

class Race {
    - int NUM_HORSES
    - int TRACK_LENGTH
    - Horse[NUM_HORSES] horseArray
    + void startGame()
    + void gameTurn()
    + int runGame()
}

Main {
    Introduce game
    Ask for base version or stretch version to make grading easier
    if stretch {
        // Simple gambling system
        create 5 horses with different likelihoods of winning
        print odds for each horse // these are made up
        ask user which horse they think will win
        ask user how much money they will put down
    }
    else {
        create 5 horses with 50/50 odds
    }
    while (user has not ended program) {
        int winner = Race.runGame()
        if stretch {
            tell user if they guessed correctly
            calculate earnings
            tell them their winnings
        }
        ask if they want to race again
    }
}