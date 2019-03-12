// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 5:  Population Bar Chart
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << endl
         << endl;
    cout << "                   ****************************************" << endl;
    cout << "                   *         Population Bar Chart         *" << endl;
    cout << "                   *                                      *" << endl;
    cout << "                   *                                      *" << endl;
    cout << "                   *                 LAB5                 *" << endl;
    cout << "                   *                                      *" << endl;
    cout << "                   ****************************************" << endl
         << endl
         << "This Lab calculates makes a graph representation for the data stored in people.txt." << endl
         << endl;

    const string name_of_file = "people.txt"; // Names the string of what the "file name" will be in C++
    ifstream in_file(name_of_file.c_str());   // Names the file to be opened

    if (in_file)
    {
        cout << "File " << name_of_file << "opened successfully!" << endl;
        cout << "File contents: " << endl;

        cout << "\nPRAIRIEVILLE POPULATION GROWTH:\n";

        int year_count = 1900;
        int star_count = 0;

        while (!in_file.eof())
        {

            int population = 0;
            in_file >> population;
            star_count = population / 1000;
            string star_string = " "; // Made a string to output stars on graph

            for (int star_counter = 0; star_counter < star_count; star_counter++)
            {
                star_string += " *"; // loads stars into string
            }

            if (in_file.eof())
            {
                break;
            }

            cout << "\n"
                 << year_count << "  " << star_string << endl;
            year_count += 20;
        }
    }

    else
    {
        cout << "Can't open the file " << name_of_file << endl;
        return 0;
    }

    in_file.close();
    return 0;
}

/*
You have opened people.txt successfully!
File contents:

PRAIRIEVILLE POPULATION GROWTH:

1900    * *

1920    * * * *

1940    * * * * *

1960    * * * * * * * * *

1980    * * * * * * * * * * * * * *

2000    * * * * * * * * * * * * * * * * * *
*/
