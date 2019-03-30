/*
  Name: Luis Suarez Harasic
  COSC 1337 Spring 2019 Sections: TT13, TT17
  Exam 1, Programming portion
  When complete: Change course designator in filename from DDHH to TT13, TT17;
                 Change "Lastname" to your lastname.
  Upload file TT13_X1_Lastname.cpp or TT17_X1_Lastname.cpp
  to BlackBoard Assignment link.
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
using namespace std;

/* INSTRUCTIONS:
  There are 4 regular steps and 1 extra credit.
  Some algorithms and IPOs (Input, Processing, Output) are provided. Usually, "input"
  is not keyboard input from the user; it is almost always a function parameter.
  
  Step 1. (10 points)
  A common programming task is to get numerical input from the user.
  Write a single function that will:
    1) Display a prompt
    2) Get user's input (from keyboard)
    3) Verify that the input is valid (within a range, inclusive)
    4) If the input is valid, accept it and return
    5) If the input is invalid, display an error message and try again

    Create a new function that performs the steps above. Use the following:
      1) Function name: get_input
      2) Parameter: prompt         (pass by constant reference)
      3) Parameter: error_msg      (pass by constant reference)
      4) Parameter: min_value      (pass by value)
      5) Parameter: max_value;     (pass by value)
      6) Parameter: range_check (true or false)     (pass by value)
      7) return: value

  Function get_input() should provide error checking that detects non-numeric input.
  If parameter range_check is true, display the valid range after the prompt so the
  user knows what range of values is acceptable and provide range checking; otherwise,
  don't provide range checking. Usually range checking is desired; provide a default.
  Hints: 1) if (cin>>value) { } else { }; 2) cin.clear(); 3) cin.ignore();


  Step 2. (10 points)
    Test the function get_input() by asking the user for their birthday. Call it
    3 times to get: month, day, year. Provide a valid range for each. Assume a
    valid day is 1 to 31, month is 1 to 12, year is from 1900 to 2018. For now,
    don't worry about the number of days each month has; that comes later.


  Step 3. (10 points)
    Despite input validation, it is possible the user entered the wrong information.
    Give the user an opportunity to verify and correct invalid input. Create a loop
    that displays the person's birthday as entered in MM/DD/YYYY format. Example: 7/4/1776
    On ONE line, display the entered date, followed by a menu of options:
      birthday is 7/4/1776  Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse?
    The options should do this:
      m)onth   : reenter the month;
      d)ay     : reenter the day;
      y)ear    : reenter the year;
      a)ccept  : user claims data is correct, accept date as entered and exit loop
      r)efuse  : user does NOT want to enter a birthday. Set date to 0/0/0000, exit loop
      
    In main, get the user's birthday. Loop as described above to accept changes.
    Accept upper and lower case. Use a switch statement for the options.


  Step 4. (10 points)
    With get_input, each part of a date may be in range, but the complete birthday
    may be invalid. Perhaps it has an invalid number of days for the month.

    Enhance your birthday validation process to verify that the number of days is valid
    for the number of the month. Do NOT modify the get_input function, keep that generic.
    Create a new function, isvalid_day_month().  Here is the IPO:
      Inputs:      number of day, number of month
      Processing:  compute whether the day, month combination is valid. Use a switch statement.
      Output:      boolean: return true if valid, false if invalid
      Use these limits: (you can copy/paste/edit the line below to save time):
        const int Jan=31, Feb=28, Mar=31, Apr=30, May=31, Jun=30, Jul=31, Aug=31, Sep=30, Oct=31, Nov=30, Dec=31;

    Call isvalid_day_month() in Step 3 code as appropriate. If user a)ccepts, but date is invalid,
    don't accept; display error and retry. If user refuses to enter date, don't validate, exit loop.


  Step 5. (2 points) EXTRA CREDIT, OPTIONAL
    To provide an incentive for your user to enter a valid date, give the user a chance
    to win a prize. After a valid date is entered, see if the user won a prize. If user
    refused, no prize is offered.

    Create a new function, won_prize() Here is the IPO:
      Input:     1 in n odds of winning the prize.
                 Example: won_prize(100); // 1 in 100 chance of winning
                 Example: won_prize(10);  // 1 in 10 chance of winning
                 Example: won_prize(2);   // 1 in 2 chance of winning
      Processing: Calculate whether the person won the prize
      Output:     true if they won the prize, false if not
    
    In main, after the user entered a valid date, call won_prize() with a 1 in 100
    chance of winning. Notify the user whether they won or not.
    Hint: use time(), srand(), rand(), %. Important: ONLY call srand() ONCE!


  Step 6. (2 points) EXTRA CREDIT, OPTIONAL
    Your boss is worried that the program may award too many prizes. To verify the prize
    award process, test it. Simulate running the prize award function 10,000 times. In
    10,000 times, how many times was a prize won? Print the output to convince your boss
    that it works. The output should be: "Of 10,000 attempts, 125 won: 1.25 percent."
*/

// step 1 (10 points) function get_input() goes here ---
int get_input(const string &prompt, const string &error_msg, int min_value, int max_value, bool range_check)
{

  int value;
  while (true)
  {
    cout << prompt;
    cin >> value;
    if (value >= min_value and value <= max_value)
    {
      return value;
    }
    cout << error_msg << endl;
  }
}; // modify as appropriate

// step 4 (10 points) function isvalid_day_month() goes here ---
bool isvalid_day_month(int day, int month)
{
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (day == 0 and month == 0)
    return true;

  if (day < 1 or month < 0 or month > 12)
    return false;

  if (day > days_in_month[month - 1])
    return false;

  return true;

}; // edit as appropriate

bool won_prize(int n)
{
  int random = rand() % n + 1;

  if (random == n)
  {
    return true;
  }

  return false;
}

int main()
{
  // Generate seed

  cout << "COSC 1337 Exam 1 Lab Portion" << endl;

  // step 2 (10 points) 3 calls to get_input() goes here ---
  int month = get_input("Please enter your bithday's month:", "Input invalid", 1, 12, true);
  int day = get_input("Please enter your bithday's day:", "Input invalid", 1, 31, true);
  int year = get_input("Please enter your bithday's year:", "Input invalid", 1900, 2018, true); // edit as appropriate

  // step 3 (10 points) loop to enter and reenter birthday until valid
  char option = ' ';
  while (option != 'a')
  {
    cout << "Birthday is " << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << "/" << year << " Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? ";
    cin >> option;
    switch (tolower(option))
    {
    case 'm':
      month = get_input("Please enter your bithday's month:", "Input invalid", 1, 12, true);
      break;
    case 'd':
      day = get_input("Please enter your bithday's day:", "Input invalid", 1, 31, true);
      break;
    case 'y':
      year = get_input("Please enter your bithday's year:", "Input invalid", 1900, 2018, true);
      break;
    case 'a':
      if (!isvalid_day_month(day, month))
      {
        option = ' ';
        cout << "Invalid date try again ..." << endl;
      }

      break;
    case 'r':
      option = 'a';
      month = 0;
      day = 0;
      year = 0;
      break;
    default:
      cout << "Invalid option, try again..." << endl;
      break;
    }
  }
  // step 4's call to isvalid_day_month (enhancement to step 3)

  // step 5 (3 points, optional extra credit) call to won_prize() if user entered valid birthday
  srand(time(NULL));
  string message = "";
  if (option = 'a' and day != 0)
  {
    if (won_prize(100))
    {
      message = "You won a prize!";
    }
    else
    {
      message = "You did not win a prize.";
    }

    cout << message << endl;
  }
  // step 6 (2 points, optional extra credit) test if won_prize() in loop of 10,000
  int won = 0;
  for (double try_number = 0; try_number < 10000; try_number++)
  {
    if (won_prize(100))
    {
      ++won;
    }
  }

  cout << "Of 10,000 attempts, " << won << " won: " << fixed << setprecision(2) << 100 * static_cast<double>(won) / 10000 << " percent." << endl;
  cout
      << endl
      << "Goodbye!" << endl; // this should appear as the last line of your output
  return 0;                  //EXIT_SUCCESS;        // Use return 0 if EXIT_SUCCESS is undefined
}

/*
  Paste your test output here

COSC 1337 Exam 1 Lab Portion
Please enter your bithday's month:03
Please enter your bithday's day:29
Please enter your bithday's year:1981
Birthday is 03/29/1981 Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? a
You did not win a prize.
Of 10,000 attempts, 90 won: 0.90 percent.

Goodbye!

--------------------------------
Process exited after 8.242 seconds with return value 0
'\\NRGCOIS-FP0\FolderRedirect\7133805\Desktop'
CMD.EXE was started with the above path as the current directory.
UNC paths are not supported.  Defaulting to Windows directory.
Press any key to continue . . .

COSC 1337 Exam 1 Lab Portion
Please enter your bithday's month:0
Input invalid
Please enter your bithday's month:03
Please enter your bithday's day:2
Please enter your bithday's year:1981
Birthday is 03/02/1981 Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? m
Please enter your bithday's month:2
Birthday is 02/02/1981 Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? d
Please enter your bithday's day:31
Birthday is 02/31/1981 Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? a
Invalid date try again ...
Birthday is 02/31/1981 Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? r
Of 10,000 attempts, 103 won: 1.03 percent.

Goodbye!

--------------------------------
Process exited after 35.77 seconds with return value 0
'\\NRGCOIS-FP0\FolderRedirect\7133805\Desktop'
CMD.EXE was started with the above path as the current directory.
UNC paths are not supported.  Defaulting to Windows directory.
Press any key to continue . . .

COSC 1337 Exam 1 Lab Portion
Please enter your bithday's month:03
Please enter your bithday's day:29
Please enter your bithday's year:1981
Birthday is 03/29/1981 Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? y
Please enter your bithday's year:2019
Input invalid
Please enter your bithday's year:2019
Input invalid
Please enter your bithday's year:2018
Birthday is 03/29/2018 Options: CHANGE: m)onth, d)ay, y)ear; OR a)ccept, r)efuse? a
You did not win a prize.
Of 10,000 attempts, 115 won: 1.15 percent.

Goodbye!

--------------------------------
Process exited after 23.96 seconds with return value 0
'\\NRGCOIS-FP0\FolderRedirect\7133805\Desktop'
CMD.EXE was started with the above path as the current directory.
UNC paths are not supported.  Defaulting to Windows directory.
Press any key to continue . . .

*/
