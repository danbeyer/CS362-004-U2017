/*Name: Daniel Beyer
* CS362 - Week 3 Assignment
* Description: Unit test 2 - Tests isGameOver() Function
* 
*/

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{

	//Unit test to test isGameOver() function, checks status of supply piles and provinces, then checks result 
	printf("\n\nUnit Test 2\n\n");
	int i, result;
	struct gameState *testState = newGame();

	
	testState->supplyCount[province] = 0;	//Ending conditions = no more provinces

	result = isGameOver(testState);
	assert(result = 1);
	
	//maintain provinces
	testState->supplyCount[province] = 5;		

	//set 3 supply piles to empty, ending conditions met
	for (i = 0; i < 25; i++) 
	{
		if (i == 5)
		{
			testState->supplyCount[i] = 0;
		}
		else if (i == 10)
		{
			testState->supplyCount[i] = 0;
		}
		else if (i == 15)
		{
			testState->supplyCount[i] = 0;
		}
		else
		{
			testState->supplyCount[i] = i;
		}
	}

	result = isGameOver(testState);
	assert(result == 1);

	
	for (i = 5; i <= 15; i++)
	{
		testState->supplyCount[i] = i;		//making sure no supply piles are empty now
	}

	//game does not end
	result = isGameOver(testState);
	assert(result == 0);

	printf("\nPassed\n");

	return 0;	
}