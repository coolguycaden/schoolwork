#include "DeckOfCards.h"

//Checks if there are cards that can be deal.t
//Returns false if there are no more cards
bool DeckOfCards::moreCards(){
	if(deck.size() > 0){
		return true;
	}

	return false;
}

//Deals a card and prints out if a card cannot be printed
Card DeckOfCards::dealCard(){

	//Prints if no more cards can be dealt
	if(!moreCards()){
		cout << "There are no more cards to deal." << endl;
		Card * empty = NULL;
		return *empty; 
	}
	
	Card cardToDeal;

	cardToDeal = deck[0];

	deck.erase(deck.begin());

	return cardToDeal;
}

//Swaps values of two cards
void DeckOfCards::swap(Card &firstCard, Card &secondCard){
	Card temp = firstCard;

	firstCard = secondCard;
	secondCard = temp;
}

//Shuffles the deck, iterates through the deck
//and replaces that card with the index of a random card
void DeckOfCards::shuffle(){
	for(int x = 0; x < static_cast<int>(deck.size()); x++){
		int randomNum = rand() % deck.size() + 1;
	  	swap(deck[x], deck[randomNum]);
	}
}


//Prints the deck out for debugging
void DeckOfCards::printDeck(){
	for(int x = 0; x < static_cast<int>(deck.size()); x++){
		cout << x << " is: " << (deck[x].toString()) << endl;
	}
}
