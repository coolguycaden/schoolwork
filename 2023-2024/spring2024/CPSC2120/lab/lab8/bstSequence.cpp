/*
 * Name: Caden Allen
 * Date Submitted: 4/3/2024
 * Lab Section: 001
 * Assignment Name: Storing a Sequence in a Binary Search Tree
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <assert.h>

#include "bstSequence.h"

using namespace std;

void fix_size(Node *T)
{
	T->size = 1;
	if (T->left) T->size += T->left->size;
	if (T->right) T->size += T->right->size;
}

/*
// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{
if (T == nullptr) return new Node(k);
if (k < T->key) T->left = insert(T->left, k);
else T->right = insert(T->right, k);
fix_size(T);
return T;
}
*/

//1 3 5 6 7 8 9
//1 3 5
//			6
//	3				8
//1		5		7		9
//
//if r = 0
// v1 3 5 6 7 8 9
Node *insert(Node *T, int v, int r)
{
	//Implement Node *insert(Node *T, int v, int r)
	if(T == nullptr){
		//cout << "made new node " << v << endl;
		return new Node(v); 
	} else if(r == 0){
		Node * previousNode = T;
		Node * newNode = new Node(v);
		T = newNode;
		T->right = previousNode;/*
		Node * previousNode = T->left;
		if(previousNode) cout << "prev node " << T->left->key << endl;
		T->left = new Node(v); 
		T->left->left = previousNode;*/
		fix_size(T);
		return T;
	}
	
	int rootRank = T->left ? T->left->size : 0;

	if(r < rootRank) {
		T->left = insert(T->left, v, r);
	} else {
		T->right = insert(T->right, v, r - rootRank - 1);
	}

	//cout << "after insert" << endl;
	fix_size(T);
	return T;
}

// returns a vector of key values corresponding to the inorder traversal of T (i.e., the contents of T in sorted order)
vector<int> inorder_traversal(Node *T)
{
	vector<int> inorder;
	vector<int> rhs;
	if (T == nullptr) return inorder;
	inorder=inorder_traversal(T->left);
	inorder.push_back(T->key);
	rhs=inorder_traversal(T->right);
	inorder.insert(inorder.end(), rhs.begin(), rhs.end());
	return inorder;
}

// return pointer to node of rank r (with r'th largest key; e.g. r=0 is the minimum)
Node *select(Node *T, int r)
{
	assert(T!=nullptr && r>=0 && r<T->size);

	int rank_of_root = T->left ? T->left->size : 0;
	if (r == rank_of_root) return T;
	if (r < rank_of_root) return select(T->left, r);
	else return select(T->right, r - rank_of_root - 1);
}

// Split tree T on rank r into tree L (containing ranks < r) and 
// a tree R (containing ranks >= r)
void split(Node *T, int r, Node **L, Node **R)
{
	//Implement void split(Node *T, int r, Node **L, Node **R)
	if(T == nullptr){
		*L = nullptr;
		*R = nullptr;
		return;
	}

	int rootRank = T->left ? T->left->size : 0;
	if(r <= rootRank){
		//cout << "split left" << endl;
		*R = T;
		split(T->left, r, L, &((*R)->left));
	} else {
		//cout << "split right" << endl;
		*L = T;
		split(T->right, r - rootRank - 1, &((*L)->right), R);
	}

	fix_size(T);
}

// insert value v at rank r
Node *insert_random(Node *T, int v, int r)
{
	// If (v,r) is the Nth node inserted into T, then:
	// with probability 1/N, insert (v,r) at the root of T
	// otherwise, insert_random (v,r) recursively left or right of the root of T

	//Implement Node *insert_random(Node *T, int v, int r)
	if(T == nullptr){
		//cout << "made node" << endl;
		return new Node(v);
	}

	int treeSize = T->size + 1;
	int ranNum = rand() % treeSize;

	if(ranNum == 0){
		//cout << "split" << endl;
		Node * newNode = new Node(v);
		split(T, r, &newNode->left, &newNode->right);
		fix_size(newNode);
		return newNode;
	} 

	int rootRank = T->left ? T->left->size : 0;
	if(r > rootRank){
		//cout << "going right" << endl;
		T->right = insert_random(T->right, v, r - rootRank - 1);
	} else {
		//cout << "going left" << endl;
		T->left = insert_random(T->left, v, r);
	}
	

	fix_size(T);
	//cout << "size fixed" << endl;
	return T;

}

// Returns true if team x defeated team y
// Leave this function unmodified
bool did_x_beat_y(int x, int y)
{
	assert (x != y);
	if (x > y) return !did_x_beat_y(y,x);
	unsigned long long lx = x;
	unsigned long long ly = y;
	return ((17 + 8321813 * lx + 1861 * ly) % 1299827) % 2 == 0;
}

// Return a BST containing a valid ordering of n teams
Node *order_n_teams(int n)
{
	Node *T = nullptr;

	// start by inserting the first team
	T = insert_random(T, 0, 0);

	// now insert the other teams...
	for (int i=1; i<n; i++) {
		// insert team i so the sequence encoded by the BST remains valid
		if (did_x_beat_y(i, select(T,0)->key)) // can we insert at beginning?
			T = insert_random(T, i, 0);
		else if (did_x_beat_y(select(T,T->size-1)->key, i)) // can we insert at end?
			T = insert_random(T, i, T->size);
		else {
		
			//cout << "current team is " << i << endl;
			// 7 5 4 2 0 3 1 6    (when inserting team i=8)
			// W W W L L L W L
			// i = team
			// T = current_ordered_tree
			/*
			bool winLosses[T->size];
			for(int x = 0; x < T->size; x++){
				bool result = did_x_beat_y(select(T, x)->key, i);
				winLosses[x] = result;
			}*/
			//return T;
			// L is did x beat y is false 0
			// W if true any non-zero
			
			/*for(int x = 0; x < T->size; x++){
				if(winLosses[x] == 0){
					cout << "L ";
				} else {
					cout << "W ";
				}
			}
			cout << endl;*/

			int lowRank = 0;
			int highRank = T->size - 1;
			int midRank = (highRank + lowRank) / 2;
			
			for(int x = 0; x < T->size/2; x++){
				//cout << winLosses[midRank] << endl;
				
				bool current = did_x_beat_y(select(T, midRank)->key, i);
				switch(current){//winLosses[midRank]){
					case true:
						lowRank = midRank;
						break;

					case false:
						highRank = midRank;
						break;
				}
				midRank = (highRank + lowRank) / 2;
			}
			
			//cout << "lowrank = " << winLosses[lowRank] << ", highrank = " << winLosses[highRank] << endl;

			//if((winLosses[lowRank] == false && winLosses[highRank] == true)){
			//    || (winLosses[lowRank] == true && winLosses[highRank] == false)){
			  ///  		cout << "found space" << endl;
		//	cout << "spot is at " << highRank << endl;
			T = insert_random(T, i, highRank);
			//
			
		}
	}
	return T;
}

void printVector(vector<int> v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

/*
int main(void)
{
	vector<int> inorder;
	Node *T = nullptr;
	
	// test insert at beginning
	for (int i=0; i<5; i++){
		T = insert(T, i+1, 0);
		//inorder = inorder_traversal(T);
		//printVector(inorder);
		//cout << '\n';
	}
	cout << "Tree should contain 5 4 3 2 1:\n";
	inorder=inorder_traversal(T);
	printVector(inorder);
	
	// test insert at end
	for (int i=5; i<10; i++){
		//cout << "adding " << i + 1 << " at rank " << T->size << endl;
		T = insert(T, i+1, T->size);
		//inorder = inorder_traversal(T);
		//printVector(inorder);
	}
	cout << "Tree should contain 5 4 3 2 1 6 7 8 9 10:\n";
	inorder=inorder_traversal(T);
	printVector(inorder);
		
	 test join
	T = join(L, R);
	cout << "Contents of re-joined tree (should be 0..9)\n";
	inorder=inorder_traversal(T);
	printVector(inorder);
	cout << "Tree size " << T->size << "\n";
	

	// test insert at middle
	for (int i=10; i<15; i++){
		cout << "adding " << i + 1 << " at rank " << T->size/2 << endl;
		T = insert(T, i+1, T->size/2);
		inorder = inorder_traversal(T);
		printVector(inorder);
	}
	cout << "Tree should contain 5 4 3 2 1 12 14 15 13 11 6 7 8 9 10:\n";
	inorder=inorder_traversal(T);
	printVector(inorder);
	
	
	// test split
	Node *L, *R;
	split(T, 4, &L, &R);
	cout << "Contents of left tree after split (should be 5..1):\n";
	inorder=inorder_traversal(L);
	printVector(inorder);
	cout << "Left tree size " << L->size << "\n";
	cout << "Contents of right tree after split (should be 6..10):\n";
	inorder=inorder_traversal(R);
	printVector(inorder);
	cout << "Right tree size " << R->size << "\n";
	
	
	// once insert is working, the next step is to build the
	// insert_random function -- to test this, just change
	// calls to insert above to insert_random.
	int N = 100000; // this should run quickly even for very large N!
	Node *S = order_n_teams(N);
	if (S == nullptr || S->size != N)
		cout << "Size of tree returned by order_n_teams is wrong\n";
	else {
		cout << "Team ordering:\n";
		//    inorder=inorder_traversal(S);
		//    printVector(inorder);
		for (int i=0; i<N-1; i++) {
			Node *x = select(S, i);
			Node *y = select(S, i+1);
			if (!did_x_beat_y(x->key, y->key)) {
				cout << "Invalid sequence: team " << x->key << " (position " << i <<
					") lost to team " << y->key << " (position " << i+1 << ")\n";
			}
		}
	}  
	return 0;
}*/
