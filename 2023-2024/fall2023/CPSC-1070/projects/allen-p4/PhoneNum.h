// Caden Allen
// CPSC 1070
// Project 4
// Decmember 4, 2023

#ifndef PHONENUM_H
#define PHONENUM_H

#include <stdio.h> // used for output and input
#include <stdlib.h> // used for file reading
#include <string.h> // used for strlen
#include <ctype.h> // used for isalnum

// MORE VERBOSE COMMENTING IN .C FILE !!!!

//This will take a line from the in file (input)
//and do conversion depending on the type 
//and output the result to the out file (output)
void conversionT9(FILE * in, FILE * out, char type);

//Turns a line of T9 key presses into
//the word equivalent
char * toWord(char * digits);

//Returns the letter equivalent
//of a T9 digit set sent in
//Like '222' being 'c'
//because 2 is the digit, and 3 is the 
//amount of 2s appearing
char toLetter(char digit, int length);

//Turns a word into T9 key presses
char * toDigits(char * word);

//Takes an individual letter to turn
//into T9 key presses
char * toDigit(char letter);

//This is the extra credit function,
//which finds textonyms given a word
void textonymFind(char * word);

//Helper function for textonymFind()
int mostInARow(char letter);


//This gets a line of text from an
//input file ( in )
char * getNextChars(FILE * in);	

#endif
