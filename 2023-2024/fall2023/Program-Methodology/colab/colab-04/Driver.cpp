#include "Card.h"
#include "DeckOfCards.h"
#include <ctime>

int main(int argv, char * arvc[]){
	srand(time(0));

	DeckOfCards d;
	
	cout << (d.dealCard()).toString() << endl;

	d.shuffle();

	d.printDeck();
	
}
