#include <iostream>
#include <iomanip> // we're dealing with money
#include "SalesPerson.h"

using namespace std;

//define public functions
SalesPerson::SalesPerson(){
  for (int i = 0; i < MONTHS; i++) {
    sales[i] = 0.0;
  }
}

void SalesPerson::getSalesFromUser(){
  double salesFigure = 0.0;

  for (int i = 1; i <= MONTHS; i++){
    cout<<"Enter sales figure for month "<<i<<": $";
    cin>>salesFigure;

    //will need to call setSales(i, salesFigure); 
    setSales(i, salesFigure);
  }
}

void SalesPerson::printAnnualSales(){
  cout<<setprecision(2)<<fixed<<"Total annual sales are $"<<totalAnnualSales()<<endl;
}

//private functions
void SalesPerson::setSales(int month, double amount){
  if (month >= 1 && month <= MONTHS && amount >= 0)
    sales[month-1] = amount;
  else
    cout<<"Error message: months or sales figure are not valid"<<endl;
  
}

double SalesPerson::totalAnnualSales(){
  double total = 0.0;

  for (int i = 0; i < MONTHS; i++){
    total += sales[i];
  }
  return total;
}

