#include "Cipher.h"

//Simple menu 
void Cipher::runMenu(){
	
	//Holds user input
	char input;

	//Holds string user whats to encode 
	//or decode
	string in;

	//Contiunues the below loop until true
	bool endLoop = false;

	string result;

	do {
		cout << "\nKey: " << filteredKey << endl;
		cout << "[e] encode with that key " << endl; 
		cout << "[d] decode with that key" << endl;
		cout << "[q] quit " << endl;
		
		cin >> input;
	
		//Takes in user input and runs relevant menu option	
		switch(input){
			case 'e': case 'E':
				cout << "Enter what to encode: ";
				cin >> in;
				result = encodeMessage(in);
				cout << "result: " << result << endl;
				break;

			case 'd': case 'D':
				cout << "Enter what to decode: ";
				cin >> in;
				result = decodeMessage(in);
				cout << "result: " << result << endl;
				break;

			case 'q': case 'Q':
				endLoop = true;
				break;

			default:
				cout << "That is not a valid option, re-enter your choice " << endl;
				break;

		}
		
	} while (!endLoop);
}

//Sets the revolving key
void Cipher::setCipher(int size, char * arrayPtr){
	
	pointerToString = arrayPtr;
	filteredKey = "";
	for(int x = 0; x < size; x++){

		//Filters non-alphabetic characters
		//And forces them to lowercase
		if(isalpha(*(arrayPtr + x))){ 
			filteredKey += tolower((*(arrayPtr + x)));
		}
	}	

}

//Returns the cipher
char * Cipher::getCipher(){
	return pointerToString;
}

//Encodes a sent in string with the revolving key
string Cipher::encodeMessage(string in){
	//This creates a revolving key using
	//filteredKey to create a queue and fill it
	Queue revolvingKey;

	for(int x = 0; x < static_cast<int>(filteredKey.length()); x++){
		revolvingKey.enqueue(filteredKey[x]);
	}




	//Holds the encoded user input
	string encodedMessage;	
	
	//Holds dequeued value
	char shiftLetter;
	
	//encodes user input
	for(int x = 0; x < static_cast<int>(in.length()); x++){
		//Takes first letter of the queue and dequeues
		//it so shiftLetter can have its value
		//Then, requeues the value
		revolvingKey.dequeue(shiftLetter);
		revolvingKey.enqueue(shiftLetter);
		

		//Shifts a letter FORWARD, encrypting it
		encodedMessage += letterShift(in[x], shiftLetter, false); 	
		
	}


	return encodedMessage;
}

//Decodes user input by using the already known key
//to create a revolving key
string Cipher::decodeMessage(string in){
	//holds decoded user input
	string decodedMessage;
	
	//This creates a revolving key using
	//filteredKey to create a queue and fill it
	Queue revolvingKey;

	for(int x = 0; x < static_cast<int>(filteredKey.length()); x++){
		revolvingKey.enqueue(filteredKey[x]);
	}


	//decodes user input
	for(int x = 0; x < static_cast<int>(in.length()); x++){
		//Takes first letter of the queue and dequeues
		//it so shiftLetter can have its value
		//Then, requeues the value
		char shiftLetter;
		revolvingKey.dequeue(shiftLetter);
		revolvingKey.enqueue(shiftLetter);

		//Shifts a letter BACKWARD, hopefully
		//reversing encryption
		decodedMessage += letterShift(in[x], shiftLetter, true); 	
		
	}

	return decodedMessage;
}

//This function will shift the first character, inputLetter, by the
//position of the alphabet of the character keyLetter
//Reverse will determine if the direction of the shift will be a positive
//or negative shift along the alphabet
//
//inputLetter will be a letter of the message to decode or encode
//keyLetter will be a letter of the revolving key
char Cipher::letterShift(char inputLetter, char keyLetter, bool reverse){	
	//Will hold the new letter after shift
	char newLetter;

	//Will hold the amount to shift inputLetter by
	int keyShift;

	//Holds the alphabetical positions of inputLetter
	int positionOfInputLetter;

	//This will be used to shift inputLetter to the
	//character letter
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	if(keyLetter == 'z'){
		return inputLetter;
	}

	//Will check for the position of keyLetter in the alphabet above
	//and then set newLetter to inputLetter + index + 1, thus
	//shifting inputLetter by the alphabetical position of 
	//toShiftBY
	for(int x = 0; x < static_cast<int>(alphabet.length()); x++){
		
		//This will get the position of the alphabet
		//that keyLetter and inputLetter are
		if(alphabet[x] == keyLetter){
			keyShift = x + 1;
		}

		if(alphabet[x] == inputLetter){
			positionOfInputLetter = x + 1;
		}
	}	
	//Subtracts position by shift if reverse is true
	//Relies on my observation of key shifting, hard to explain
	//EXPLANATION AT BOTTOM OF FILE
	if(reverse){
		
		//Checks if inputLetter needs to be shifted at all
		if(keyShift + positionOfInputLetter == 26 && positionOfInputLetter < keyShift){
			return inputLetter;
		}

		//These explained at bottom of file
		if(keyShift < positionOfInputLetter){
			keyShift = abs(positionOfInputLetter - keyShift);
		} else {
			
			keyShift = (positionOfInputLetter - keyShift) + 26;
		}
		
	} else {

		//Sets newLetter to the alphabetical position
		//of the shift
		keyShift = (keyShift + positionOfInputLetter) % 26;
	}

	
	if(keyShift == 0){
		 newLetter = 'z';
	} else {
		newLetter = alphabet[keyShift - 1]; 
	}

	return newLetter;
}

/*
 * Here is my long-winded explanation on how my reverse key-shifting works
 * Put simply, let us take the key 'ghost' and the encoded message 'omaei'
 * First, compare the first key letter with the message, which would be
 * 'g' and 'o', and now take the positions, 7 and 15 respectively in the alphabet
 * Now, if the encoded message's position is greater, simply subtract the two (7 - 15) or 
 * (15 - 7) is fine, but use abs for negative values
 * Now, let us compare 'o' and 'a', for the key and encoded message respectively
 * Their positions are 15 and 1 respectively, so subtract the two THEN subtract that result from
 * 26, order doesn't matter, but use abs for negative values
 */
