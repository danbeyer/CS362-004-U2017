/*Name: Daniel Beyer
* CS362 - Week 3 Assignment
* Description: Card test 4 - Tests gardens card
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
    int players = 1;
    int numTests = 1;                   
    int card = gardens;
    int effect;
    int initHandCount;
    int position;
	

	

     printf("\n\nTesting Gardens Card\n\n");

    for (i = 0; i < numTests; i++) {

        // initialize the game
        initializeGame(players, kc, 1000, &gameOrig);

        // copy over to test gameState
        memcpy(&gameTest, &gameOrig, sizeof(struct gameState));

        // give the opposing player a hand
        gameTest.hand[player1][0] = gardens;
        gameTest.hand[player1][1] = gold;             
        gameTest.hand[player1][2] = smithy;
        gameTest.hand[player1][3] = great_hall;
        gameTest.hand[player1][4] = gold;
		gameTest.hand[player1][5] = gold;
		gameTest.hand[player1][6] = gold;
		gameTest.hand[player1][7] = gold;
		gameTest.hand[player1][8] = gold;
		gameTest.hand[player1][9] = gold;
		gameTest.hand[player1][10] = gold;
		gameTest.hand[player1][11] = gold;
		
		
		gameTest.deckCount[player1] = 5;
            

		
		//Assign deck cards
		for(i=0; i< gameTest.deckCount[player1]; i++)
		{
			gameTest.deck[player1][i] = gold;
		}


        initHandCount = gameTest.handCount[player1];
        position = gameTest.hand[player1][0];

        effect = cardEffect(card, 0, 0, 0, &gameTest, position, 0);

        printf("Player 1 (gardens player)\n\n");
        //Player 1 has drawn + 4 cards
        if (effect == -1) {
            printf("Passed\n");
            
        }
		//Player 1 has not drawn + 4 cards
        else {
            printf("Failed\n");
            
        }
		int getp1Score = scoreFor(player1, &gameTest);
		                      
			if (getp1Score != (gameTest.deckCount[player1] / 10)) {
			printf("FAILED\n");
			} else {
			printf("PASSED\n");
			}
    }
    return 0;
}