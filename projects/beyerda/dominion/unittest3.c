/*Name: Daniel Beyer
* CS362 - Week 3 Assignment
* Description: Unit test 3 - Tests buyCard() Function
* 
*/

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



int main(){
	int fail = 0;
	// Initialize game and cards.
	struct gameState g;
	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,
						mine,ambassador,outpost,baron,tribute};
	
	// Pick a random seed.					
	int randomSeed = 60;
	
	// Initialize game.
	initializeGame(2, k, randomSeed, &g);
	
	printf("\n\nUnit Test 3\n\n");
	
	// Player 1 draws.
	printf("Testing Player 1 buying:\n");
	int checkBuy = buyCard(1, &g);
	if(checkBuy == 0) {
		printf("Test 1 Passed\n");
	}
	else if(checkBuy != 0) {
		printf("Test 1 Failed\n");
		fail = 1;
	}
	
	int checkBuy2 = buyCard(100, &g);
	if(checkBuy == 0) {
		printf("Test 2 Passed\n");
	}
	else if(checkBuy != 0) {
		printf("Test 2 Failed. Card not valid\n");
		fail = 1;
	}
	
	// End turn.
	endTurn(&g);
	
	// Player 2 draws.
	printf("Testing Player 2 buying:\n");
	int checkBuy3 = buyCard(1, &g);
	if(checkBuy == 0) {
		printf("Test 3 Passed\n");
	}
	else if(checkBuy != 0) {
		printf("Test 3 Failed\n");
		fail = 1;
	}
	
	int checkBuy4 = buyCard(1, &g);

	if(checkBuy == 0) {
		printf("Test 4 Passed\n");
	}
	else if(checkBuy != 0) {
		printf("Test 4 Failed. Not enough money\n");
		fail = 1;
	}
	
	if(!fail) {
		printf("\nPassed\n");
	}
	
	
	
	return 0;
}