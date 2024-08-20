/*
 * Name: Caden Allen
 * Date Submitted: 2/19/2024
 * Lab Section: 001
 * Assignment Name: Sorting and Searching Algorithms 
 */

#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//This function is a helper function used to do the actual sorting in 
//merge sort. Takes in the two split lists sent from mergeSort
//And merges them together, in order from least to greatest
template <class T>
vector<T> merge(vector<T> &leftList, vector<T> &rightList){

	//left is first index of leftList
	//right is first index of rightList
	int left = 0; 
	int right = 0;
	
	//This will hold the left and right list merged, ordered from
	//least to greatest
	vector<T> sortedList;

	while(left < leftList.size() && right < rightList.size()){
		//If left is smaller, than left is pushed first to the 
		//sortedList, and the next left value is taken to be compared
		if(leftList[left] < rightList[right]){
			sortedList.push_back(leftList[left]);
			left++;
		} else {

			//left is bigger, so right is pushed to sortedList
			//and the next right value is taken to be 
			//compared
			sortedList.push_back(rightList[right]);
			right++;
		}
	}
	
	//The above while loop solves the vast majority of cases, these two
	//while loops clean up any remaining edge cases 
	while(right < rightList.size()){
		sortedList.push_back(rightList[right]);
		right++;
	}

	while(left < leftList.size()){
		sortedList.push_back(leftList[left]);
		left++;
	}
	
	//returns sortedList
	return sortedList;
}


template <class T>
vector<T> mergeSort(vector<T> &list){
	vector<T> leftHalf;
	vector<T> rightHalf;
	
	int mid = list.size() / 2;
	
	for(int x = 0; x < mid; x++){
		leftHalf.push_back(list[x]);
		rightHalf.push_back(list[mid + x]);
		if(x == mid - 1 && mid * 2 < list.size()){
			rightHalf.push_back(list[mid + x + 1]);
		}
	}

	if(list.size() <= 1){
		return list;
	} else {

		mergeSort(leftHalf);
		mergeSort(rightHalf);
		list = merge(leftHalf, rightHalf);
		return list;
	}

	return list;
	
}

//This function does the actually "quicksorting" needed by 
//the quickSort function
template <class T>
int pivot(vector<T> &list, int start, int end){
	//This gets a random index as the pivot, in range of the
	//sent in list
	int range = end - start + 1;

	//This holds the random number's index
	int pivotIndex = rand() % range + start;

	//This holds pivot's value
	T pivotValue = list[pivotIndex];
	
	//Swaps pivotIndex with starting index, and starting
	//index value iwth pivotIndex
	T temp = list[start];
	list[start] = list[pivotIndex];
	list[pivotIndex] = temp;
	
	//This will be the index that is swapped when
	//a value less than pivotValue is found
	pivotIndex = start;

	int currentIndex = start + 1;

	for(int x = currentIndex; x <= end; x++){
		
		//A value less than pivotValue is found 
		if(list[x] <= pivotValue){
			pivotIndex++;
			T temp = list[pivotIndex];
			list[pivotIndex] = list[x];
			list[x] = temp;
				
		}
	}
	
	//Swaps the pivot to its proper position
	temp = list[pivotIndex];
	list[pivotIndex] = pivotValue;
	list[start] = temp;

	//returns the pivotIndex for further partitioning of an
	//array
	return pivotIndex;
}

template <class T>
vector<T> quickSortExtended(vector<T> &list, int start, int end){
	//split into two different arrays based on pivot
	// random pivot, swap with beginning
	// Recursive until size is 1
	
	if(start < end){
		int pivotIndex = pivot(list, start, end);
		quickSortExtended(list, start, pivotIndex - 1);
		quickSortExtended(list, pivotIndex + 1, end);
	}

	return list;
}


template <class T>
vector<T> quickSort(vector<T> &list){
	return quickSortExtended(list, 0, list.size() - 1);
}















