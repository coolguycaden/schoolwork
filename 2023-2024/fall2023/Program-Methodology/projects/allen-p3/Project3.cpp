/*
 * Caden Allen
 * CPSC 1070
 *
 *
 *      This program is a new Certified-Plaue Product! This products will allow 
 	you to encrypt and decrypt as much as you desire, with our new patented
	Plaue-Encryption Techology (Revolving Caesar Cipher)!!! Use our 
	state-of-the-art technology to protect your information! Now available
	for only $129999.99 for one use!!! Get your Plaue-Encryption Technology
	today, while supplies last !!!

	(Plaue Products.Co is not liable for any damages caused by misuse of
	 this product or the inability to encrypt or decrypt messages!)
 *
 *
 *
 *
 */



#include "Queue.h"
#include "Cipher.h"
#include "CipherAdvanced.h"
#include <chrono>
using namespace std::chrono;

int main(int argv, char * argc[]){
	auto start = high_resolution_clock::now();
	
	string key;	
	cout << "Type in the word to use as the key: ";
	
	getline(cin, key);
		

	char * keyPtr = &key[0];
	Cipher c(key.length(), keyPtr);
	
	c.runMenu();

	CipherAdvanced::runMenu();	

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<seconds>(stop - start);
	cout << duration.count() << endl;
}
