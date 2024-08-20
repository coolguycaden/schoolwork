#include "Searches.h"
#include "Sorts.h"

int main(){
	vector <int> rizz;

	cout << "before sort: ";
	
	srand(time(NULL));
	for(int x = 1; x < 12; x++){
		int num = rand() % 50;
		rizz.push_back(num);
		cout << num << " ";
	}
	cout << "\n\n";
	//cout << "len is: " << rizz.size() << endl;

	//cout << "after sort: ";
	//vector <int> newRizz = mergeSort(rizz);
	

	quickSort(rizz);
	cout << "len is now: " << rizz.size() << endl;
	cout << "after sort: ";
	for(int x = 0; x < rizz.size(); x++){
		cout << rizz[x] << " ";
	}
	cout << endl;
}
