#include "BlackjackRules.h"

//Returns true if the sum of cards (their values)
//is less than 21, else, false
bool BlackjackRules::isWon(){

	//This will hold the total
	//value of the hand
	int total = 0;

	for(int x = 0; x < static_cast<int>(newHand.size()); x++){
		total += (newHand[x].getFace() + 1);
	}
	
	return (total < 21);
}
