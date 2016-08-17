#include "DayOfYear.h"

//-------------------------------------------------------------------------------------------------------------------------------
//overloading the prefix operator ++
DayOfYear DayOfYear::operator++()
{
	dayOfTheYear++;

	if (dayOfTheYear == 366)
		dayOfTheYear = 1;
	setMonth();
	return DayOfYear(dayOfTheYear);
}
//-------------------------------------------------------------------------------------------------------------------------------

//overloading the postfix operator ++
DayOfYear DayOfYear::operator++(int)
{
	DayOfYear temp = *this;
	dayOfTheYear++;

	if (dayOfTheYear == 366)
		dayOfTheYear = 1;
	setMonth();
	return temp;
}
//-------------------------------------------------------------------------------------------------------------------------------

//overloading the prefix operator --
DayOfYear DayOfYear::operator--()
{
	dayOfTheYear--;

	if (dayOfTheYear == 0)
		dayOfTheYear = 365;
	setMonth();
	return DayOfYear(dayOfTheYear);
}
//-------------------------------------------------------------------------------------------------------------------------------

//overloading the postfix operator --
DayOfYear DayOfYear::operator--(int)
{
	DayOfYear temp = *this;
	dayOfTheYear--;

	if (dayOfTheYear == 0)
		dayOfTheYear = 365;
	setMonth();
	return temp;
}
//-------------------------------------------------------------------------------------------------------------------------------

//default constructor
DayOfYear::DayOfYear()
{
	dayOfTheYear = 1;
	tempDay = 1;
	month = "January";
}
//-------------------------------------------------------------------------------------------------------------------------------

DayOfYear::DayOfYear(int dayChosen)
{
	dayOfTheYear = dayChosen;
	tempDay = dayOfTheYear;
	month = "January";
	setMonth();
}
//-------------------------------------------------------------------------------------------------------------------------------

DayOfYear::DayOfYear(int dayChosen, std::string monthChosen) 
{
	if (dayChosen <= 0 || dayChosen > 31)
	{
		std::cout << "Error, the day chosen is not a correct date.\nExiting the program. . .";
		exit(1);
	}
	dayOfTheYear = dayChosen;
	tempDay = dayOfTheYear;
	month = monthChosen;
}
//-------------------------------------------------------------------------------------------------------------------------------

void DayOfYear::setMonth()
{
	tempDay = dayOfTheYear;
	if (tempDay >= 1 && tempDay <= 31)
		month = "January";
	//February will only have 28 days in this program
	else if (tempDay >= 32 && tempDay <= 59)
	{
		month = "February";
		tempDay -= 31;
	}
	else if (tempDay >= 60 && tempDay <= 90)
	{
		month = "March";
		tempDay -= 59;
	}
	else if (tempDay >= 91 && tempDay <= 120)
	{
		month = "April";
		tempDay -= 90;
	}
	else if (tempDay >= 121 && tempDay <= 151)
	{
		month = "May";
		tempDay -= 120;
	}
	else if (tempDay >= 152 && tempDay <= 181)
	{
		month = "June";
		tempDay -= 151;
	}
	else if (tempDay >= 182 && tempDay <= 212)
	{
		month = "July";
		tempDay -= 181;
	}
	else if (tempDay >= 213 && tempDay <= 243)
	{
		month = "August";
		tempDay -= 212;
	}
	else if (tempDay >= 244 && tempDay <= 273)
	{
		month = "September";
		tempDay -= 243;
	}
	else if (tempDay >= 274 && tempDay <= 304)
	{
		month = "October";
		tempDay -= 273;
	}
	else if (tempDay >= 305 && tempDay <= 334)
	{
		month = "November";
		tempDay -= 304;
	}
	else if (tempDay >= 335 && tempDay <= 365)
	{
		month = "December";
		tempDay -= 334;
	}
}
//-------------------------------------------------------------------------------------------------------------------------------

void DayOfYear::print()
{
	//prints the output for choice 1 in the main program
	std::cout << month << " " << tempDay << "." << std::endl;
}
//-------------------------------------------------------------------------------------------------------------------------------
