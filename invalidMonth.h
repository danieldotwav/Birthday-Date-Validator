#ifndef INVALIDMONTH_H
#define INVALIDMONTH_H

#include <iostream>
#include <string> 

class invalidMonth
{
public:
	//Create a default constructor invalidMonth() with no parameter. 
	invalidMonth();
	//Create a constructor invalidMonth(string) with a string parameter.
	invalidMonth(std::string st);
	//Create a destructor with a message about calling the destructor
	//from this class.
	~invalidMonth() { std::cout << "invalidMonth destructor called\n"; }
	//Create a function of type string, called what(). This function has no parameter.
	std::string what();

private:
	std::string message;
};

#endif