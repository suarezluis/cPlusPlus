// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 5:  Population Bar Chart
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
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
         << " This Lab calculates makes a graph representation for the data stored in people.txt." << endl
         << endl;

    const string name_of_file = "people.txt";
    ifstream in_file(name_of_file.c_str());

    if (in_file)
    {
        cout << " File " << name_of_file << " opened successfully!" << endl;

        cout << endl
             << " PRAIRIEVILLE POPULATION GROWTH:" << endl
             << endl;

        vector<int> dataVector;
        int data{};
        int maxPopulation = 0;
        while (!in_file.eof())
        {
            in_file >> data;

            dataVector.push_back(data);
            if (data > maxPopulation)
            {
                maxPopulation = data;
            }
        }

        vector<int> yearsVector;
        int year = 1900;
        for (int index = 0; index < dataVector.size(); index++)
        {
            yearsVector.push_back(year);
            year += 20;
        }

        for (int population = maxPopulation; population >= 1000; population -= 1000)
        {
            cout << setw(6) << population;
            for (int year = 0; year < yearsVector.size() - 1; year++)
            {
                if (dataVector[year] >= population)
                {
                    cout << "  XX  ";
                }
                else
                {
                    cout << "      ";
                }
            }
            cout << endl;
        }
        cout << "      ";
        for (int year = 0; year < yearsVector.size() - 1; year++)
        {
            cout << " " << yearsVector[year] << " ";
        }
        cout << endl;
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


                   ****************************************
                   *         Population Bar Chart         *
                   *                                      *
                   *                                      *
                   *                 LAB5                 *
                   *                                      *
                   ****************************************

 This Lab calculates makes a graph representation for the data stored in people.txt.

 File people.txt opened successfully!

 PRAIRIEVILLE POPULATION GROWTH:

 21000                                            XX
 20000                                            XX
 19000                                      XX    XX
 18000                                XX    XX    XX    XX
 17000                                XX    XX    XX    XX
 16000                                XX    XX    XX    XX
 15000                                XX    XX    XX    XX    XX
 14000                          XX    XX    XX    XX    XX    XX
 13000                          XX    XX    XX    XX    XX    XX
 12000                          XX    XX    XX    XX    XX    XX
 11000                          XX    XX    XX    XX    XX    XX
 10000                          XX    XX    XX    XX    XX    XX
  9000                    XX    XX    XX    XX    XX    XX    XX
  8000                    XX    XX    XX    XX    XX    XX    XX
  7000                    XX    XX    XX    XX    XX    XX    XX    XX
  6000                    XX    XX    XX    XX    XX    XX    XX    XX
  5000              XX    XX    XX    XX    XX    XX    XX    XX    XX
  4000        XX    XX    XX    XX    XX    XX    XX    XX    XX    XX
  3000        XX    XX    XX    XX    XX    XX    XX    XX    XX    XX    XX
  2000  XX    XX    XX    XX    XX    XX    XX    XX    XX    XX    XX    XX
  1000  XX    XX    XX    XX    XX    XX    XX    XX    XX    XX    XX    XX    XX
       1900  1920  1940  1960  1980  2000  2020  2040  2060  2080  2100  2120  2140

--------------------------------
Process exited after 0.357 seconds with return value 0
Press any key to continue . . .
*/
