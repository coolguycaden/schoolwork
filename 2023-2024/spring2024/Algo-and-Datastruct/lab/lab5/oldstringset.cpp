/*
 * Name: Caden Allen
 * Date Submitted: 3/4/2024
 * Lab Section: 001
 * Assignment Name: Spell Checker with Hash Table
 */
#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
	return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
	return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
	return size;
}

void Stringset::insert(string word){
	hash<string> stringHash;
	int insertLocation;
	//cout << "word is " << word << endl;

	if(num_elems == size){
		size = table.size() * 2;
		
		vector<list<string>> newTable;
		newTable.resize(size);
		table.resize(size);
		

		for(int x = 0; x < table.size(); x++){
			if(table[x].size() > 0){
				list<string>::iterator index = table[x].begin();
				insertLocation = stringHash(*(index)) % table.size(); 	
				//cout << "hash for " << *index << " is " << insertLocation << endl;
				newTable[insertLocation] = table[x];
					
			}
		}
		newTable.swap(table);	
		/*
		size = table.size() * 2;
		vector<list<string>> newTable;
		
		//newTable.resize(table.size() * 2);
		//cout << "newtable size: " << newTable.size() << endl;
		for(int x = 0; x < table.size(); x++){
			if(table[x].size() > 0){
				list<string>::iterator index = table[x].begin();
				insertLocation = stringHash(*(index)) % table.size(); 	
				//cout << "changing " << x << " to " << insertLocation << endl;
				table[insertLocation] = table[x];
				list<string> newList;
				table[x] = newList;
			}
			auto index = table[x].begin();
			while(index != table[x].end()){
				newTable[x]
			}
		}
		table.resize(size);
		*/

	}

	insertLocation = stringHash(word) % table.size(); 
	if(word.length() <= 0){
		return;
	}

	if(table[insertLocation].size() == 0) {
		table[insertLocation].push_back(word);
	} else {
		list<string> listAtLocation = table[insertLocation];
		list<string>::iterator temp = listAtLocation.begin();
		int x = 0;
		while(temp != listAtLocation.end() && x != listAtLocation.size() - 1){
			if(*temp == word){
				num_elems--;
				//cout << "here3" << endl;
				return;
			}
			temp++;
			x++;
		}

		if(*temp != word){
			//cout << *temp << " is not " << word << endl;
			table[insertLocation].push_back(word);
		} 
	}
	/*
	cout << "current table: " << endl;
	for(int x = 0; x < table.size(); x++){
		if(table[x].size() > 0){
			auto index = table[x].cbegin();
			cout << "index " << x << ": ";
			while(index != table[x].end()){
				cout << *index << " ";
				index++;
			}
			cout << endl;
		}
	}
	cout << "\n\n";
	*/
	num_elems++;
}

bool Stringset::find(string word) const 
{
	/*cout << "current table: " << endl;
	for(int x = 0; x < table.size(); x++){
		if(table[x].size() > 0){
			auto index = table[x].cbegin();
			cout << "index " << x << ": ";
			while(index != table[x].end()){
				cout << *index << " ";
				index++;
			}
			cout << endl;
		}
	}
	cout << "\n\n";
	*/
	hash<string> stringHash;
	int locationToCheck = stringHash(word) % table.size();

	//cout << "locationToCheck for " << word << " is " << locationToCheck << endl;	
	
	list<string> tempList = table[locationToCheck];
	
	if(tempList.size() == 0){
		//cout << "size is 0" << endl;
		return false;
	}
	
	for(auto index = tempList.cbegin(); index != tempList.cend(); index++){
		//cout << "current word is " << *index << endl;
		if(*index == word){
			return true;
		}
	}

	
	return false;
}

void Stringset::remove(string word)
{
	

	hash<string> stringHash;
	int locationToCheck = stringHash(word) % table.size();

	//list<string> tempList = table[locationToCheck];
	
	if(table[locationToCheck].size() > 0){
		//issue where a single deletion gets multiple words, but 
		//num_elems doesn't decrement the same amount 
		table[locationToCheck].remove(word);
		num_elems--;
	}


}
