/*Name: Daniel Beyer
* CS362 - Week 3 Assignment
* Description: Unit test 1 - Tests fullDeckCount() Function
* 
*/

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define DECK_SIZE 150
#define HAND_SIZE 150
#define DISCARD_SIZE 150

int main()
{
	//Unit test to test fullDeckCount() function - counts number of specified card

	printf("\n\nUnit Test 1\n\n");
	int testPlayer, testCard, count, i, result;
	struct gameState *testState = newGame();



	testCard = 5;		//silver card
	testPlayer = 1;
	count = 15;			//count should be 15 silver cards

	testState->deckCount[testPlayer] = DECK_SIZE;
	testState->handCount[testPlayer] = HAND_SIZE;
	testState->discardCount[testPlayer] = DISCARD_SIZE;

	//populate the players deck and puts fifteen silver cards in the deck
	for (i = 0; i < DECK_SIZE; i++)
	{
		if (i < 15)
		{
			testState->deck[testPlayer][i] = testCard;
		}
		else
		{
			testState->deck[testPlayer][i] = (i % 5);
		}
	}

	//now we can test to make sure fullDeckCount() returns 15
	result = fullDeckCount(testPlayer, testCard, testState);
	assert(result == count);

	printf("\nPassed\n");

	return 0;
}