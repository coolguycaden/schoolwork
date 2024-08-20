#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  cout <<"demo start"<<endl;

  enum Fruit {apple, grape, orange};
  cout<< "apple = "<<apple<<" grape = " << grape<<endl;
  enum Fruit2{banana, cherry, tomato};
  Fruit2 f;
	f = banana;
	string b = "banana";
	cout<<"f is: " << f << " and b is " << static_cast<Fruit2>(b);
	//int n = cherry;
	//cout << " n is : " << n;
		
} 

  
