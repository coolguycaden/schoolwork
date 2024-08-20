#include "minHeap.h"
// Repeatedly swap element A[i] with its parent
// as long as A[i] violates the heap property with respect to
// its parent (i.e., as long as A[i] < A[parent(i)]).
void minHeap::siftUp(int pos){
	int parentPos = floor((pos - 1) / 2);
	
	//If heap is size of 1 or then node at pos is NOT greater than its parent
	//then no need for sifUp
	if(heap.size() <= 1 || (heap[parentPos] <= heap[pos])){	
		return;
	}

	int temp = heap[parentPos];
	heap[parentPos] = heap[pos];
	heap[pos] = temp;
	
	siftUp(parentPos);
}

//As long as A[i] violates the heap property
//with one of its children, swap A[i] with its smallest child.
void minHeap::siftDown(int pos){
	int leftChildPos = (2 * pos) + 1;
	int rightChildPos = leftChildPos + 1;
	int smallestChildPos;
	int temp;

	if(leftChildPos >= heap.size() && rightChildPos >= heap.size()){
		return;
	} else if(rightChildPos >= heap.size()){
		if(!(heap[leftChildPos] >= heap[pos])){
			temp = heap[pos];
			heap[pos] = heap[leftChildPos];
			heap[leftChildPos] = temp;
		}
		return;
	}
	
	//If the heap has a size of 1 or the node children are GREATER than the parent, no need
	//for siftDown
	if(heap.size() <= 1 || 
	  ((heap[leftChildPos] >= heap[pos]) && (heap[rightChildPos] >= heap[pos])) ){
	  	//cout << "breaking recursion" << endl;
		return;
	}

	if(heap[leftChildPos] > heap[rightChildPos]){
		smallestChildPos = rightChildPos;	
	} else {
		smallestChildPos = leftChildPos;
	}
	
	temp = heap[pos];
	heap[pos] = heap[smallestChildPos];
	heap[smallestChildPos] = temp;

	siftDown(smallestChildPos);
}

minHeap::minHeap(vector<int> data){
	for(int x = 0; x < data.size(); x++){
		insert(data[x]);
	}
}

void minHeap::insert(int value){
	heap.push_back(value);
	int size = heap.size() - 1;
	siftDown(size);
	siftUp(size);
}

//swap A[n] and A[0], then sift-down(0).
int minHeap::removeMin(){
	if(heap.size() < 1){
		return -1;
	}
	
	int min = heap[0];
	heap[0] = heap[(heap.size() - 1)]; 
	heap[(heap.size() - 1)] = min;
	
	heap.pop_back();

	siftDown(0);
	
	return min;
}
