#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <iostream>
#include <string>

class DayOfYear
{
private:
	int dayOfTheYear;
	int tempDay;
	static std::string month;

public:
	DayOfYear();
	DayOfYear(int);
	DayOfYear(int, std::string);  // Added because of challenge 3

	DayOfYear operator++();
	DayOfYear operator++(int);
	DayOfYear operator--();
	DayOfYear operator--(int);

	void setMonth();
	void print();
};

#endif