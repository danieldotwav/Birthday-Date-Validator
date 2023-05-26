#include <iostream>
#include <string> 
#include "invalidDay.h"

using namespace std;

//	The default constructor invalidDay() sets the private member 'message' to be the string below:
//		"Day must be between 1 and 31."	
invalidDay::invalidDay() {
	message = "Day must be between 1 and 31.\n";
}

//   The overloaded constructor invalidDay(string) assigns the
//string parameter to private member 'message'.
invalidDay::invalidDay(std::string st) {
	message = st + "\n";
}

//   The string function what(), with no parameter, returns
//the private member 'message'.
std::string invalidDay::what() {
	return message;
}