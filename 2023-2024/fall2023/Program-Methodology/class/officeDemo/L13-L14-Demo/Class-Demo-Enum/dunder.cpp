#include <iostream>
#include "SalesPerson.h"


using namespace std;

int main(){
  cout<<"Welcome to Dunder-Mifflin Infinity!"<<endl;

  SalesPerson dwight;

  dwight.getSalesFromUser();
  dwight.printAnnualSales();

  cout<<"Goodbye, world!"<<endl;

}
