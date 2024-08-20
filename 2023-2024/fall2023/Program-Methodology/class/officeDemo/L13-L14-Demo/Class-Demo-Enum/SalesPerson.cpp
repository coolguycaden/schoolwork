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

  for (int i = JANUARY; i <= DECEMBER; i++){
    //cout<<"Enter sales figure for month "<<i<<": $";
      cout<<"Enter monthly sales amount for ";
      
      //c++ cannot implicitly convert an int to a month
      //*** Modified for enum ***/
      printMonth(static_cast<Months>(i));
      cout<<": $";
      cin>>salesFigure;
      while (salesFigure<0) {
          cout<<endl<<"Monthly sales figure needs to be $0.00 or higher"<<endl<<"Please re-enter the monthly sales figure: $";
          cin>>salesFigure;
          
      }

    //will need to call setSales(i, salesFigure); 
    setSales(i, salesFigure);
  }
}

void SalesPerson::printAnnualSales(){
  cout<<setprecision(2)<<fixed<<"Total annual sales are $"<<totalAnnualSales()<<endl;
}

//private functions

//***New for Enumerated Type Demo ***
void SalesPerson::printMonth(Months inMonth){
    //uses a switch statement to print out the month
  switch(inMonth){
      case JANUARY : cout<<"January"; break;
      case FEBRUARY : cout<<"February";break;
      case MARCH : cout<<"March"; break;
      case APRIL : cout<<"April"; break;
      case MAY : cout<<"May"; break;
      case JUNE : cout<<"June"; break;
      case JULY : cout<<"July"; break;
      case AUGUST : cout<<"August"; break;
      case SEPTEMBER : cout<<"September"; break;
      case OCTOBER : cout <<"October"; break;
      case NOVEMBER : cout<<"November"; break;
      case DECEMBER : cout<<"December"; break;
      default: cout<<"Error converting months!";
  }
}


void SalesPerson::setSales(int month, double amount){
    //assert that month and amount have been validated prior to function
    //sets the sales in the array (aka mutator)
    sales[month-1] = amount;
}

double SalesPerson::totalAnnualSales(){
  double total = 0.0;

  for (int i = 0; i < MONTHS; i++){
    total += sales[i];
  }
  return total;
}

