#include <iostream>
#include "BlackjackRules.h"
#include "PokerRules.h"

int main(int argc, char * argv[]){

	//This will be the hand to check if it
	//is a winning hand or not
	vector <Card> hand;
	
	if(argc > 1 && *argv[1] == '0'){
		cout << "\n******* Welcome to Blackjack Rules *******\n\n";

		//Adds cards to hand
		hand.push_back(Card(9, 2));	
		hand.push_back(Card(3, 3));	
		hand.push_back(Card(4, 1));	

		//BlackjackRule blackjack(hand, 3);
		
		AnalyzeHand * blackjack = new BlackjackRules(hand);

		cout << "We are checking the Hand: \n";
		cout << "\t" << (*blackjack).toString() << endl;

		cout << "\n...Checking\n\n";

		//This will check if the hand is winning
		bool won = (*blackjack).isWon();

		//Prints out if the hand is a winning hand
		if(won){
			cout << "This is a Winning hand!" << endl;
		} else {
			cout << "This ia a Losing hand!" << endl;
		}

	} else if( argc > 1 && *argv[1] == '1'){
		cout << "\n******* Welcome to Poker Rules *******\n\n";
			
		hand.push_back(Card(0, 1));	
		hand.push_back(Card(12, 2));	
		hand.push_back(Card(11, 1));		
		hand.push_back(Card(10, 3));	
		hand.push_back(Card(9, 1));	

		AnalyzeHand * poker = new PokerRules(hand);

		cout << "We are checking the Hand: \n";
		cout << "\t" << (*poker).toString() << endl;

		cout << "\n...Checking\n\n";

		//This will check if the hand is winning
		bool won = (*poker).isWon();

		//Prints out if the hand is a winning hand
		if(won){
			cout << "This is a Winning hand!" << endl;
		} else {
			cout << "This ia a Losing hand!" << endl;
		}


	} else {
		cout << "Re-run the program with a argument passed in! Either 1 or 0!" << endl;
	}
}
