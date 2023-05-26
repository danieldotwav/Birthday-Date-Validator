#include <iostream>
#include <string> 
#include "invalidMonth.h"

using namespace std;

//The default constructor invalidMonth() sets the private 
//member 'message' to be the string below:
//	"The month must be between 1 and 12.";
invalidMonth::invalidMonth() {
	message = "The month must be between 1 and 12.";
}

//The overloading constructor invalidMonth(string) assigns the
//string parameter to the private member 'message'.
invalidMonth::invalidMonth(std::string st) {
	st = message;
}

//The function what() returns the private member 'message'.
std::string invalidMonth::what() {
	return message;
}