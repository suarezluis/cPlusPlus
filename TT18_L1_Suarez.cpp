// This is how to write a comment
#include <iostream>

using namespace std;

int main()
{

    cout << "\x1B[2J\x1B[H";

    cout << "       *****************************\n";
    cout << "       * Welcome to TT18_L1_Suarez *\n";
    cout << "       *****************************\n\n";

    int currentYear = 0;
    cin >> currentYear;
    cout << "Next Year is: " << ++currentYear << endl;
    cout << "Good-bye!\n";
    return 0;
}