#include "CipherAdvanced.h"

vector <string> CipherAdvanced::unscrambledMessages;
vector <string> CipherAdvanced::usedKeys;

void CipherAdvanced::runMenu(){
	string scrambled;
	cout << "Type in the scrambled word: ";
	cin >> scrambled;

	unknownMultiWordScramble(scrambled);
}

void CipherAdvanced::unknownMultiWordScramble(string scrambledMessage){
		

	//Holds the dictionary copied from the computer	
	ifstream dict("/usr/share/dict/american-english");
	
	//Holds a word from the dictionary
	string word;

	//Holds unscrambled word 
	string unscrambled;


	
	Cipher dictWord;

	while(getline(dict, word) ){//&& count < 50){
		char * beginningKey = &word[0];
		if(word.length() >= 3){	
			dictWord.setCipher(word.length(), beginningKey); 
			unscrambled = dictWord.decodeMessage(scrambledMessage);
			if(madeOfWords(unscrambled)){
				unscrambledMessages.push_back(unscrambled);
				usedKeys.push_back(dictWord.getFilteredKey());
			}
				
		}
			
	}

	printList();	
}

void CipherAdvanced::printList(){
	cout << "message\tkey\n\n";
	
	for(int x = 0; x < usedKeys.size(); x++){
		cout << unscrambledMessages[x] << " " << usedKeys[x] << endl;
	}	
}
/*
bool isAVowel(char letter){
	switch(letter){
		case 'a': case 'A':
		case 'e': case 'E':
		case 'i': case 'I':
		case 'o': case 'O':
		case 'u': case 'U':
		case 'y': case 'Y':
			return true;
		default:
			return false;
	
	};

	return false;
}
*/


//There exists no non-hyphenated word with 3 of the same
//letters in a row, and this function checks that
bool CipherAdvanced::hasThreeLettersInARow(string substring){
	if((substring[0] == substring[1]) && (substring[1] == substring[2])){
		return true;
	}
	return false;
}

//Checks if an unscrambled message is made of words
bool CipherAdvanced::madeOfWords(string unscrambled){
	
	//This will be the maximum amont of words
	//the string could have if each word is 3 letters 
	//long
	//int maximumWords =  (unscrambled.length() % 3) + (unscrambled.length() / 3);

	//Makes an array that will hold substrings
	string substringOfUnscrambled; 

	string wordstogether;

	for(int x = 0; x < static_cast<int>(unscrambled.length()) - 2; x++){
		if(hasThreeLettersInARow(unscrambled.substr(x,3))){
			return false;
		}
	}
	return true;
}

