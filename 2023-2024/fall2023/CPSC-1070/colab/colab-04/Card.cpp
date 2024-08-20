#include "Card.h"

string Card::faceNames [13] = {"Ace", "Deuce", "Three", "Four",
				      "Five", "Six", "Seven", "Eight",
				      "Nine", "Ten", "Jack", "Queen", "King"};

string Card::suitNames [4] = {"Hearts", "Diamonds", "Clubs","Spades"};


//Returns a Card as a string
string Card::toString(){
	string format = "" + faceNames[f - 1] + " of " + suitNames[s - 1];
	return format;	
}
