/*
  Author:		   Luis F Suarez
  Assignment:      Lab 11
  Topic:           Day of the Year
  File Name:	   TT17_L11_Suarez.cpp
  Course/Section:  COSC 1337
  Due Date:        See syllabus or blackboard
  Instructor:      Thayer
*/
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <array>

using namespace std;

class Day
{
private:
	int dayOfTheYear;

public:
	Day(int dayInput = 1); // default value
	Day(string month, int day);

	const static int numberOfDaysInMonthArray[13]; // = array with index 0 empty to match index with day number
	const static string monthOfTheYearArray[13];   // = array with index 0 empty to match index with month number

	int get_day()
	{
		return dayOfTheYear;
	}
	void set_day(int dayInput = 1)
	{
		dayOfTheYear = dayInput;
	}

	void display();

	// Overloading
	Day operator++();
	Day operator++(int);
	Day operator--();
	Day operator--(int);
};

const int Day::numberOfDaysInMonthArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const string Day::monthOfTheYearArray[13] = {" ", "january", "febuary", "march", "april", "may", "june", "july",
											 "august", "september", "october", "november", "december"};

Day::Day(int dayInput)
{
	if (dayInput >= 1 && dayInput <= 365)
	{
		dayOfTheYear = dayInput;
	}
	else
	{
		int defaultDay = 1;
		cout << "\n Not a valid day entered. Defaulting to day 1." << endl;
		dayOfTheYear = defaultDay;
	}
}

Day::Day(string month, int day)
{

	int counter = 1;

	while (counter < sizeof(monthOfTheYearArray))
	{
		if ((day > numberOfDaysInMonthArray[counter] && month.substr(0, 3) == monthOfTheYearArray[counter].substr(0, 3)) || day <= 0)
		{
			int defaultDay = 1;
			cout << "\n Not a valid day entered. Defaulting to jan 1." << endl;
			dayOfTheYear = defaultDay;
			break;
		}
		if (month.substr(0, 3) == monthOfTheYearArray[counter].substr(0, 3))
		{
			month = monthOfTheYearArray[counter];
			int day_count = 0;
			for (int i = 1; i < counter;)
			{
				day_count += numberOfDaysInMonthArray[--counter];
			}
			dayOfTheYear = day_count + day;
			break;
		}
		else
		{
			if (counter == 13)
			{
				int defaultDay = 1;
				cout << "\n Not a valid month entered. Defaulting to jan 1." << endl;
				dayOfTheYear = defaultDay;
				break;
			}
		}
		counter++;
	}
}
// overloading operator
Day Day::operator++()
{
	dayOfTheYear++;
	return *this;
}
// overloading operator
Day Day::operator++(int)
{
	Day temp = *this;
	dayOfTheYear++;
	return temp;
}
// overloading operator
Day Day::operator--()
{
	dayOfTheYear--;
	return *this;
}
// overloading operator
Day Day::operator--(int)
{
	Day temp = *this;
	dayOfTheYear--;
	return temp;
}

void Day::display()
{

	int TemporaryCounter = numberOfDaysInMonthArray[1];
	string month = " ";
	int day = 0;

	for (int index = 1; dayOfTheYear >= index; index++)
	{

		if (dayOfTheYear > TemporaryCounter)
		{ //
			TemporaryCounter += numberOfDaysInMonthArray[index + 1];
		}
		else
		{

			month = monthOfTheYearArray[index];

			if (dayOfTheYear <= numberOfDaysInMonthArray[1])
			{
				day = dayOfTheYear;
			}
			else
				day = -(TemporaryCounter - dayOfTheYear - numberOfDaysInMonthArray[index]);

			const int thisYear = 2019;
			string date = month + " " + to_string(day) + ", " + to_string(thisYear);

			cout << endl
				 << " Day number: [" << dayOfTheYear << "] " << date << endl;

			break;
		}
	}
}

int main()
{

	char option = ' ';
	do
	{
		cout << "\nPlease pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: ";

		cin >> option;
		if (toupper(option) == 'D')
		{
			cout << " Enter day of year number (-9 to quit): ";
			int day_num = 0;
			cin >> day_num;
			Day my_day(day_num);
			my_day.display();
		}
		else if (toupper(option) == 'M')
		{
			cout << "\n Enter the month and day of month: (stop -9 to quit): ";
			string month = "   ";
			int day = 0;
			cin >> month >> day;
			Day my_day2(month, day);
			my_day2.display();
		}
		else if (toupper(option) == 'O')
		{
			cout << " Enter a month and day to start: ";
			string month = "   ";
			int day = 0;
			cin >> month >> day;
			Day my_day3(month, day);
			cout << "(use +/-5 days with --day, ++day, day++, day--):\n";

			for (int i = 0; i < 5; i++)
			{
				--my_day3;
				my_day3.display();
			}

			for (int i = 0; i < 5; i++)
			{
				++my_day3;
				my_day3.display();
			}

			for (int i = 0; i < 5; i++)
			{
				my_day3++;
				my_day3.display();
			}

			for (int i = 0; i < 5; i++)
			{
				my_day3--;
				my_day3.display();
			}
		}
		else if (toupper(option) == 'Q')
			break;
		else
			cout << "Not a valid entry. try again.\n";
		cin.clear();
		cin.ignore(1024, '\n');

	} while (option != 'Q' && option != 'q');
	cout << "\nGoodBye!" << endl;

	return 0;
}

/*


Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 1

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 45

 Day number: [45] febuary 14, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 15

 Day number: [15] january 15, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 100

 Day number: [100] april 10, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 365

 Day number: [365] december 31, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 1000

 Not a valid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): -1000

 Not a valid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 366

 Not a valid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 180

 Day number: [180] june 29, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): -9

 Not a valid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): 0

 Not a valid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): q

 Not a valid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: d
 Enter day of year number (-9 to quit): -9

 Not a valid day entered. Defaulting to day 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: m

 Enter the month and day of month: (stop -9 to quit): jan 1

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: m

 Enter the month and day of month: (stop -9 to quit): jan 15

 Day number: [15] january 15, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: m

 Enter the month and day of month: (stop -9 to quit): march 32

 Not a valid day entered. Defaulting to jan 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: m

 Enter the month and day of month: (stop -9 to quit): dec 32

 Not a valid day entered. Defaulting to jan 1.

 Day number: [1] january 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: o
 Enter a month and day to start: juli 1
(use +/-5 days with --day, ++day, day++, day--):

 Day number: [181] june 30, 2019

 Day number: [180] june 29, 2019

 Day number: [179] june 28, 2019

 Day number: [178] june 27, 2019

 Day number: [177] june 26, 2019

 Day number: [178] june 27, 2019

 Day number: [179] june 28, 2019

 Day number: [180] june 29, 2019

 Day number: [181] june 30, 2019

 Day number: [182] july 1, 2019

 Day number: [183] july 2, 2019

 Day number: [184] july 3, 2019

 Day number: [185] july 4, 2019

 Day number: [186] july 5, 2019

 Day number: [187] july 6, 2019

 Day number: [186] july 5, 2019

 Day number: [185] july 4, 2019

 Day number: [184] july 3, 2019

 Day number: [183] july 2, 2019

 Day number: [182] july 1, 2019

Please pick an option: d)ay [#d->m,d]; m)onth+day [m d->#d]; o)perator [+/-5]; q)uit: q

GoodBye!

--------------------------------
Process exited after 215.6 seconds with return value 0
Press any key to continue . . .



*/