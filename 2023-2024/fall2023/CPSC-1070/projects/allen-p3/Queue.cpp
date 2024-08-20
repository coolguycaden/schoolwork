#include "Queue.h"

//Adds an item to the dynamic queue
void Queue::enqueue(char letter){
	if(isEmpty()){
		//Sets up the queue initially
		//if a queue has one item, the front and rear
		//are the same
		front = new QueueNode(letter);
		rear = front;

		size++;
	} else {

		if(isFull()){
			cout << "queue is full" << endl;

		} else {
			//Creates a new rear value, and changes the rear
			//to the new value
			(*rear).next = new QueueNode(letter);
			rear = (*rear).next;

			//Keeps track of queue size
			size++;
		}
	}	
}

//Makes sure the queue does not grow too big
//hard limit of 100 queue items
bool Queue::isFull(){
	if(size >= 100){
		return true;
	}
	return false;
}

//Checks if queue is empty
//No front value, means no queue items
bool Queue::isEmpty(){
	if(front == NULL){
		return true;
	}
	return false;
}

//Removes the first node in the Queue, and sets
//val to the value of the number held in the node
void Queue::dequeue(char & val){
	
	//Creates a temporary QueueNode
	QueueNode * temp;
	
	if(isEmpty()){
		cout << "empty, cannot dequeue" << endl;
	} else {

		//Changes the front node to the node
		//"behind" it, and change that node
		//to be the front
		val = (*front).value;
		temp = front;
		front = (*front).next;
		
		//Frees memory of temp
		delete temp;
		
		
	//	cout << val << " was dequeued " << endl;
			
	}
}

//Clears the queue of values
void Queue::clear(){

	//trash variable,
	//holds the dequeued values
	char value;

	while(!isEmpty()){
		dequeue(value);
	}
}
