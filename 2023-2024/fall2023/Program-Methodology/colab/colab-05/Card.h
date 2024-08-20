#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card {
	private:
		static string faceNames[13];
		static string suitNames[4];

		enum Face {Ace, Deuce, Three, Four,
			   Five, Six, Seven, Eight,
			   Nine, Ten, Jack, Queen, King};

		enum Suit {Hearts, Diamonds, Clubs, Spades};

		Face f;
		Suit s;

	public:
		Card(){
			f = Ace;
			s = Hearts;
		}

		Card(int face, int suit){
			f = static_cast<Face>(face);
			s = static_cast<Suit>(suit);	
		}
		
		//Returns face
		int getFace();

		//converts a card to a string
		string toString();

		//Returns suit
		int getSuit();
};


#endif
