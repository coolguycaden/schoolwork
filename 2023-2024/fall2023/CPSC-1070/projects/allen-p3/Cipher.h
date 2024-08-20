#ifndef CIPHER_H
#define CIPHER_H

#include "Queue.h"

//Used to create a char vector that holds 
//the filtered key (no spaces, nums, punc)
#include <vector>

//Used for the isalpha() function which
//checks for if a charater is non-alphabetic
//And uses tolower() which makes a char lowercase
#include <cctype>

//Used for abs()
#include <cmath>

class Cipher {
	private:
		//This will hold the key filtered for
		//non-alphabetic characters (spaces, nums, punc)
		string filteredKey;
		
		//points to char array
		char * pointerToString;

	public:

		Cipher(){
			filteredKey = "cpsc";
			pointerToString = &filteredKey[0];
		}

		//Allows for the setting of the cipher
		Cipher(int size, char * arrayPtr){
			pointerToString = arrayPtr;
			setCipher(size, arrayPtr);
		}	


		//Simple menu that takes user input
		void runMenu();
	
		//Allows for manual adjustment of cipher	
		void setCipher(int, char *);

		//Returns the cipher
		char * getCipher();

		//Encodes a user input with the stored key
		string encodeMessage(string in);

		//Decodes a user input with stored key
		string decodeMessage(string in);

		//Shifts letters, more extensive commenting in Cipher.cpp
		static char letterShift(char, char, bool);

		string getFilteredKey(){
			return filteredKey;
		}
};

#endif
