// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 4:  Calculate the distance.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// for getting a letter
char input(string input_text, string error_message)
{
    char letter;
    while (true)
    {
        cout << "  Please enter the " << input_text << " letter: ";
        cin >> letter;
        letter = tolower(letter);
        int ascii = int(letter);

        if (ascii >= 97 and ascii <= 122)
        {
            return letter;
        }
        cout << error_message << endl;
    }
};
// for getting a number
double input(double min, double max, string input_text, string error_message)
{
    double number;
    while (true)
    {

        cout << "  Please enter the " << input_text << " number ( " << min << " , " << max << " ): ";
        cin >> number;

        if (number >= min and number <= max)
        {
            return number;
        }
        cout << error_message << endl;
    }
};
// for getting a point (x, y)
void input(double &x, double &y, string input_text)
{
    while (true)
    {
        cout << "  Please enter the " << input_text << " point (x) (-100 , 100): ";
        cin >> x;
        if (x >= -100 and x <= +100)
        {
            while (true)
            {
                cout << "  Please enter the " << input_text << " point (y) (-100 , 100): ";
                cin >> y;
                if (y >= -100 and y <= +100)
                {
                    return;
                }
                cout << "  Please enter a point value within range" << endl;
            }
        }
        cout << "  Please enter a point value within range" << endl;
    }
};
// return the distance between two letters (a-z)
int dist(char a, char b)
{
    return abs(int(a) - int(b));
};
// return the distance between two numbers
double dist(double d1, double d2)
{
    return abs(d1 - d2);
};
// return distance between two points.
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
};
// display letters and letter distance
void display(string msg, char ch1, char ch2)
{
    static int count;
    ++count;
    cout << "    (#" << count << ") " << msg << ch2 << " and " << ch1 << " = " << dist(ch1, ch2);
};
// display numbers and number distance
void display(const string msg, double d1, double d2)
{
    static int count;
    ++count;
    cout << "    (#" << count << ") " << msg << d2 << " and " << d1 << " = " << dist(d1, d2);
};
// display points and point distance.
void display(const string msg, double x1, double y1, double x2, double y2)
{
    static int count;
    ++count;
    cout << "    (#" << count << ") " << msg << " (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") = " << dist(x1, y1, x2, y2);
};
int main()
{
    cout << endl
         << endl;
    cout << "               ****************************************" << endl;
    cout << "               *        Calculate the distance        *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               *                 LAB6                 *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               ****************************************" << endl
         << endl
         << "This Lab calculates the distance betwen letters,numbers and points in a graph." << endl;
    bool running{true};
    char option{};
    while (running)
    {
        while (true)
        {
            cout << endl
                 << endl
                 << "Options: l)etter; n)umber; p)oint; q)uit: ";
            cin >> option;
            if (option == 'q')
            {
                return 0;
            }
            if (option != 'l' and option != 'n' and option != 'p')
            {
                cout << "Invalid option please try again";
            }
            else
            {
                break;
            }
        }
        double x1{};
        double y1{};
        double x2{};
        double y2{};
        switch (option)
        {
        case 'l':
            display("Distance between letters ", input("second", "Please enter a letter from a to z"), input("first", "Please enter a letter from a to z"));
            break;
        case 'n':
            display("Units between", input(-200, 200, "second", "Please enter a number in the range"), input(-100, 100, "first", "Please enter a number in the range"));
            break;
        case 'p':
            input(x1, y1, "first");
            input(x2, y2, "second");
            display("Straight line distance between points ", x1, y1, x2, y2);
        }
    };
}
/*
               ****************************************
               *        Calculate the distance        *
               *                                      *
               *                                      *
               *                 LAB6                 *
               *                                      *
               ****************************************

This Lab calculates the distance betwen letters,numbers and points in a graph.


Options: l)etter; n)umber; p)oint; q)uit: l
  Please enter the first letter: b
  Please enter the second letter: f
    (#1) Distance between letters b and f = 4

Options: l)etter; n)umber; p)oint; q)uit: n
  Please enter the first number ( -100 , 100 ): -5.5
  Please enter the second number ( -200 , 200 ): 20.5
    (#1) Units between-5.5 and 20.5 = 26

Options: l)etter; n)umber; p)oint; q)uit: p
  Please enter the first point (x) (-100 , 100): 0
  Please enter the first point (y) (-100 , 100): 3
  Please enter the second point (x) (-100 , 100): 4
  Please enter the second point (y) (-100 , 100): 0
    (#1) Straight line distance between points  (0,3) and (4,0) = 5

Options: l)etter; n)umber; p)oint; q)uit: l
  Please enter the first letter: 8
Please enter a letter from a to z
  Please enter the first letter: A
  Please enter the second letter: z
    (#2) Distance between letters a and z = 25

Options: l)etter; n)umber; p)oint; q)uit: n
  Please enter the first number ( -100 , 100 ): -123.456
Please enter a number in the range
  Please enter the first number ( -100 , 100 ): -10
  Please enter the second number ( -200 , 200 ): 50
    (#2) Units between-10 and 50 = 60

Options: l)etter; n)umber; p)oint; q)uit: p
  Please enter the first point (x) (-100 , 100): 0
  Please enter the first point (y) (-100 , 100): 0
  Please enter the second point (x) (-100 , 100): 1
  Please enter the second point (y) (-100 , 100): 1
    (#2) Straight line distance between points  (0,0) and (1,1) = 1.41421

Options: l)etter; n)umber; p)oint; q)uit: q

--------------------------------
Process exited after 136.1 seconds with return value 0
Press any key to continue . . .
*/
