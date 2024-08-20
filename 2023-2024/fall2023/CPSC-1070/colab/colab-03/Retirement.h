#ifndef RETIRE_H
#define RETIRE_H

#include <iostream>
#include <cmath>
#include <iomanip>

//Used for finding substring of user principal
//for debt payment calculator
#include <string>

using namespace std;

class Retirement{

public:
    void estimateDriver();
    
private:
    double estimateEarnings (int, int, int, double, double, double);
    bool isValidPayment(string);    
};


#endif
