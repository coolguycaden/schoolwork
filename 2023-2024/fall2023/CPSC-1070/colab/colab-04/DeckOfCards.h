#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"
#include <vector>
#include <cmath>

class DeckOfCards{
	private:
		vector <Card> deck;
		int currentCard;

		
		
	
	public:
		DeckOfCards(){
			for(int x = 1; x < 14; x++){
				for(int y = 1; y < 5; y++){
					Card * newCard = new Card(x, y);
					deck.push_back(*newCard);
					delete newCard;
				}
			}
		}

		//Returns next available card
		Card dealCard();

		//Checks if there are cards left to deal
		bool moreCards();

		//Shuffles the deck
		void shuffle();


		//prints the deck
		void printDeck();

		//swaps two values
		void swap(Card&, Card&);
};	

#endif
