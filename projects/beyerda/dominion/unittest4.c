/*Name: Daniel Beyer
* CS362 - Week 3 Assignment
* Description: Unit test 4 - Tests getCost() Function
* 
*/

#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{

	int testCard, result;

	printf("\n\nUnit Test 4\n\n");
	testCard = 0;
	result = getCost(testCard);
	assert(result == 0);

	//Gold card
	testCard = 6;
	result = getCost(testCard);
	assert(result == 6);

	//Mine card
	testCard = 11;
	result = getCost(testCard);
	assert(result == 5);

	//Council Room card
	testCard = 8;
	result = getCost(testCard);
	assert(result == 5);

	//Province card
	testCard = 3;
	result = getCost(testCard);
	assert(result == 8);

	printf("\nPassed\n");

	return 0;
}