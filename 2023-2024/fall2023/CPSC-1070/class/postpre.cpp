#include <iostream>
using namespace std;

int main(){
  int x =4;

  cout<<"1.0post: "<< x--<<endl;
  cout<<"current val: "<<x<<endl;
  cout<<"2.0pre: "<<--x<<endl;
  cout<<"current val: "<<x<<endl;
  cout<<"3.0post: "<<x++<<endl;
  cout<<"current val: "<<x<<endl;
  cout<<"4.0pre: "<<++x<<endl;
}
