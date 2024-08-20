#include "PokerRules.h"

//Returns true if two cards have same
//face value
bool PokerRules::pair(){
		
	//This will hold the face values of
	//the cards in the hand
	int faceArray [cardTotal];
	for(int x = 0; x < cardTotal; x++){
		faceArray[x] = newHand[x].getFace();
	}

	//This will sort the face values in ascending order
	sort(faceArray, faceArray + cardTotal);
	
	//Because the values are sorted numerically, this is
	//an easy way to check if values equal
	for(int x = 0; x < cardTotal - 1; x++){
		if(faceArray[x] == faceArray[x + 1]){
			return true;
		}
	}

	return false;

}

//Checks if a hand has two pairs of same face
//value cards
bool PokerRules::twoPairs(){
	
	//Holds the amount of pairs found
	int pairCount = 0;

	//This will hold the face values of
	//the cards in the hand
	int faceArray [cardTotal];
	for(int x = 0; x < cardTotal; x++){
		faceArray[x] = newHand[x].getFace();
	}

	//This will sort the face values in ascending order
	sort(faceArray, faceArray + cardTotal);
	
	//Because the values are sorted numerically, this is
	//an easy way to check if values equal
	for(int x = 0; x < cardTotal - 1; x++){
		if(faceArray[x] == faceArray[x + 1]){
			pairCount++;
		}
	}

	if(pairCount == 2){
		return true;
	}

	return false;

}

//Checks if a hand has three cards of
//the same face value
bool PokerRules::threeOfAKind(){
	//This will hold the number of the same face
	int sameFace = 1;

	//This will hold the face values of
	//the cards in the hand
	int faceArray [cardTotal];
	for(int x = 0; x < cardTotal; x++){
		faceArray[x] = newHand[x].getFace();
	}

	//This will sort the face values in ascending order
	sort(faceArray, faceArray + cardTotal);
	
	//Because the values are sorted numerically, this is
	//an easy way to check if values equal
	for(int x = 0; x < cardTotal - 1; x++){
		if(faceArray[x] == faceArray[x + 1]){
			sameFace++;
		}
	}
	
	if(sameFace == 3){
		return true;
	}	

	return false;

}

//Checks if a hand has four cards of the
//same face value
bool PokerRules::fourOfAKind(){
	//This will hold the number of the same face
	int sameFace = 1;

	//This will hold the face values of
	//the cards in the hand
	int faceArray [cardTotal];
	for(int x = 0; x < cardTotal; x++){
		faceArray[x] = newHand[x].getFace();
	}

	//This will sort the face values in ascending order
	sort(faceArray, faceArray + cardTotal);
	
	//Because the values are sorted numerically, this is
	//an easy way to check if values equal
	for(int x = 0; x < cardTotal - 1; x++){
		if(faceArray[x] == faceArray[x + 1]){
			sameFace++;
		}
	}
	
	if(sameFace == 4){
		return true;
	}	

	return false;
}

//Returns true if all cards are ordered
//in sequential value
bool PokerRules::straight(){
	//This will hold the face values of
	//the cards in the hand
	int faceArray [cardTotal];
	for(int x = 0; x < cardTotal; x++){
		faceArray[x] = newHand[x].getFace();
	}

	//This will sort the face values in ascending order
	sort(faceArray, faceArray + cardTotal);
	
	int loopStart = 0;

	//Ace (0) is a special card for a straight
	//Ace can either be a high straight, which is 
	//Ace, King, Queen, Jack, Ten
	//Or a low straight
	//Ace, Two, Three, Four, Five
	//This will change the start of the for loop based on if
	//a zero is present and 
	if(faceArray[0] == 0){
		loopStart = 1;
		
		//If an ace is present, there are only 
		//two possible straights, a high
		//or low ace straight
		//the next card must be duece or ten
		if(faceArray[1] != 1 && faceArray[1] != 9){
			return false;
		}
	}
	
	
	//Because the values are sorted numerically, this is
	//an easy way to check if values are sequential in order
	//( 1 by 1 )
	for(int x = loopStart; x < cardTotal - 1; x++){
		if(faceArray[x] + 1 != faceArray[x + 1]){
			return false;
		}
	}
	
	return true;
}

//Return true if all cards have the same suit
bool PokerRules::flush(){
	for(int x = 0; x < cardTotal - 1; x++){
		if(newHand[x].getSuit() != newHand[x + 1].getSuit()){
			return false;
		}	
	}

	return true;
}

//Check if a handd is winning
bool PokerRules::isWon(){
	if(pair() || twoPairs() || threeOfAKind() || fourOfAKind() || straight() || flush()){
		return true;
	}

	return false;
}
