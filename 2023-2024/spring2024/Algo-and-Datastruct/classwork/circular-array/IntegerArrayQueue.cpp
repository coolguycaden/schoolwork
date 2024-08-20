#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value){
	if((back + 2) % size == front){
		//cout << "\tqueue full " << endl;
		return false;
	} else {

		back++;
		if(back == size){
			back = 0;
		}
		
		//cout << "\tqueue empty and space available" << endl;
		array[back] = value;
		//cout << "queue now: ";
		//printArrayQueue();
		/*	} else {

			back++;

			if(back == size){
			back = 0;
			}
			cout << "\tspace available" << endl;
			array[back] = value;
			cout << "queue now: ";
			printArrayQueue();
			}*/
		return true;
	}
	//cout << "\tfailed enqueue" << endl;
	return false;
}

int IntegerArrayQueue::dequeue(){
	if((back + 1) % size == front){
		//cout << "\tqueue empty, cannot dequeue" << endl;
		//cout << "queue is: ";
		//printArrayQueue();
		return 0;
	} else {
		int returnValue = array[front];
		front++;
		if(front == size){
			front = 0;
		}
				
		//cout << "\tdequeue possible, removing " << returnValue << " front is " << front << endl;
		//cout << "queue now: ";
		//printArrayQueue();
		return returnValue;

	}
	
	//cout << "\tfailed dequeue" << endl;
	return 0;

}
