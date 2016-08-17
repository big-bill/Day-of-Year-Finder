# Day-of-Year-Finder
super simple first project for COP 2228

Still learning how to use github.
This project isn't anything special, but it was our first project to utilize operator overloading.


Project 1 Description:

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
