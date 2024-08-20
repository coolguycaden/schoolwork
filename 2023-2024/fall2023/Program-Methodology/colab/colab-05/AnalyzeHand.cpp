#include "AnalyzeHand.h"

//Returns the hand as a formatted list, following
//the below format:
// [Ace of Hearts, Ace of Spades, Ace of Diamonds]
string AnalyzeHand::toString(){
	string format = "[";
	
	for(int x = 0; x < static_cast<int>(hand.size()); x++){
		if(x < static_cast<int>(hand.size() - 1)){
			format += (hand[x].toString() + ", ");
		} else {
			//Removes the comma, as this will
			//be the last item in the list
			format += hand[x].toString();
		}
	}

	//Ends the formatting
	format += "]";

	return format;
}
