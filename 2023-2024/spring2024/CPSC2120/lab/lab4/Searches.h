/*
 * Name: Caden Allen
 * Date Submitted: 2/19/2024
 * Lab Section: 001
 * Assignment Name: Search and Sorting Algorithms
 */

#pragma once

#include <vector>
#include <iostream>

template <class T>
int linearSearch(std::vector<T> data, T target){

	for(int x = 0; x < data.size(); x++){
		if(target == data[x]){
			return x;
		}
	}

	return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){
	// 1 2 3 4 5 6 7 8 9 10
	// low = 0, high = data.size();
	// mid = high - low / 2 + low
	// mid = 10 - 0/ 2 = 5
	// if 5 = target return
	// 5 higher 
	// low = mid 
	// mid = high - low / 2  +low
	// mid = 10 - 5 / 2 + 5
	// 5 /2 = 2 + 5 = 7
	// 7 lower
	// high = 7
	//

	int low = 0;
	int high = data.size();
	int mid = (high - low) / 2 + low;

	for(int x = 0; x < data.size() / 2; x++){
		
		//std::cout << "mid is " << mid << std::endl;
		//std::cout << "value at mid is " << data[mid] << std::endl;
		if(data[mid] == target){
			return mid;
		}
		
		if(data[mid] > target){
			//std::cout << "high set as " << mid << std::endl;
			high = mid - 1;
		}

		if(data[mid] < target){
			//std::cout << "low set as " << mid << std::endl;
			low = mid + 1;
		}
		mid = low + (high - low) / 2;
	}




	return -1;
}
