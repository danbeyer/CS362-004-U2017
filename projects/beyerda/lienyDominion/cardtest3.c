/*Name: Daniel Beyer
* CS362 - Week 3 Assignment
* Description: Card test 3 - Tests Council Room card
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
    int kc[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, council_room, smithy};
    int i;                              
    int player1 = 0;
    int player2 = 1;
    int players = 2;
    int numTests = 1;                   
    int card = council_room;
    int effect;
    int initHandCount;
    int position;
	

	

     printf("\n\nTesting Council Room Card\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        // give the opposing player a hand
        gameTest.hand[player1][0] = council_room;
        gameTest.hand[player1][1] = gold;             
        gameTest.hand[player1][2] = smithy;
        gameTest.hand[player1][3] = great_hall;
        gameTest.hand[player1][4] = feast;
		
		gameTest.deckCount[player1] = 5;
		gameTest.deckCount[player2] = 2;
		
		gameTest.hand[player2][0] = gold;
        gameTest.hand[player2][1] = gold;             

		
		//Assign deck cards


        initHandCount = gameTest.handCount[player1];
        position = gameTest.hand[player1][0];

        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        printf("Player 1 (council room player)\n\n");
        //Player 1 has drawn + 4 cards
        if (effect == 0) {
            printf("Passed\n");
            
        }
		//Player 1 has not drawn + 4 cards
        else {
            printf("Failed\n");
            
        }

		assert(gameTest.handCount[player1] == 8);		//gain 4 cards, discard 1 -> new total of 8 cards in hand
		
    }
    return 0;
}