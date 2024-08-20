/*
 * Name: Caden Allen
 * Date Submitted: 3/4/2024
 * Lab Section: 001
 * Assignment Name: Spell Checker Using Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 #include <cmath> //used for abs() for string len comparison

 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
/*
int main()
{
	cout << "Enter filename: " ;
	string filename;
	cin >> filename;

	Stringset wordlist;
	
	loadStringset(wordlist, filename);
	//spellcheck(wordlist, "hi");

	testStringset(wordlist);
	return 0;
}
*/
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string>> t = words.getTable();
                int numWords = words.getNumElems();
		//int total = 0;
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
		    	//total++;
                    }
                }
		//cout << "Totals: " << total << endl;
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 }
 
 void loadStringset(Stringset& words, string filename){
 
	ifstream file;
	file.open(filename);

	string line;
	while(getline(file, line)){
		words.insert(line);

	}

 }
 
 vector<string> spellcheck(const Stringset& words, string word){
 	vector<string> oneLetterDifference;
	vector<list<string>> table = words.getTable();
	
	int total = 0;
	int length = 0;
	while(length < words.getSize()){
		if(table[length].size() > 0){
			auto index = table[length].cbegin();
			//cout << "index " << length << ": ";
			while(index != table[length].end()){
				//cout << *index << " ";
				string tempWord = *index;
				int lettersOff = 0;
				for(int x = 0; x < tempWord.length(); x++){
					if(tempWord[x] != word[x]){
						lettersOff++;
					}
				}
				
				int len = tempWord.length() - word.length();
				len = abs(len);
				if(lettersOff <= 1 && tempWord.length() > 0 && tempWord != word){
					if(len == 0 && lettersOff <= 1){
						oneLetterDifference.push_back(tempWord);
					} 
					
				}
	
				index++;	
				total++;
			}
				
			//cout << "." << endl;
		}

		length++;
	}
	/*
	cout << "word was " << word << endl;
	cout << "list was: " << endl;
	for(int x = 0; x < oneLetterDifference.size(); x++){
		cout << oneLetterDifference[x] << endl;
	}*/
	//cout << "\n\n";
	//cout << "total is " << total << endl;
	return oneLetterDifference;
 }















