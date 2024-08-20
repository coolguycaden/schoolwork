#ifndef ANALYZEHAND_H
#define ANALYZEHAND_H

#include "Card.h"
#include <vector>

class AnalyzeHand {
	private:
		//Holds cards to analyze
		vector <Card> hand;

		//Num of cards in hand
		int numOfCards;

	public:
		AnalyzeHand(vector <Card> inputHand){
			for(int x = 0; x < static_cast<int>(inputHand.size()); x++){
				hand.push_back(inputHand[x]);
				numOfCards++;
			}
		}

		//Returns a formatted string of the
		//cards within hand
		string toString();

		virtual bool isWon() = 0;	

};

#endif
