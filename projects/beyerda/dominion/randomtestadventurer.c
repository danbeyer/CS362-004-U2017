#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>


int checkAdventureCard(int p, struct gameState *post) {
	struct gameState pre;
	post->whoseTurn = p;
	memcpy(&pre, post, sizeof(struct gameState));

	int check;
	

	check = AdventurerRe(post);

	int treasureCards = 0;
	int drawnCard;
	int tempHand[MAX_HAND];
	int i=0;

	
	while(treasureCards < 2) {

		drawCard(p,&pre);
		drawnCard = pre.hand[p][pre.handCount[p] - 1];
		if(drawnCard == copper || drawnCard == silver || drawnCard == gold) {
			treasureCards += 2;
		}
		else {
			pre.handCount[p]--;
		}
		
	}

	while(i-1 >=0) {
		pre.discard[p][pre.discardCount[p]++] = tempHand[i-1];
		i--;
	}
	//Test pre and post game states
	if(memcmp(&pre, post, sizeof(struct gameState)) == 0) {
		printf("Test passed!");
		return 0;
	}
	else {
		printf("Test failed!");
		return 1;
	}

}

int main() {
	
	//Much of this code comes from the testDrawCard.c implementation
	int i, n, r, p, j, deckCount, discardCount, handCount, treasureCount, treasureLocation;
	int goodResult = 0;	//counters for test results
	int badResult = 0;
	int testResult = 0;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("Testing Adventurer.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
	
	//Set number of players
    p = floor(Random() * 2);
	printf("p = %d\n", p);
    G.deckCount[p] = floor(Random() * MAX_DECK);

    G.discardCount[p] = floor(Random() * MAX_DECK);

    G.handCount[p] = floor(Random() * MAX_HAND);
	
	//set random cards
	for(j=0; j < G.deckCount[p]; j++) {
    	G.deck[p][j] = floor(Random() * 23);
    }
    for(j=0; j < G.discardCount[p]; j++) {
    	G.discard[p][j] = floor(Random() * 23);
    }
	//treasureCount = floor(Random() * 10)+2;		//Set at least 2 treasure cards
	//treasureLocation = floor(Random() * G.deckCount[p]);
	//G.deck[p][treasureLocation] = copper;
	
	testResult = checkAdventureCard(p, &G);
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