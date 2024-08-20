/*
 * Name: Caden Allen
 * Date Submitted: 1/29/2023
 * Lab Section: 001
 * Assignment Name: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>


class List{

	private:
		Node<T> * start; //pointer to the first node in this list
		int mySize;  //size (or length) of this list

	public:
		List();
		~List();
		int size();
		bool empty();
		void insertStart(T);
		void insertEnd(T);
		void insertAt(T, int);
		void removeStart();
		void removeEnd();
		void removeAt(int);
		T getFirst();
		T getLast();
		T getAt(int);
		int find(T);

		//Print the name and this list's size and values to stdout
		//This function is already implemented (no need to change it)
		void print(string name){
			cout << name << ": ";
			cout << "size = " << size();
			cout << ", values = ";
			Node<T> * iterator = start;
			while(iterator != nullptr){
				cout << iterator->value << ' ';
				iterator = iterator->next;
			}
			cout << endl;
		}

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
	start = NULL;
	mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
	int deleted = 0;
	
	//print("list now: ");
	if(mySize == 1){
		delete start;
	} else {

		for(int x = 0; x < mySize; x++){
			Node<T> * temp = start;
			start = start->next;
			delete temp; 
			deleted++;
		}
	}
}

//Return the size of this list
template <class T>
int List<T>::size(){
	return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
	if(mySize == 0){
		return true;
	}
	return false;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
	//cout << "inserted " << value << endl;
	Node<T> * newNode = new Node<T>(value);
	Node<T> * tempHead = start;
	start = newNode;
	start->next = tempHead;
	mySize++;
	//print("list after: ");
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
	if(mySize == 0){
		start = new Node<T>(value);
		//cout << start->value << " was added1 " << endl;
	} else {
		Node<T> * newNode = new Node<T>(value);
		Node<T> * tempHead = start;

		while(tempHead->next != nullptr){
			tempHead = tempHead->next;
		}

		tempHead->next = newNode;
		//cout << tempHead->next->value << "was added2 " << endl;
	}

	mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
	Node<T> * newNode = new Node<T>(value);	
	Node<T> * tempHead = start;

	if(j == 0){
		insertStart(value);		
	} else {

		for(int x = 0; x < mySize; x++){
			if(x == j - 1){
				Node<T> * tempNode = tempHead->next;
				tempHead->next = newNode;
				newNode->next = tempNode;
			}
			tempHead = tempHead->next;
		}
	}
	mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
	if(mySize > 0){
		Node<T> * tempHead = start;
		start = start->next;
		delete tempHead;
		mySize--;
	}
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
	Node<T> * tempNode = start;
	for(int x = 0; x < mySize - 2; x++){
		tempNode = tempNode->next;
	}

	//cout << " current node is " << tempNode->value << endl;

	if(mySize > 1){
		delete tempNode->next;
		tempNode->next = nullptr;
		mySize--;
	}

	if(mySize == 1){
		delete tempNode;
		start = nullptr;
	
		mySize--;
	}
	
	

}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
	Node<T> * tempHead = start;
	Node<T> * nodeToDelete;
	Node<T> * nodeAfterDeletedNode;

	if(j == 0 && mySize >= 1){		
		removeStart();
		mySize--;
	}


	for(int x = 0; x < mySize; x++){
		if(x == j - 1){
			nodeToDelete = tempHead->next;
			nodeAfterDeletedNode = tempHead->next->next;
			tempHead->next = nodeAfterDeletedNode;
			delete nodeToDelete;
			mySize--;
		} else {
			tempHead = tempHead->next;
		}
	}
	
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
	if(mySize == 0){
		T temp = T();
		return temp;
	}

	return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
	Node<T> * tempNode = start;
	
	for(int x = 0; x < mySize - 1; x++){
		tempNode = tempNode->next;
	}
	
	if(mySize > 0){
		return tempNode->value;
	}

	
	T temp = T(); 
	return temp;

}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
	Node<T> * tempNode = start;
	for(int x = 0; x < mySize; x++){
		if(x == j){
			return tempNode->value;
		}
		//cout << "value was " << tempNode->value << endl;
		tempNode = tempNode->next;
	}
	
	T temp = T();
	return temp;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
	Node<T> * temp = start;
	int position = 0;
	while(temp->next != nullptr){
		if(temp->value == key){
			return position;
		}
		temp = temp->next;
		position++;
	}

	if(start->value == key){
		return 0;
	}
	
	return -1;
}
