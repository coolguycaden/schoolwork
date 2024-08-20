#include <iostream>
#include <cstdlib>
using namespace std;

int fibonacci(int num){
	if(num == 0 || num == 1){
		return num;
	}

	return (fibonacci(num - 1) + fibonacci(num - 2));
}

int main(){
	/*	
	enum Color {
		red,
		green = 3,
		blue,
		yellow = 1,
		brown
	};

	Color r = static_cast<Color>(blue);
	cout << r;
	*/
	
	int x = 0;
	while (x < 10 ){
		cout << x + 1 << " term is: " << fibonacci(x) << endl;
		x++;
	}

	return 0;
}
