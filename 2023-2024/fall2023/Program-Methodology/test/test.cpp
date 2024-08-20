#include <iostream>
using namespace std;

int main(){
  int dog = 0;

  cout<<"1Dog is "<<dog<<endl;
  {
    int dog = 1;
    cout<<"2dog is " << dog<<endl;
  }
  cout <<"3dog is"<<dog<<endl;

  enum Farts {wet, stinky, gassy, dirty};
  Farts num1= wet;

  cout<<"The types of farts are: "<<num1<<endl;
  
}
