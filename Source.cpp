#include <iostream>
#include <string>
#include <ctime>
#include "invalidDay.h"
#include "invalidMonth.h" 

using namespace std;

//  Create a function of type int called getDay() with 2 integer parameters to represent month and year. This function returns the proper day entered by the user.
int getDay(int mth, int yr);
//  Create a function of type int getMonth() with no parameter to return the month.
int getMonth();
//  Create a function of type int getYear() with no parameter to return the year.
int getYear();
//  Create a function isLeapYear() of type bool with an int paramter to represent the year.
bool isLeapYear(int yr);  
string getMonthName(int month);
//  Create a function of type void called printBirthDate() with 3 integer parameters: day. month and year. This function displays the user birthday in the form: Month_name, day and year (ex: August 5, 2001)
void printBirthDate(int day, int month, int year);
void updateChoice(bool* loopPtr);


int main() {
    int day;
    int month{ 0 };
    int year;

    bool loop{ false };
    bool* loopPtr = &loop;

    do {
        year = getYear();
        month = getMonth();
        day = getDay(month, year);

        cout << "Birth Day: ";
        printBirthDate(day, month, year);

        // Ask user if they want to re-run the program
        updateChoice(loopPtr);
    } while (loop);


    return 0;
}

int getDay(int mth, int yr) {
    bool done{ false };
    string message{ "" };
    int day;

    do {
        try {
            cout << "Enter birth day: ";
            cin >> day;

            // Day is out range for any month
            if (day < 1 || day > 31) {
                invalidDay invD;
                throw invD;
            }
            // Months with 31 days
            if ((mth == 1 || mth == 3 || mth == 5 || mth == 7 || mth == 8 || mth == 10 || mth == 12) && day > 31) {
                invalidDay invD;
                // Convert mth variable into a string and concatenate
                message = to_string(mth) + " only has 31 days";
                throw invD;
            }
            // Months with 30 days
            if ((mth == 4 || mth == 6 || mth == 9 || mth == 11) && day > 30) {
                invalidDay invD;
                message = to_string(mth) + " only has 30 days";
                throw invD;
            }
            // Check February days
            if (mth == 2 && day > 28) {
                if (!(day == 29 && isLeapYear(yr))) {
                    message = "February only had 28 days in " + to_string(yr);
                    throw message;
                }
            }

            done = true;
        }
        // Message: Day must be between 1 and 31 (Default Constructor)
        catch (invalidDay invD) {
            cout << invD.what();
        }
        // Custom Message: Parameterized Constructor 
        catch (std::string) {
            invalidDay invD(message);
            cout << invD.what();
        }
    } while (!done);

    return day;
}

int getMonth() {
    bool done{ false };
    int mth;

    do {
        try {
            cout << "Enter birth month: ";
            cin >> mth;

            if (mth < 1 || mth > 12) {
                invalidMonth invM;
                throw invM;
            }
            else {
                done = true;
            }
        }
        catch (invalidMonth invM) {
            invM.what();
        }
    } while (!done);

    return mth;
}

int getYear() {
    bool done{ false };
    int yr;

    do {
        try {
            cout << "Enter birth year: ";
            cin >> yr;

            if (yr < 1990 || yr > 2023) {
                throw "invYr";
            }
            else {
                done = true;
            }
        }
        catch (char const* invY) {
            cout << "Enter a value between 1990 and 2023." << endl;
        }
    } while (!done);

    return yr;
}

bool isLeapYear(int yr) {
    if (((yr % 4 == 0) && (yr % 100 != 0)) || yr % 400 == 0)
        return true;
    else
        return false;
}

string getMonthName(int month) {
    string monthName{ "" };

    switch (month) {
    case 1:
        monthName = "January";
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    case 5:
        monthName = "May";
        break;
    case 6:
        monthName = "June";
        break;
    case 7:
        monthName = "July";
        break;
    case 8:
        monthName = "August";
        break;
    case 9:
        monthName = "September";
        break;
    case 10:
        monthName = "October";
        break;
    case 11:
        monthName = "November";
        break;
    case 12:
        monthName = "December";
        break;
    default:
        cout << "Could not find a valid for the date entered\n";
    }

    return monthName;
}

void printBirthDate(int day, int month, int year) {
    cout << getMonthName(month) << " " << day << ", "
        << year << endl << endl;
}

void updateChoice(bool* loopPtr) {
    // Allocate memory for the pointer
    int decision = *loopPtr;

    cout << "Would you like to run the program again?\n";
    cout << "Enter 1 for YES, Enter 0 to EXIT: ";
    cin >> decision;

    while (decision != 1 && decision != 0) {
        cout << "ERROR: " << decision << " is not a valid choice\n";
        cout << "Would you like to run the program again?\n";
        cout << "Enter 1 for YES, Enter 0 to EXIT: ";
        cin >> decision;
        cout << endl;
    }

    // Update the value of loop via the pointer
    *loopPtr = decision;

    cout << endl;
}