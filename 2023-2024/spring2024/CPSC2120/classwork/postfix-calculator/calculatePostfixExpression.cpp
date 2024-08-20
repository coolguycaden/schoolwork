#include <string>
#include <stack>
#include <ctype.h>
#include <iostream>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length){
	int result = 0;
	int num1;
	int num2;
	int x = 0;

	stack<string> operatorStack;

	while(x < length){
		
		char temp = expression[x].at(0);
		if(!isdigit(temp)){
			string numberTemp1 = operatorStack.top();
			num1 = stoi(numberTemp1);
			operatorStack.pop();
			string numberTemp2 = operatorStack.top();
			num2 = stoi(numberTemp2);
			operatorStack.pop();


			switch(temp){
				case '-':
					result = num2 - num1;
					break;
				case '+':
					result = num1 + num2;
					break;
				case '*':
					result = num1 * num2;
					break;
				case '/':
					result = num2 / num1;
					break;
				case '%':
					result = num2 % num1;
					break;
				case '^':
					result = num2 ^ num1;
					break;	
			}

			if(x == length - 1 && operatorStack.empty()){
				return result;
			} else {
				operatorStack.push(to_string(result));
			}

		} else {
			operatorStack.push(expression[x]);
		}

		x++;
	}
	
	return 0;	
	
}
/*
int main(){
	string rizz[3] = {"6", "3", "-"};
	cout << "rizz result: " << calculatePostfixExpression(rizz, 3) << endl;
}*/
