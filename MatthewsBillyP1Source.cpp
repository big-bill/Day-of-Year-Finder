/*
Project 1 is programming challenges 2 & 3 for chapter 11
Challenge 2: 
Assuming that a year has 365 days, write a class named DayOfYear that takes an integer representing a day of the year
and translate it to a string consisting of the month followed by day of the month. For example:

Day 2 would be January 2
Day 32 would be February 1
Day 365 would be December 31

The constructor for the class should take as a parameter an integer representing the day of the year, and the class
should have a member function print() that prints the day in the month-day format. The class should have an integer
member variable to represent the day and should have static member variables of type string to assist in the translation
from the integer format to the month-day format.

Test your class by inputting various integers representing days and printing out their representation in the month-day format.


Challenge 3:
Modify DayOfYear class to add a constructor that takes two parameters: a string representing a month and an integer in the range 
0 through 31 representing the day of the month. The constructor should then initialize the integer member of the class to represent
the day specified by the month and day of month parameters. The constructor should terminate the program with an appropriate error
message if the number entered for a day is outside the range of days for the month given.
Add the following overloaded operators:

++ prefix and postfix increment operators. These operators should modify the DayOfYear object so that it represents the next day.
If the day is already the end of the year, the new value of the object will represent the first day of the year.

-- prefix and postfix decrement operators. These operators should modify the DayOfYear object so that it represents the previous day.
If the day is already the first day of the year, the new value of the object will represent the last day of the year.

---End---
 
Written by Billy Matthews, Feb 2016

Updated in August 2016, made some improvements to make it github-ready and whatnot.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "DayOfYear.h"

void splashScreen(); //greets the user and explains the program
void clearScreen();  //clears the screen

std::string DayOfYear::month = "";  //static string variable for the DayOfYear class

//-------------------------------------------------------------------------------------------------------------------------------
int main()
{
	//declaration and initialization of variables
	int day = 0, dayOfTheMonth = 0, testDate = 0;
	std::string temp = "", chosenMonth = "", input = "";
	char repeat = '\0';

	//greets the user and explains the program
	splashScreen();

	
	do{
		//clearScreen does what it sounds like, it clears the screen
		clearScreen();

		while (true)
		{
			std::cout << "-----------------Day of the year finder Program-----------------\n"
					  << "Enter a day of the year (1-365) to find what month and day it is.\n"
					  << "Day: ";

			std::getline(std::cin, input);

			//validates that the user entered a numeric value between 1-2
			std::stringstream myStream(input);
			if (myStream >> day && (day >= 1 && day <= 365))
				break;
			clearScreen();
			std::cout << "\nInvalid choice, please try again.\n\n";
		}

		// Example of utilizing the second constructor that has two parameters (int day and string month)
		// The specifications didn't ask for the second constructor to be utilized, only added onto the class.
		/*
			std::string testMonth = "May"
			DayOfYear dayKnown(5, testMonth);
			dayKnown.print();
			std::getline(std::cin, temp);
			DayOfYear dayError(32, "May"); // Program exits because of an invalid date
		*/

		DayOfYear dayChosen(day);
		
		std::cout << "\nDay " << day << " is: ";
		dayChosen.print();

		dayChosen++;
		dayChosen.setMonth();
		std::cout << "\nThe next day: ";
		dayChosen.print();

		//To get the previous date, we must decrement twice
		dayChosen--;
		--dayChosen;
		dayChosen.setMonth();
		std::cout << "\nThe previous day: ";
		dayChosen.print();

		//gets the user's decision to repeat the program or not
		while (true)
		{
			std::cout << "\nWould you like to enter another date? (Y/N)  ";
			std::getline(std::cin, temp);

			if (temp.length() == 1)
			{
				repeat = temp[0];
				repeat = toupper(repeat);
				if (repeat == 'Y' || repeat == 'N')
					break;
			}
			std::cout << "\nInvalid entry, please try again." << std::endl;
		}

	} while (repeat != 'N');
	
	std::cout << "\n\nThanks for using the program!\nPress enter to exit. . .";
	std::cin.get();
	return 0;
}	

//-------------------------------------------------------------------------------------------------------------------------------
void splashScreen()
{
	std::cout << "Welcome to the \"Day of the year finder\" program!\n"
			  << "\nThis program will find the month and day of a particular day of the year by\n"
			  << "having you enter a day of the year (A value ranging between 1-365).\n"
			  << "\nPress enter to continue. . .";
	std::cin.get();
	std::cin.clear();
}

//-------------------------------------------------------------------------------------------------------------------------------
void clearScreen()
{
	//clears the screen
	std::cout << std::string(100, '\n');
}
