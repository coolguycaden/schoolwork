// Caden Allen
// CPSC 1070
// Project 4
// December 4, 2023

#include "PhoneNum.h"

//This function will call all other functions
//type determines whether the conversion is FROM digits or letters
//if type = 'd', than the conversion is from digits
//else, the conversion is from letters
void conversionT9(FILE * in, FILE * out, char type){	

	if (type == 'd') {
		
		//This will store a line of text
		char * line = getNextChars(in);
		
		//This will store the decoded text
		char * decodedWord = NULL;
		
		//This will loop through lines of the input file
		//decode the digits into letters, and add the completely
		//decoded word into the output file
		while(line != NULL){
			
			//printf("line to be decoded: %s \n", line);
			
			if(line != NULL){
				decodedWord = toWord(line);
				//printf("decoded word is %s\n\n", decodedWord);
				
				//This strips the trailing newline character from
				//the fgets
				if(decodedWord[strlen(decodedWord) - 1] == '\n'){
					decodedWord[strlen(decodedWord) - 1] = '\0';
				}
				
				//variable for 
				//for loop
				int c;

				//Adds decodedWord to output file
				//character by character
				for(c = 0; c < strlen(decodedWord); c++){
					//This will hold the ASCII value of decodedWord[c]
					int letterToAdd = decodedWord[c];

					//This checks if letterToAdd is an alphanumeric character
					if(isalnum(letterToAdd) != 0){

						//adds the character to the output file
						fputc(letterToAdd, out);
					}
				}	
				//Adds a new line to space out words
				//in the output file	
				fprintf(out, "\n");

				//This frees the dynamic memory created by 
				//toWord() and getNextChars()	
				free(decodedWord);
				free(line);
				
				line = NULL;
				decodedWord = NULL;
			
			}
			
			//This gets the next line of text
			//from the input file
			line = getNextChars(in);

		}

	} else {

		//This will store a line of text
		char * line = getNextChars(in);
		
		//This stores the result of the toDigits function
		char * encodedWord = NULL;

		//This will loop through lines of the input file
		//encode the letters into digits and add the completely
		//decoded word into the output file
		while(line != NULL){
			
			//This gets the line of text from input file
			//which will be a word or number to 

			if(line != NULL){
				encodedWord = toDigits(line);
				
				//variable for 
				//for loop
				int c;

				//Adds decodedWord to output file
				//character by character
				for(c = 0; c < strlen(encodedWord); c++){
					//This will hold the ASCII value of decodedWord[c]
					int letterToAdd = encodedWord[c];

					//This checks if letterToAdd is an alphanumeric character
					if(isalnum(letterToAdd) != 0 || letterToAdd == 45){

						//adds the character to the output file
						fputc(letterToAdd, out);
					}
				}
				
				//Adds a new line to space out words
				//in the output file	
				//fprintf(out, "\n");
				
				
				//This frees the dynamic memory created by 
				//toDigits() and getNextChars()	
				
				free(encodedWord);	
				free(line);
				
				line = NULL;
				encodedWord = NULL;
			
			}
			
			line = getNextChars(in);
		}


	}

}

//Takes a set of digits and returns a letter
char toLetter(char digit, int length){
	
	//Returns the proper amount of a number corresponding
	//with T9 presses
	switch(digit){
		case '1':
			break;
		
		case '2':
			if(length == 1){
				return 'a';
			}
			if(length == 2){
				return 'b';
			}
			if(length == 3){
				return 'c';
			}
			break;

		case '3':
			if(length == 1){
				return 'd';
			}
			if(length == 2){
				return 'e';
			}
			if(length == 3){
				return 'f';
			}	
			break;

		case '4':
			if(length == 1){
				return 'g';
			}
			if(length == 2){
				return 'h';
			}
			if(length == 3){
				return 'i';
			}	
			break;

		case '5':
			if(length == 1){
				return 'j';
			}
			if(length == 2){
				return 'k';
			}
			if(length == 3){
				return 'l';
			}	
			break;

		case '6':
			if(length == 1){
				return 'm';
			}
			if(length == 2){
				return 'n';
			}
			if(length == 3){
				return 'o';
			}	
			break;

		case '7':
			if(length == 1){
				return 'p';
			}
			if(length == 2){
				return 'q';
			}
			if(length == 3){
				return 'r';
			}	
			if(length == 4){
				return 's';
			}
			break;

		case '8':
			if(length == 1){
				return 't';
			}
			if(length == 2){
				return 'u';
			}
			if(length == 3){
				return 'v';
			}	
			break;

		case '9':
			if(length == 1){
				return 'w';
			}
			if(length == 2){
				return 'x';
			}
			if(length == 3){
				return 'y';
			}
			if(length == 4){
				return 'z';
			};
			break;

		default:
			break;
	}
	//puts("return wrong");
	return '_';
}

//Takes in a set of digits and turns it into the
//alphabetical equivalnet according to the T9 system
char * toWord(char * digits){	
	
	//This is the counter for the loop
	int index;

	//This will indicate the last encountered hyphen index, or the
	//beginning of the word
	int lastHyphenIndex = 0;

	// dynamically allocate word
	// length based on letters
	// This assumes that the only character
	// the delimiter 
	int letters = 1;
	
	//This declares initial space for a singular letter, newline plus the delimiter
	char * decodedWord = (char *) malloc(sizeof(char) * letters);
	
	
	//Looks for a hyphen, meaning there are
	//key presses, no hyphen means
	//that the entered digits are
	//meant to be numbers, so they do not need
	//to be decoded
	if(strchr(digits, '-') == NULL ){
		for(index = 0; index < strlen(digits); index++){
			decodedWord[index] = digits[index];
			letters++;
			decodedWord = (char *) realloc(decodedWord, sizeof(char) * letters);
		}

		return decodedWord;
	}



	//This will loop through the sent in digits and split them into substrings
	//based on an encountered hyphen
	//
	//For example, a sent in digits of 222-2-4
	//will be split into 222 and 2 and 4, and letters will be returned
	//based on that substrings
	for(index = 0; index < strlen(digits); index++){
		if(digits[index + 1] == '-' || digits[index + 1] == '\0'){
			//Holds the length of a substring
			//until a hyphen is encountered
			int substringLen;
			

			//This will find how long substringLen should be 
			if(letters == 1){
				substringLen = index - lastHyphenIndex + 1;
			} else {
				substringLen = index - lastHyphenIndex;
			}
			
			//Increases decodedWord memory for another letter to be added
			decodedWord = (char *) realloc(decodedWord, sizeof(char) * letters);
			
			//This updates the position of the
			//hyphen
			lastHyphenIndex = index + 1; 
		
			//This adds the letter to decodedWord, leaving room for
			//the null character
			decodedWord[letters - 1] = toLetter(digits[index], substringLen);
			
			//Increase the letters found so far
			letters++;
		}
	}
	

	return decodedWord;
}

//Takes in a letter and return the T9
//key presses necessary to create that letter
char * toDigit(char letter){
	switch(letter){
		case 'a':
			return "2-";
		case 'b':
			return "22-";
		case 'c':
			return "222-";
		case 'd':
			return "3-";
		case 'e':
			return "33-";
		case 'f':
			return "333-";
		case 'g':
			return "4-";
		case 'h':
			return "44-";
		case 'i':
			return "444-";
		case 'j':
			return "5-";
		case 'k':
			return "55-";
		case 'l':
			return "555-";
		case 'm':
			return "6-";
		case 'n':
			return "66-";
		case 'o':
			return "666-";
		case 'p':
			return "7-";
		case 'q':
			return "77-";
		case 'r':
			return "777-";
		case 's':
			return "7777-";
		case 't':
			return "8-";
		case 'u':
			return "88-";
		case 'v':
			return "888-";
		case 'w':
			return "9-";
		case 'x':
			return "99-";
		case 'y':
			return "999-";
		case 'z':
			return "9999-";
		default:
			break;
	}

	return "";
}

//This will turn the sent in word into digits
//according to the T9 key push system
char * toDigits(char * word){
	//Holds size of encoededWord
	//used for dynamic memory
	int length = 1;
	
	//This will hold the word sent in,
	//but turned into digits
	//has initial space for the '\0' 
	char * encodedWord = (char *) malloc(sizeof(char) * length);
	
	//This is the variable for the
	//for loop
	int index;

	//This will check if the passed in word is actually
	//a number, and if so, will return that number as a 
	//dynamically allocated string
	if(isdigit(word[0]) != 0){
		for(index = 0; index < strlen(word); index++){
			encodedWord[index] = word[index];
			length++;
			encodedWord = (char *) realloc(encodedWord, sizeof(char) * length);
		}

		return encodedWord;
	}


	for(index = 0; index < strlen(word); index++){
		//finds how much length needs to increase to
		//accomodate the T9 key presses
		int neededLength = strlen(toDigit(word[index]));

		length += neededLength;
		
		//Adjusts memory allocation as needed to hold
		//T9 Key presses
		encodedWord = (char *) realloc(encodedWord, sizeof(char) * length);
		
		//This is the normal operation, turning an
		//alphabetical character into key presses
		strcat(encodedWord, toDigit(word[index]));
		
		printf("word is now %s\n", encodedWord);
	}
	
	//encodedWord = (char *) realloc(encodedWord, sizeof(char) * length + 1);
	//encodedWord[length - 1] = '\0';
	
	//puts("alloc");
	return encodedWord;
}

//This will return the next line of an input file
char * getNextChars(FILE * in){
	
	//This will determine the size of the 
	//dynamic memory allocation
	int length = 1;

	//This will hold a line from the input file
	char * line = (char *) malloc(sizeof(char) * length);
	
	//This reads in character by character from file until
	//the end or newline character is found
	while(!feof(in)){
		printf("length is %ld", strlen(line) + 1);
		char charToAdd = fgetc(in);
		if(charToAdd == 10){
			line[length - 1] = '\0';
			printf("word is %s\n", line);
			length = 1;
			return line;
		}
		puts("yeah");
		length++;
		line = (char *) realloc(line, sizeof(char) * length);
		line[length - 2] = charToAdd;
	}
	//length++;
	//line = (char *) realloc(line, sizeof(char) * length);
	//line[length - 1] = '\0';
	return line;
	
	//This reads in the word from the file
	/*if(fgets(line, 5, in) != NULL){
		//This strips the trailing newline character 
		//from fgets()
		line[strlen(line) - 1] = '\0';
	//	int length = strlen(line) + 1;
	//	line = (char *) realloc(line, sizeof(char) * length + 1);	
		return line;
	} else {
		//This signifies that the end of the
		//file has been reached
		return NULL;
	}*/
	return NULL;

}
