#include <stdbool.h>
#include "horse.h"
#include "track.h"
#include <iostream>
#include <string>

/**
 * Two version may be selected between
 * 
 * NORMAL: base code that was asked for
 * 
 * STRETCH: "pushing the envelope" by including rudimentary 'betting'
 * - Horses have unique odds of flipping a coin
 * - Horses have 'odds' to win (that I made up)
 * - User guesses a horse to win and a dollar amount to bet
 * - After race, user gets total earnings
 * 
 * I decided to keep everything in main() as not to create new classes
 * and deviate from the assignment
 */

int main() {
    using namespace std; // Used for cin
    int NUM_OF_HORSES = 5;

    // Stretch/gambling variables
    int earnings = 0;
    int bet = 0;
    int horsePicked;
    bool stretch = false;

    // Version selection
    printf("Which version do you want: 0 - Normal, 1 - Stretch ");
    int input;
    cin >> input;
    switch (input)
    {
        case 0:
            stretch = false;
            break;
        case 1:
            stretch = true;
            break;
        default:
            printf("\nInvalid input, normal mode chosen\n");
    }

    int oddsArray[NUM_OF_HORSES];
    if (stretch) { // STRETCH: Chance of horse flipping heads (out of 100)
        oddsArray[0] = 45;
        oddsArray[1] = 48;
        oddsArray[2] = 50;
        oddsArray[3] = 54;
        oddsArray[4] = 55;
    } 
    else {
        for (int i = 0; i < NUM_OF_HORSES; i++) { // Base game, all flips are 50/50
            oddsArray[i] = 50;
        }
    }

    // Creates game track
    Track track = Track(oddsArray);

    // Allows for multiple races per session
    bool playAgain = true;
    int loops = 0;
    while (playAgain && loops < 1000) {
        int multiplier;
        // STRETCH: User places bet
        if (stretch) {
            printf("Which horse will win? Lower number horse wins in tie.\n0 - 1/2,\n1 - 1/3,\n2 - 1/5,\n3 - 1/6,\n4 - 1/10\n");
            cin >> horsePicked;
            printf("\nYou picked horse %d. How much will you bet? ", horsePicked);
            cin >> bet;
            printf("\n$%d on %i\n", bet, horsePicked);
        }

        // Actual race
        int winningHorse = track.runGame();

        // STRETCH: Calculates winnings
        if (stretch) {
            if (horsePicked != winningHorse) {
                earnings -= bet;
            }
            else {
                switch (winningHorse) 
                {
                    case 0:
                        bet *= 2;
                        break;
                    case 1:
                        bet *= 3;
                        break;
                    case 2:
                        bet *= 5;
                        break;
                    case 3:
                        bet *= 6;
                        break;
                    case 4:
                        bet *= 10;
                        break;
                }
            }
            printf("\nCurrent payout: $%d", earnings);
        }
        playAgain = track.askNewGame();
        
    }
    return 0;
}