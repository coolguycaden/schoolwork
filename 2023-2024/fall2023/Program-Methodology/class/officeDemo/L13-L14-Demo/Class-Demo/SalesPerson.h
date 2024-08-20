#ifndef SALESP_H
#define SALESP_H

static const int MONTHS = 12;

class SalesPerson {
 public:
  SalesPerson(); //default constructor
  void getSalesFromUser(); //function to get sales #s
  void printAnnualSales(); //sumarize and print sales
  
 private:
  double sales[MONTHS];
  double totalAnnualSales(); //utility function
  void setSales(int, double); //set sales for a month

  //static const int MONTHS = 12;
};

#endif
