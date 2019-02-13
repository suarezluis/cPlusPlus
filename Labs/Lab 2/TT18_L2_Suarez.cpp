// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 2:  Diamond pattern.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int option = 1;
    while (option != 0)
    {

        cout << "Please enter the line size of the diamond or Q to quit: ";
        cin >> option;

//        int optionInt = stoi(option);
        

        for (int i = 1; i <= option; i += 2)
        {
            cout << string((option - i) / 2, ' ');
            cout << string(i, '*') << endl;
        }
        for (i = option; i >= 1; i -= 2)
        {
            cout << string((option - i) / 2, ' ');
            cout << string(i, '*') << endl;
        }
       
    }
}

/* TEST OUTPUT 



*/
