#ifndef QUEUE_H
#define QUEUE_H

#include <iostream> // For output and input

using namespace std;

class Queue {
	private:
		//Implements the Linked List ADT, along with a constructor
		struct QueueNode {
			char value;
			QueueNode *next;	

			QueueNode(char val, QueueNode *nxt = nullptr){
				value = val;
				next = nxt;
			}

		};
		
		//Tracks front and rear of queue
	       	QueueNode *front;
		QueueNode *rear;
		
		//Keeps track of the queue size
		int size;

	public:
		Queue(){
			front = nullptr;
			rear = nullptr;
		}
		
		//Adds an item to the queue
		void enqueue(char);

		//Removes an item from the queue
		void dequeue(char &);

		//Returns true if the front node does
		//not point to another node
		bool isEmpty();

		//Returns true if queue size is
		//greater or equal to 100
		bool isFull();

		//Empties the queue
		void clear();
};

#endif
