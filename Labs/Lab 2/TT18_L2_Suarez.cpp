// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 2:  Diamond pattern.

#include <iostream>
using namespace std;

int main()
{
    cout << endl
         << endl;
    cout << "               ****************************************" << endl;
    cout << "              *    *            PYRAMID           *    *" << endl;
    cout << "             *    ***            MAKER           ***    *" << endl;
    cout << "            *    *****                          *****    *" << endl;
    cout << "             *    ***            LAB 2           ***    *" << endl;
    cout << "              *    *                              *    *" << endl;
    cout << "               ****************************************" << endl
         << endl
         << endl;

    int option = 1;
    while (option > 0)
    {

        cout << endl
             << "Please enter the line size of the diamond or 0 to quit: ";
        cin >> option;
        cout << endl;

        //		 Top half of the rhombus.

        for (int i = 1; i < option; i += 2)
        {
            cout << string((option - i) / 2, ' ');
            cout << string(i, '*') << endl;
        }

        //         Middle part of the rhombus.

        if (option % 2 > 0)
        {
            cout << string(option, '*') << endl;
        }

        //      	Bottom part of the rombus

        for (int i = 1; i < option; i += 2)
        {
            cout << string((i - 1) / 2 + (option % 2), ' ');
            cout << string((option - i - (option % 2)), '*') << endl;
        }
    }
}

/* TEST OUTPUT 


               ****************************************
              *    *            PYRAMID           *    *
             *    ***            MAKER           ***    *
            *    *****                          *****    *
             *    ***            LAB 2           ***    *
              *    *                              *    *
               ****************************************




Please enter the line size of the diamond or 0 to quit: 1

*

Please enter the line size of the diamond or 0 to quit: 2

*
*

Please enter the line size of the diamond or 0 to quit: 3

 *
***
 *

Please enter the line size of the diamond or 0 to quit: 4

 *
***
***
 *

Please enter the line size of the diamond or 0 to quit: 5

  *
 ***
*****
 ***
  *

Please enter the line size of the diamond or 0 to quit: 6

  *
 ***
*****
*****
 ***
  *

Please enter the line size of the diamond or 0 to quit: 7

   *
  ***
 *****
*******
 *****
  ***
   *

Please enter the line size of the diamond or 0 to quit: 8

   *
  ***
 *****
*******
*******
 *****
  ***
   *

Please enter the line size of the diamond or 0 to quit: 9

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *

Please enter the line size of the diamond or 0 to quit: 0


--------------------------------
Process exited after 16.41 seconds with return value 0
Press any key to continue . . .


*/

