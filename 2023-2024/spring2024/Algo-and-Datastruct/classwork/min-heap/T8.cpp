#include <vector>
#include <iostream>

#include "minHeap.h"

//using testing::ElementsAreArray;

using namespace std;

int main()
{
    vector<int> input;
    vector<int> test;
    vector<int> heapTest;

    for (int i=1000000; i>0; i--) input.push_back(i);
    cout << "done1";
    for (int i=1; i<=1000000; i++) test.push_back(i);
    cout << "done2";

    minHeap h(input);

cout << "done ";
    for (int i=0; i<1000000; i++) heapTest.push_back(h.removeMin());

    //ASSERT_THAT(heapTest, ElementsAreArray(test));
    for (int i=0; i<1000000; i++)
    {
    	if(i % 100000){
		cout << "100000 done" << endl;
	}
        if (heapTest[i] != test[i])
        {
            std::cout << "Mismatch in heapTest at position " << i << ": expected/correct value " << test[i] << ", actual value when testing " << heapTest[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}
