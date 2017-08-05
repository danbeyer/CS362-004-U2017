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

	int check = smithyCard(post, handP);

	if(pre.deckCount[p] <= 2) {
			pre.deckCount[p] = pre.discardCount[p] - pre.deckCount[p];
			pre.discardCount[p] = 0;
			pre.playedCardCount += 1;
			pre.handCount[p] += 2;
	}
	else {
		pre.deckCount[p] -= 3;
		pre.handCount[p] += 2;
		pre.playedCardCount += 1;
	}
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

  printf ("Testing Smithy.\n");

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