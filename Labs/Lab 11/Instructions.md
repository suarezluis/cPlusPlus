For the Chapter 11 lab, combine two of the Programming Challenges at the end of Chapter 11: 2) Day of the Year; and 3) Day of the Year Modification, both on page 768 (7ed), page 786 (8ed), or page 810 (9ed). Do both of these labs in one program. The textbook says: “write a class named DayOfYear”; I used class Day below because it is less typing. Design your class to avoid stale data. Re-read page 400 (7ed) or page 422 (8ed and 9ed) in the textbook: "Avoiding Stale Data". Robust, dependable code will avoid the possibility of redundant, out-of-sync data. You should have only one data member to store one value for the day of the year from 1 to 365.

2. Day of the Year. Use this year: 2019 as your year. Since the year is the same for all days, use a const static int YEAR for all instances. The months of 2019 have the following days: Jan=31; Feb=28; Mar=31; Apr=30; May=31; Jun=30; Jul=31; Aug=31; Sep=30; Oct=31; Nov=30; Dec=31. One way to translate an integer dayOfYear into a month and day is to provide an array daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; In a loop, you can reduce the int dayOfYear by month, until you have month number and day number. Needed is an array: string monthsOfYear[12]; This can be initialized to: {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"}; An enum type, such as: enum month_t {jan, feb, mar, …} can make your code more self-documenting. For simplicity, you can use 3 letters for the month, although you can use full month names if you like. You can avoid uppercase, lowercase when searching for the month for greater flexibility.

Use static member variables to store data common to all instances. The YEAR, daysInMonth array and monthsOfYear array are common to all instances of class Day. You may not be able to initialize static data in the declaration of a class. (It depends on the version of C++.) Initialize static data AFTER the declaration of the class, but BEFORE any instances of the class are created. See program 11-3 as an example of a program that uses static data. Use "const static" for data which is constant and static. These arrays should be public and static. They should not be duplicated for each instance. They can be accessed using the scope resolution operator, as in: Day:: . Because they are const, outside users cannot mess them up.

C++11/14/17 syntax allows you to initialize data members when you declare them in your class. This is not available in earlier compilers.

You can use one of the Day constructors like this:
Day halfway(365/2); // creates an instance of class Day, called halfway, initialized to the day number 182
halfway.print(); // displays the day in “Month, dd” format. This will output something like: "June 30".

3. Day of the Year Modification. Expand on #2) above. Add a constructor that accepts a string for the month and the day of the month. Also write four overloaded operators (++day, --day, day++, day--) so day of year can be incremented and decremented (may jump to the next or previous month). Testing example:
   Day cincoDeMayo("May", 5); // creates a day, which is initialized to the number of the day, May 5th.
   Day restDay = ++cincoDeMayo // increment to next day
   restDay.print(); // displays: "May 6"

See program 11-11 for code that overloads operator++, operator--.
CAUTION! Do not allow your day_of_year to become invalid! Day of the year outside of the range 1-365 are not valid! Decrementing day=1 should not allow day 0, -1, -2, -3, ... What to do? Wrap day 1 "down to" 365, and increment day 365 "up to" day 1. For workload reduction, leave year at 2019.

For testing: Provide a menu-driving testing loop in main(). Allow the user to test various numeric days of the year OR month, day. Verify that valid data is accepted (day number 1 to 365; months Jan to Dec and correct day limit for that month). Test all constructors, operators, getters, setters in class Day.

Invalid data should be rejected by the constructors. If invalid data is detected in a constructor, it is common to “throw an exception”, which can exit the program. We don’t cover error-handling with exceptions (a big topic) in this class. To deal with invalid day (invalid month, day combination), set the day to some valid default. This could be simple, like January 1, or more intelligent, such as setting it to the closest valid date: Feb 31 becomes Feb 28; Jan -5 becomes Jan 1;Juniper, 345 can become: Jan 1.

Test the four operators (++day, --day, day++, day--) by showing the previous five days and the following five days in expanded format. Example:

void test_operators() {

Day bday("jul", 4);

cout<<"start at: "; bday.print(); cout<<endl;

for (int i=0; i<5; ++i) {cout<<" "; (--bday).print();} cout<<endl;

for (int i=0; i<5; ++i) {cout<<" "; (++bday).print();} cout<<endl;

for (int i=0; i<5; ++i) {cout<<" "; (bday++).print();} cout<<endl;

for (int i=0; i<5; ++i) {cout<<" "; (bday--).print();} cout<<endl;

cout<<"end at: "; bday.print(); cout<<endl;

}

Extra credit: (5%): Overload the << operator so when the class is sent to cout (ostream) it prints out the date in expanded format. Example:
cout << cincoDeMayo; // prints out: "May 5"
Can use cout << testDay; as well as: testDay.print(); This makes it easier to output a Day. See code on page 719 (7ed) or page 737 (8ed) or page 745 (9ed).

See the attached file: Lab11_test_output_sample.txt for ideas on how to test your code. If you don’t have time to handle multiple possibilities (such as: month name uppercase, lower-case, abbreviated, etc.) that is OK – just state your assumptions in comments in the code. In the various option, I included a variety of test cases to be sure I tested all class member methods. Test cases in the various option are up to you. It is a good place to test both valid and invalid data. The various test cases should run without further user input.
