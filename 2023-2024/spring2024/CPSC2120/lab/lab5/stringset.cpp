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
	size = table.size();

	if(num_elems == table.size()){
		size = table.size() * 2;
		vector<list<string>> newTable;
		newTable.resize(size);

		for(int x = 0; x < table.size(); x++){
			list<string>::iterator index = table[x].begin();
			for(; index != table[x].end(); index++){
				insertLocation = stringHash(*index) % newTable.size();
				newTable[insertLocation].push_back(*index);
			}
		}
		newTable.swap(table);
	}

	insertLocation = stringHash(word) % table.size(); 
	if(find(word)){
		return;
	}

	table[insertLocation].push_back(word);
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

	list<string> tempList = table[locationToCheck];
	
	if(tempList.size() == 0){
		return false;
	}
	
	for(auto index = tempList.cbegin(); index != tempList.cend(); index++){
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

	if(table[locationToCheck].size() > 0){
		table[locationToCheck].remove(word);
		num_elems--;
	}


}
