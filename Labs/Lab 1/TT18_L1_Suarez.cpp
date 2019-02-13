// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 1:  Provide menu-driven option loop that calculates: restaurant bill; BMI; or quits the loop.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char option;
    while (option != 'q')
    {
        

        cout << "       +---------------------------+\n";
        cout << "       | Welcome to TT18_L1_Suarez |\n";
        cout << "       |---------------------------|\n";
        cout << "       |          OPTIONS          |\n";
        cout << "       |          -------          |\n";
        cout << "       |      (A)mount of Bill     |\n";
        cout << "       |      (B)ody Mass Index    |\n";
        cout << "       |           (Q)uit          |\n";
        cout << "       +---------------------------+\n\n";

        cout << "Please enter an option: ";
        cin >> option;
        option = tolower(option);
        if (option == 'a')
        {
            
            cout << "       +---------------------------+\n";
            cout << "       | Welcome to TT18_L1_Suarez |\n";
            cout << "       |---------------------------|\n";
            cout << "       |       Amount of Bill      |\n";
            cout << "       |       --------------      |\n";
            cout << "       +---------------------------+\n\n";
            cout << "Please enter the cost of the food: $";
            double foodCost = 0;
            cin >> foodCost;
            cout << "Please enter the percentage that you want to tip: ";
            double tipPercentage = 0;
            cin >> tipPercentage;
            const double TAX_RATE = 0.0825;

            // Calculating the total cost: cost of food + tax + tip (before taxes)

            double totalBill = foodCost * (1 + TAX_RATE) + (foodCost * tipPercentage / 100);
            cout << fixed << "The total bill is: $" << setprecision(2) << totalBill << endl;
            cout << "\n\n\nENTER ANY CHARACTER TO CONTINUE : ";
            char temp;
            cin >> temp;
        }

        if (option == 'b')
        {
            
            cout << "       +---------------------------+\n";
            cout << "       | Welcome to TT18_L1_Suarez |\n";
            cout << "       |---------------------------|\n";
            cout << "       |    Body Mass Calculator   |\n";
            cout << "       |    --------------------   |\n";
            cout << "       +---------------------------+\n\n";
            cout << "Please enter height in inches: ";
            int heightInches = 0;
            cin >> heightInches;
            cout << "Please enter weight in pounds: ";
            int weightPounds = 0;
            cin >> weightPounds;
            double bmi = ((float)weightPounds / (heightInches * heightInches)) * 703;

            cout << "The Body Mass Index (BMI) is: " << fixed << setprecision(2) << bmi << endl;
            cout << "\n\n\nENTER ANY CHARACTER TO CONTINUE : ";
            char temp;
            cin >> temp;
        }

        if (option == 'q')
        {
            return 0;
        }
    }
}

/* TEST OUTPUT 

Menu
=======================================

       +---------------------------+
       | Welcome to TT18_L1_Suarez |
       |---------------------------|
       |          OPTIONS          |
       |          -------          |
       |      (A)mount of Bill     |
       |      (B)ody Mass Index    |
       |           (Q)uit          |
       +---------------------------+

Please enter an option:

=======================================

Amount of Bill
=======================================

       +---------------------------+
       | Welcome to TT18_L1_Suarez |
       |---------------------------|
       |       Amount of Bill      |
       |       --------------      |
       +---------------------------+

Please enter the cost of the food: $156
Please enter the percentage that you want to tip: 20
The total bill is: $200.07



ENTER ANY CHARACTER TO CONTINUE :

=======================================

Body Mass Calculator
=======================================

       +---------------------------+
       | Welcome to TT18_L1_Suarez |
       |---------------------------|
       |    Body Mass Calculator   |
       |    --------------------   |
       +---------------------------+

Please enter height in inches: 68
Please enter weight in pounds: 162
The Body Mass Index (BMI) is: 24.63



ENTER ANY CHARACTER TO CONTINUE :

=======================================


*/

