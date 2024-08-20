#ifndef BLACKJACKRULES_H
#define BLACKJACKRULES_H

#include "AnalyzeHand.h"

class BlackjackRules : public AnalyzeHand {	
	private:
		vector <Card> newHand;
		int cardTotal;
	
	public:
		BlackjackRules(vector <Card> inputHand) : AnalyzeHand(inputHand) {
			for(int x = 0; x < static_cast<int>(inputHand.size()); x++){
				newHand.push_back(inputHand[x]);
			}
			cardTotal = inputHand.size();	
		}	

		virtual bool isWon();	

};


#endif
