/*
 * Name: Caden Allen
 * Date Submitted: 3/14/2024
 * Assignment Name: Single-Word Anagram Finder
 */
#

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);
/*
int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}
*/
vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

/*
 *  The anagram() function will take a word (string) and a wordlist of all words (vector of strings) and 
 *  builds a dictionary/map where the key is a specific amount of times each letter
 *  occurs in a word and the associated value is a vector of strings containing all words 
 *  using those letters (anagrams).
 */ 


//This makes a map based on the sent in word, the map will be used
//to compare a word from wordlist to the given word
unordered_map<char, int> getCharMap(string word){
	unordered_map<char, int> map;

	for(int x = 0; x < word.size(); x++){ 
		map[word[x]]++;
	}

	return map;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist){
	vector<string> anagrams;	
	unordered_map<char, int> givenWord;
	givenWord = getCharMap(word);
	
	int x = 0;
	while(x < wordlist.size()){
		if(wordlist[x].size() == word.size()){
			
			unordered_map<char, int> comparedWord = getCharMap(wordlist[x]); 
			
			bool isAnagram = true;
			int y = 0;
			while(isAnagram && y <= 255){
				if(givenWord[y] != comparedWord[y]){
					isAnagram = false;
				}
				y++;
			}

			if(isAnagram){
				anagrams.push_back(wordlist[x]);
			}
		}
		x++;
	}

	return anagrams;
}



























