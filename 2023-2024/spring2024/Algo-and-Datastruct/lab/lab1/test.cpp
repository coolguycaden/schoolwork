#include "ListQueue.h"
#include "ListStack.h"
#include "List.h"

#include <sstream>
int main(){
	/*List<string> fart;

	fart.insertEnd("a");
	fart.insertEnd("b");
	fart.insertEnd("c");
	fart.insertEnd("d");

	cout << fart.size() << endl;
	cout << fart.empty() << endl;
	cout << fart.find("c") << endl;
	cout << fart.getAt(0) << endl;
	*/
	
	/*Test 8
	
	List<int> list1;
	for(int i = 1, j = 1; i <= 10; i++){
		j = -2 * j;
		cout << "j is: " << j << endl;
		list1.insertStart(j);
	}
	list1.insertAt(3,0);
	list1.print("list1: ");
	int test[11];
	string bob;


	int test2[] = {3,1024,-512,256,-128,64,-32,16,-8,4,-2};
	for (int i=0; i<11;i++){
		// ASSERT_EQ(test[i],test2[i]);
	}


	// When done redirect cout to its old self

	for (int i=0; i<11; i++)
	{
		if (test[i] != test2[i])
		{
			cout << "Mismatch at position " << i << ": expected/correct value " << test2[i] << ", actual value when testing " << test[i] << ".\n";
			return 1;
		}
	}
	cout << "Passed" << endl;
	*/


		/* TEST 13
		   List<char> list3;
		   char c[] = {'z', 'p', 'r', 'p', 'd', 'a', 'h', 'q', 'o', 'r', 'r', 'r'};
		   for(int i = 0; i < 12; i++){
		   list3.insertStart(c[i]);
		   }
		   list3.print("list3: ");
		   cout << list3.getAt(4) << endl;
		   if(list3.getAt(4) == 'q'){
		   cout << "yup";
		   } else {
		   cout << "nope";
		   }
		 */
	

	/*  TEST 18 plus more testing 
	 *
	ListStack<char> stack4;
	List<char> test;
	char a = 'A';
	for(int i = 1, j = 1; i <= 17; i++){
		stack4.push(a);
		test.insertStart(a);
		a++;
	}

	stack4.print("stack: ");
	test.print("list: ");
	cout << " last is: " << test.getLast() << endl;
	int k = stack4.pop();
	cout << "k is " << k << endl;
	if (stack4.size() != 16)
	{
		cout << "expected/correct value 6, actual value when testing " << stack4.size() << ".\n";
		return 1;
	}
	cout << "Passed" << endl;
	*/

	//Test 17
	//here11 * 10 - insertStart
	//here18 - getLast
	//1
	//here 15 - removeEnd
	//here18
	//2
	//here15

	List<int> rizz;
	for(int x = 1; x < 11; x++){
		rizz.insertStart(x);
	}

	rizz.print("list: ");
	rizz.removeEnd();
	rizz.print("after is " );
	rizz.removeEnd();
	rizz.print("again now: ");
}
