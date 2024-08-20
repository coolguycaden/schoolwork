#include "Card.h"

string Card::faceNames [13] = {"Ace", "Deuce", "Three", "Four",
				      "Five", "Six", "Seven", "Eight",
				      "Nine", "Ten", "Jack", "Queen", "King"};

string Card::suitNames [4] = {"Hearts", "Diamonds", "Clubs","Spades"};


//Returns a Card as a string
string Card::toString(){
	string format = "" + faceNames[f] + " of " + suitNames[s];
	return format;	
}

//Returns the numeric value of face
int Card::getFace(){
	return static_cast<int>(f);
}

//Returns numeric value of suit
int Card::getSuit(){
	return static_cast<int>(s);
}
