#ifndef CIPHERADVANCED_H
#define CIPHERADVANCED_H
#include "Cipher.h"
#include "Queue.h"

//Used to read in from the dictonary
#include <fstream>

#include <vector>
class CipherAdvanced : public Cipher {	
	private:
		static vector <string> unscrambledMessages;
		static vector <string> usedKeys;	
		
	public:

		CipherAdvanced(){
							
		}

		static void runMenu();
		static void unknownMultiWordScramble(string scrambledMessage);	
		static bool hasThreeLettersInARow(string);
		static bool madeOfWords(string);
		static void printList();	
};

#endif
