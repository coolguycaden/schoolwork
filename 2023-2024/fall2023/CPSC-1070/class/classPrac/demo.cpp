#include <iostream>
#include "demo.h"

using namespace std;

Demo::Demo(){
	cout<<"demo constructor is called!"<<endl;
}

Demo::Demo(char c){
	lel = c;
	cout<<"works!!"<<endl;
}

Demo::~Demo(){
	cout<<"destroyed!"<<endl;
}

