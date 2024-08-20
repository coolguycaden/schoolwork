#ifndef POKERRULES_H
#define POKERRULES_H

#include "AnalyzeHand.h"
#include <algorithm> // Used for sort()
class PokerRules : public AnalyzeHand {
	private:
		vector <Card> newHand;
		int cardTotal;

	public:
		PokerRules(vector <Card> inHand) : AnalyzeHand(inHand) {
			for(int x = 0; x < static_cast<int>(inHand.size()); x++){
				newHand.push_back(inHand[x]);
			}
			cardTotal = inHand.size();
		}

		//Returns true if two cards within the 
		//same hand have the same value
		bool pair();

		//returns true if two pairs are found
		bool twoPairs();
			
		//Returns true if there are three cards of
		//the same face value
		bool threeOfAKind();

		//Returns true if there are four cards 
		//of the same face value
		bool fourOfAKind();

		//Returns true if there are five cards in
		//sequential value order
		bool straight();

		//Returns true if all 5 cards
		//are all of the same suit
		bool flush();

		//Determines if this hand wins
		virtual bool isWon();
};

#endif
