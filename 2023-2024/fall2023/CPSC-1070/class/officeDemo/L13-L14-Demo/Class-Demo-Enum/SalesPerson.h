#ifndef SALESP_H
#define SALESP_H

static const int MONTHS = 12;

class SalesPerson {
 public:
  SalesPerson(); //default constructor
  void getSalesFromUser(); //function to get sales #s
  void printAnnualSales(); //sumarize and print sales
  enum Months {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
  Months calendar;
  
 private:
  double sales[MONTHS];
  double totalAnnualSales(); //utility function
  void setSales(int, double); //set sales for a month
  void printMonth(Months);
  
  //static const int MONTHS = 12;
};

#endif
