#ifndef INVALIDDAY_H
#define INVALIDDAY_H

#include <iostream>
#include <string> 

class invalidDay
{
public:
	//Create a default constructor with no parameter.
	invalidDay();

	//Create an overloaded constructor with a string parameter,
	invalidDay(std::string st);

	// Create a string function what(), with no parameter.
	std::string what();

private:
	std::string message;
};

#endif