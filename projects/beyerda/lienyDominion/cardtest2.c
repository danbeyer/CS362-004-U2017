/*Name: Daniel Beyer
* CS362 - Week 3 Assignment
* Description: Card test 2 - Tests adventure card
* Source: Some info taken from cardtest4.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct gameState gameOrig;          // original game state
    struct gameState gameTest;          // game state for testing
    int kc[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int i;                              
    int player1 = 0;
    int player2 = 1;
    int players = 2;
    int numTests = 1;                   
    int card = adventurer;
    int effect;
    int initHandCount;
    int position;

	

     printf("\n\nTesting Adventurer Card\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        // give the player a hand
        gameTest.hand[player1][0] = gold;
        gameTest.hand[player1][1] = adventurer;             
        gameTest.hand[player1][2] = smithy;
        gameTest.hand[player1][3] = great_hall;
        gameTest.hand[player1][4] = feast;

        initHandCount = gameTest.handCount[player1];
        position = gameTest.hand[player1][1];

        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        printf("Player 1 (adventurer player)\n\n");
        //Player 1 has drawn + 3 cards
        if (effect == 0) {
            printf("Passed\n");
            
        }
		//Player 1 has not drawn + 3 cards
        else {
            printf("Failed\n");
            
        }

        printf("Player 2\n\n");

        //Player 2 unchanged after Player 1 plays

        if (gameTest.handCount[player2] == gameOrig.handCount[player2]) {
            printf("Passed\n");
            
        }
        else {
            printf("Failed\n");
            
        }
    }
    return 0;
}