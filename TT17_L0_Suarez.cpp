// This is how to write a comment
#include <iostream>
using namespace std;

int main()
{
    cout << "What is the current year? ";
    int currentYear = 0;
    cin >> currentYear;
    cout << "Next Year is: " << ++currentYear << endl;
    cout << "Good-bye!\n";
    return 0;
}