/*
 * Name: Caden Allen
 * Date Submitted: 3/4/2024
 * Lab Section: 001
 * Assignment Name: Spell Checker using Hash Table
 */

#pragma once


#include <functional> //this is for hash function
#include <iostream> //for debug printing
//#include <unistd.h> //using sleep() for debug
//#include <iterator> //used for std::next for the enumeration of the stl list class

#include <string>
#include <vector>
#include <list>
using namespace std;

//Stringset class, do not modify definitions for existing members
class Stringset
{
    private:
        vector<list<string>> table;
        int num_elems;
        int size;
    public:
        Stringset();
        vector<list<string>> getTable() const;
        int getNumElems() const;
        int getSize() const;
        void insert(string word);
        bool find(string word) const;
        void remove(string word);
};
