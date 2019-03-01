// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 4:  The Speed of Sound.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    cout << endl
         << endl;
    cout << "               ****************************************" << endl;
    cout << "               *          The Speed of Sound          *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               *                 LAB4                 *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               ****************************************" << endl
         << endl
         << "       This Lab calculates the speed of sound in given materials." << endl;
    vector<string> materials{};
    vector<string> speeds{};
    ifstream inFile;
    // string filename="junk.txt";
    string filename = "TT18_L4_Suarez_In.txt";
    // inFile.open("tt17.txt");
    inFile.open(filename);

    if (inFile)
    {
        string in_string;
        int counter = 0;
        while (true)
        {
            // while(not inFile.eof()) {
            inFile >> in_string;
            if (inFile.eof())
                break;
            if (counter % 2 == 0)
            {
                //				cout<<"-"<<counter / 2.<<"-";
                //				cout<<in_string;
                materials.push_back(in_string);
            }
            else
            {

                speeds.push_back(in_string);
            }
            ++counter;
        }

        // if (in_string=="**stop**") break;
    }

    else
    {
        // cout<<"The file: ttt13.txt, did not open.\n";
        cout << "The file: " << filename << " did not open.\n";
        // cout<<"Error occurred.\n";
    }

    inFile.close(); // recommended
    bool running{true};

    //    cout << "option=" << static_cast<char>('') << endl;

    while (running)
    {
        cout << endl
             << "                    List of available materials:" << endl
             << endl
             << "                              0) Quit at any time";
        for (int index = 1; index < static_cast<int>(materials.size()); index++)
        {
            cout << endl
                 << "                              " << index << ") " << materials[index];
        }
        cout << endl;
        int option = -1;

        while (true)
        {
            cout << endl
                 << "                Please select a option from 0 to " << static_cast<int>(materials.size()) - 1 << " : ";
            cin >> option;

            if (option == 0)
            {
                return 0;
            }
            if (option > 0 and option < static_cast<int>(materials.size()))

            {
                break;
            }
            cout << endl
                 << "                INVALID - OPTION, please try again..." << endl;
        }
        double distance{};
        while (true)
        {

            cout << endl
                 << "    Please enter the distance (feets) for sound to travel in " << materials[option] << " : ";
            cin >> distance;
            if (distance > 0)
            {
                break;
            }
            if (distance == 0)
            {
                return 0;
            }
            cout << endl
                 << "                INVALID - DISTANCE, please try again..." << endl;
        }

        double time{};
        time = distance / stoi(speeds[option]);
        cout << endl
             << "------------------------------------------------------------------------" << endl;
        cout << endl
             << "        For sound to cover " << distance << " feet in" << materials[option] << ", it takes " << fixed << setprecision(2) << time << " seconds" << endl;
        cout << endl
             << "------------------------------------------------------------------------" << endl;
    }
}

/*


               ****************************************
               *          The Speed of Sound          *
               *                                      *
               *                                      *
               *                 LAB4                 *
               *                                      *
               ****************************************

       This Lab calculates the speed of sound in given materials.

                    List of available materials:

                              0) Quit at any time
                              1) Air
                              2) Water
                              3) Steel
                              4) Copper
                              5) Nylon
                              6) Iron

                Please select a option from 0 to 6 : 1

    Please enter the distance (feets) for sound to travel in Air : 1000

------------------------------------------------------------------------

        For sound to cover 1000 feet inAir, it takes 0.91 seconds

------------------------------------------------------------------------

                    List of available materials:

                              0) Quit at any time
                              1) Air
                              2) Water
                              3) Steel
                              4) Copper
                              5) Nylon
                              6) Iron

                Please select a option from 0 to 6 : 2

    Please enter the distance (feets) for sound to travel in Water : 1000

------------------------------------------------------------------------

        For sound to cover 1000.00 feet inWater, it takes 0.20 seconds

------------------------------------------------------------------------

                    List of available materials:

                              0) Quit at any time
                              1) Air
                              2) Water
                              3) Steel
                              4) Copper
                              5) Nylon
                              6) Iron

                Please select a option from 0 to 6 : 3

    Please enter the distance (feets) for sound to travel in Steel : 1000

------------------------------------------------------------------------

        For sound to cover 1000.00 feet inSteel, it takes 0.06 seconds

------------------------------------------------------------------------

                    List of available materials:

                              0) Quit at any time
                              1) Air
                              2) Water
                              3) Steel
                              4) Copper
                              5) Nylon
                              6) Iron

                Please select a option from 0 to 6 : 4

    Please enter the distance (feets) for sound to travel in Copper : 1000

------------------------------------------------------------------------

        For sound to cover 1000.00 feet inCopper, it takes 0.13 seconds

------------------------------------------------------------------------

                    List of available materials:

                              0) Quit at any time
                              1) Air
                              2) Water
                              3) Steel
                              4) Copper
                              5) Nylon
                              6) Iron

                Please select a option from 0 to 6 : 5

    Please enter the distance (feets) for sound to travel in Nylon : 1000

------------------------------------------------------------------------

        For sound to cover 1000.00 feet inNylon, it takes 0.87 seconds

------------------------------------------------------------------------

                    List of available materials:

                              0) Quit at any time
                              1) Air
                              2) Water
                              3) Steel
                              4) Copper
                              5) Nylon
                              6) Iron

                Please select a option from 0 to 6 : 6

    Please enter the distance (feets) for sound to travel in Iron : 1000

------------------------------------------------------------------------

        For sound to cover 1000.00 feet inIron, it takes 0.12 seconds

------------------------------------------------------------------------

                    List of available materials:

                              0) Quit at any time
                              1) Air
                              2) Water
                              3) Steel
                              4) Copper
                              5) Nylon
                              6) Iron

                Please select a option from 0 to 6 : 7

                INVALID - OPTION, please try again...

                Please select a option from 0 to 6 : -1

                INVALID - OPTION, please try again...

                Please select a option from 0 to 6 : 6

    Please enter the distance (feets) for sound to travel in Iron : -1

                INVALID - DISTANCE, please try again...

    Please enter the distance (feets) for sound to travel in Iron : 0

--------------------------------
Process exited after 72.22 seconds with return value 0
Press any key to continue . . .



*/
