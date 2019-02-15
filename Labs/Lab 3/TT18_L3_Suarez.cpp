// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 3:  Math Tutor.

#include <iostream>
#include <cstdlib> // Header file needed to use srand and rand
#include <ctime>   //II Header file needed to use time

using namespace std;

int main()
{
    cout << endl
         << endl;
    cout << "               +-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/" << endl;
    cout << "               +                M A T H               +" << endl;
    cout << "               -                 TUTOR                -" << endl;
    cout << "               *                                      *" << endl;
    cout << "               /                 LAB 2                /" << endl;
    cout << "               +                                      +" << endl;
    cout << "               +-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/+-*/" << endl
         << endl;

    int correct = 0;
    int wrong = 0;
    int percentage = 100;
    while (true)
    {
        unsigned seed; //Random generator seed

        //II Use the time funct i on to get a "seed" value for srand
        seed = time(0);
        srand(seed);

        int operationIndex = 0; // Operation: 0: + 1: - 2:* 3:/
        char operationSymbol = '+';
        int randomA = 0;
        int randomB = 0;
        int answer = -1;

        while (answer < 0 || answer > 100)
        {
            operationIndex = rand() % 3 + 1;
            randomA = rand() % 100 + 1;
            randomB = rand() % 100 + 1;

            //Make sure division by zero never happens.
            while (randomB == 0 && operationIndex == 3)
            {
                randomB = rand() % 100 + 1;
            }
            //Make sure the answer to a division is an integer
            while (operationIndex == 3 && (randomA % randomB != 0 || randomA == randomB || randomB == 1))
            {
                randomA = rand() % 100 + 1;
                randomB = rand() % 100 + 1;
            }

            // Matching operator index with symbol and evaluating operation
            switch (operationIndex)
            {
            case 0:
                operationSymbol = '+';
                answer = randomA + randomB;
                break;
            case 1:
                operationSymbol = '-';
                answer = randomA - randomB;
                break;
            case 2:
                operationSymbol = 'x';
                answer = randomA * randomB;
                break;
            case 3:
                operationSymbol = '/';
                answer = randomA / randomB;
                break;
            }
        }
        // Asking question.
        cout
            << endl
            << "Enter a sentinel number to quit (-1) or;" << endl
            << "Please solve the following operation: " << randomA << " " << operationSymbol << " " << randomB << " = ";
        int userAnswer = 0;
        cin >> userAnswer;
        // If answer is correct increase correct counter
        if (userAnswer == answer && (userAnswer >= 0 && userAnswer <= 100))
        {
            correct++;
        }
        // If answer is incorrect increase wrong counter
        if (userAnswer != answer && (userAnswer >= 0 && userAnswer <= 100))
        {
            wrong++;
        }

        // Calculate percentage only if incorrect answers are different than zero, if zero then percentage is 100%
        if (wrong > 0)
        {
            percentage = (correct * 100) / (correct + wrong);
        }

        // If answer is a sentinel quit qithout counting that answer and show final stats.
        if (userAnswer < 0 || userAnswer > 100)
        {
            // Show results only if at least one question has been answered
            if (correct + wrong > 0)
            {
                cout << endl
                     << "===============================================" << endl;
                cout << "                 Final Score" << endl;
                cout << "===============================================" << endl
                     << endl;
                // If correct percentage is more than 75 do not advice more studying
                if (percentage >= 75)
                {
                    cout << "Final Score: " << percentage << "% Good Job!." << endl;
                }
                // If correct percentage is less than 75, advice more studying
                else
                {
                    cout << "Final Score: " << percentage << "% More studying is recommended." << endl;
                }
            }

            return 0;
        }

        // If answer is correct display correct and answer
        if (userAnswer == answer)
        {

            cout << endl
                 << "Correct! the answer is " << answer << endl;
        }
        // If answer is incorrect display wrong and correct answer
        else
        {

            cout << endl
                 << "Incorrect, the answer is " << answer << endl;
        }
        // Display statistics
        cout << "Correct answers: " << correct << endl
             << "Incorrect answers:" << wrong << endl
             << endl;
        // If correct percentage is more than 75 do not advice more studying
        if (percentage >= 75)
        {
            cout << "You answered correctly " << percentage << "% of the questions." << endl;
        }
        // If correct percentage is less than 75, advice more studying
        else
        {
            cout << "You answered correctly " << percentage << "% of the questions. more studying is recommended." << endl;
        }
    }
}

/* TEST OUTPUT 


//               ****************************************
//               +                M A T H               +
//               -                 TUTOR                -
//               *                                      *
//               /                 LAB 2                /
//               +                                      +
//               ****************************************


Enter a sentinel number to quit (-1) or;
Please solve the following operation: 98 / 49 = 2

Correct! the answer is 2
Correct answers: 1
Incorrect answers:0

You answered correctly 100% of the questions.

Enter a sentinel number to quit (-1) or;
Please solve the following operation: 69 / 23 = 0

Incorrect, the answer is 3
Correct answers: 1
Incorrect answers:1

You answered correctly 50% of the questions. more studying is recommended.

Enter a sentinel number to quit (-1) or;
Please solve the following operation: 100 / 10 = 10

Correct! the answer is 10
Correct answers: 2
Incorrect answers:1

You answered correctly 66% of the questions. more studying is recommended.

Enter a sentinel number to quit (-1) or;
Please solve the following operation: 66 x 1 = 66

Correct! the answer is 66
Correct answers: 3
Incorrect answers:1

You answered correctly 75% of the questions.

Enter a sentinel number to quit (-1) or;
Please solve the following operation: 21 / 3 = 100

Incorrect, the answer is 7
Correct answers: 3
Incorrect answers:2

You answered correctly 60% of the questions. more studying is recommended.

Enter a sentinel number to quit (-1) or;
Please solve the following operation: 15 / 5 = -1

===============================================
                 Final Score
===============================================

Final Score: 60% More studying is recommended.

--------------------------------
Process exited after 45.9 seconds with return value 0
Press any key to continue . . .

 


*/
