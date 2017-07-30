#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>



int checkSmithyCard(int p, int handP, struct gameState *post) {
	struct gameState pre;
	post->whoseTurn = p;
	memcpy(&pre, post, sizeof(struct gameState));
	
	int choice1 = floor(Random() * 2);
	int choice2 = 0;
	int choice3 = 0;

	int check = StewardRe(post, choice1, 0, 0, handP);
	

	if (choice1 == 1){
    //+2 cards
    drawCard(p, &pre);
    drawCard(p, &pre);
  }
  else if (choice1 == 2){
    //+2 coins
    pre.coins = pre.coins + 3;		//Bug: +3 coins
  }
  else{
    //trash 2 cards in hand
    discardCard(choice2, p, &pre, 1);
    discardCard(choice3, p, &pre, 1);
  }

  //discard card from hand
  discardCard(handP, p, &pre, 0);
  

	
	if(memcmp(&pre, post, sizeof(struct gameState)) == 0) {
		printf("Test passed!\n");
		return 0;
	}
	else {
		printf("Test failed!\n");
		return 1;
	}
}


int main() {

	//Much of this code comes from the testDrawCard.c implementation
	int i, n, r, p, j, deckCount, discardCount, handCount;
	int goodResult = 0;	//counters for test results
	int badResult = 0;
	int testResult = 0;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing Steward.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
	
	//Set number of players
    p = floor(Random() * 2);
	//printf("p = %d\n", p);
    G.deckCount[p] = floor(Random() * MAX_DECK);

    G.discardCount[p] = floor(Random() * MAX_DECK);

    G.handCount[p] = floor(Random() * MAX_HAND);
	
	G.playedCardCount = floor(Random() * 10);

	int handPos = floor(Random() * G.handCount[p]);
	testResult = checkSmithyCard(p, handPos, &G);
	if(testResult == 0) {
		goodResult++;
	}
	else {
		badResult++;
	}
  }
  
  printf("Tests passed: %d, Tests failed: %d\n", goodResult, badResult);
  
  return 0;
	
}