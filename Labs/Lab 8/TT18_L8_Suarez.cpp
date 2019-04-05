// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 8: Tic-Tac-Toe.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <typeinfo>
using namespace std;

template <typename T>
T get_value(const string &prompt = "enter value: ",
            const string &errmsg = "  invalid, try again\n",
            T value_min = INT_MIN, T value_max = INT_MAX, bool range_check = true)
{
  T value{};
  while (true)
  {
    if (prompt != "")
      cout << prompt;
    if (cin >> value and (!range_check or (value >= value_min and value <= value_max)))
      return value;
    else
    {
      cin.clear();
      cin.ignore(INT_MAX, '\n');
      if (errmsg != "")
        cout << errmsg;
    }
  }
}

class ttt
{
private:
  char board[3][3]{{'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'}};
  // moves counter to stablish if player 1 or player 2
  int moves = 0;
  // translate number into coordinates
  bool convert(int move, int &row, int &col)
  {
    // assume 3x3 board, convert move 1 to 9 to row 0-2, col 0-2
    switch (move)
    {
    case 1:
    case 2:
    case 3:
      row = 2;
      break;
    case 4:
    case 5:
    case 6:
      row = 1;
      break;
    case 7:
    case 8:
    case 9:
      row = 0;
      break;
    default:
      return false;
    }
    col = (move - 1) % 3;

    switch (board[row][col])
    {
    case '1':
      return true;
      break;
    case '2':
      return true;
      break;
    case '3':
      return true;
      break;
    case '4':
      return true;
      break;
    case '5':
      return true;
      break;
    case '6':
      return true;
      break;
    case '7':
      return true;
      break;
    case '8':
      return true;
      break;
    case '9':
      return true;
      break;
    default:

      return false;
    }
  }

public:
  // return player number
  string getPlayer()
  {
    // Player 1 or player 2
    if (moves % 2 == 0)
    {
      return "1";
    }
    return "2";
  }
  void show()
  {
    for (int row{}; row < 3; ++row)
    {
      cout << " -------------" << endl;
      for (int col{}; col < 3; ++col)
      {

        cout << " | " << board[row][col];
      }
      cout << " |" << endl;
    }
    cout << " -------------" << endl;
  }

  // Make move and return if it was valid
  bool make_move(int move, char token)
  {

    int row, col;

    if (convert(move, row, col))
    {
      // Add move to counter only if valid
      moves++;
      board[row][col] = token;

      return true;
    }
    else
    {
      return false;
    }
  }

  // check if there is possible moves
  bool isOver()
  {
    for (int row{}; row < 3; ++row)
    {

      for (int col{}; col < 3; ++col)
      {
        switch (board[row][col])
        {
        case '1':
          return false;
          break;
        case '2':
          return false;
          break;
        case '3':
          return false;
          break;
        case '4':
          return false;
          break;
        case '5':
          return false;
          break;
        case '6':
          return false;
          break;
        case '7':
          return false;
          break;
        case '8':
          return false;
          break;
        case '9':
          return false;
          break;
        }
      }
    }
    return true;
  }

  // Check if someone won
  bool isWin()
  {
    if (
        // Horizontal lines
        (board[0][0] == board[0][1] and board[0][1] == board[0][2]) or
        (board[1][0] == board[1][1] and board[1][1] == board[1][2]) or
        (board[2][0] == board[2][1] and board[2][1] == board[2][2]) or
        // Verticalal lines
        (board[0][0] == board[1][0] and board[1][0] == board[2][0]) or
        (board[0][1] == board[1][1] and board[1][1] == board[2][1]) or
        (board[0][2] == board[1][2] and board[1][2] == board[2][2]) or
        // Diagonal lines
        (board[0][0] == board[1][1] and board[1][1] == board[2][2]) or
        (board[0][2] == board[1][1] and board[1][1] == board[2][0]))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{

  cout << endl
       << endl;
  cout << "                         ****************************************" << endl;
  cout << "                         *            Tic - Tac - Toe           *" << endl;
  cout << "                         *                                      *" << endl;
  cout << "                         *                                      *" << endl;
  cout << "                         *                 LAB8                 *" << endl;
  cout << "                         *                                      *" << endl;
  cout << "                         ****************************************" << endl
       << endl
       << "    This Lab creates an TTT game class, instanciates an TTT object and drives the game" << endl
       << endl;

  cout << " Start...\n";
  ttt game;

  char player = 'X';
  game.show();
  while (!game.isOver())
  {
    // game.show();
    if (game.isWin())
    {
      cout << "That is it! Player " << game.getPlayer() << " won...";
      return 0;
    }
    string prompt = "\n Player " + game.getPlayer() + " Enter move on board or 0 to quit: ";
    int move = get_value(prompt, "  Invalid move, try again\n", 0, 9);
    if (move == 0)
    {
      cout << endl
           << "Thank you for playing, Good Bye.";
      return 0;
    }

    // Check if move is not done
    if (!game.make_move(move, player))
    {
      cout << endl
           << endl
           << " That move has been played already, try again." << endl
           << endl;
    }
    game.show();
    player = (player == 'X' ? 'O' : 'X');
  }
  if (game.isOver())
  {
    cout << "Game Over!";
  }
  return 0;
}

/*



                         ****************************************
                         *            Tic - Tac - Toe           *
                         *                                      *
                         *                                      *
                         *                 LAB8                 *
                         *                                      *
                         ****************************************

    This Lab creates an TTT game class, instanciates an TTT object and drives the game

 Start...
 -------------
 | 7 | 8 | 9 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 1 | 2 | 3 |
 -------------

 Player 1 Enter move on board or 0 to quit: 7
 -------------
 | X | 8 | 9 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 1 | 2 | 3 |
 -------------

 Player 2 Enter move on board or 0 to quit: 7


 That move has been played already, try again.

 -------------
 | X | 8 | 9 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 1 | 2 | 3 |
 -------------

 Player 2 Enter move on board or 0 to quit: 0

Thank you for playing, Good Bye.
--------------------------------
Process exited after 12.67 seconds with return value 0
Press any key to continue . . .








                         ****************************************
                         *            Tic - Tac - Toe           *
                         *                                      *
                         *                                      *
                         *                 LAB8                 *
                         *                                      *
                         ****************************************

    This Lab creates an TTT game class, instanciates an TTT object and drives the game

 Start...
 -------------
 | 7 | 8 | 9 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 1 | 2 | 3 |
 -------------

 Player 1 Enter move on board or 0 to quit: 5
 -------------
 | 7 | 8 | 9 |
 -------------
 | 4 | X | 6 |
 -------------
 | 1 | 2 | 3 |
 -------------

 Player 2 Enter move on board or 0 to quit: 7
 -------------
 | O | 8 | 9 |
 -------------
 | 4 | X | 6 |
 -------------
 | 1 | 2 | 3 |
 -------------

 Player 1 Enter move on board or 0 to quit: 3
 -------------
 | O | 8 | 9 |
 -------------
 | 4 | X | 6 |
 -------------
 | 1 | 2 | X |
 -------------

 Player 2 Enter move on board or 0 to quit: 8
 -------------
 | O | O | 9 |
 -------------
 | 4 | X | 6 |
 -------------
 | 1 | 2 | X |
 -------------

 Player 1 Enter move on board or 0 to quit: 9
 -------------
 | O | O | X |
 -------------
 | 4 | X | 6 |
 -------------
 | 1 | 2 | X |
 -------------

 Player 2 Enter move on board or 0 to quit: 6
 -------------
 | O | O | X |
 -------------
 | 4 | X | O |
 -------------
 | 1 | 2 | X |
 -------------

 Player 1 Enter move on board or 0 to quit: 1
 -------------
 | O | O | X |
 -------------
 | 4 | X | O |
 -------------
 | X | 2 | X |
 -------------
That is it! Player 2 won...
--------------------------------
Process exited after 34.25 seconds with return value 0
Press any key to continue . . .







                         ****************************************
                         *            Tic - Tac - Toe           *
                         *                                      *
                         *                                      *
                         *                 LAB8                 *
                         *                                      *
                         ****************************************

    This Lab creates an TTT game class, instanciates an TTT object and drives the game

 Start...
 -------------
 | 7 | 8 | 9 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | 1 | 2 | 3 |
 -------------

 Player 1 Enter move on board or 0 to quit: 1
 -------------
 | 7 | 8 | 9 |
 -------------
 | 4 | 5 | 6 |
 -------------
 | X | 2 | 3 |
 -------------

 Player 2 Enter move on board or 0 to quit: 5
 -------------
 | 7 | 8 | 9 |
 -------------
 | 4 | O | 6 |
 -------------
 | X | 2 | 3 |
 -------------

 Player 1 Enter move on board or 0 to quit: 9
 -------------
 | 7 | 8 | X |
 -------------
 | 4 | O | 6 |
 -------------
 | X | 2 | 3 |
 -------------

 Player 2 Enter move on board or 0 to quit: 7
 -------------
 | O | 8 | X |
 -------------
 | 4 | O | 6 |
 -------------
 | X | 2 | 3 |
 -------------

 Player 1 Enter move on board or 0 to quit: 3
 -------------
 | O | 8 | X |
 -------------
 | 4 | O | 6 |
 -------------
 | X | 2 | X |
 -------------

 Player 2 Enter move on board or 0 to quit: 6
 -------------
 | O | 8 | X |
 -------------
 | 4 | O | O |
 -------------
 | X | 2 | X |
 -------------

 Player 1 Enter move on board or 0 to quit: 4
 -------------
 | O | 8 | X |
 -------------
 | X | O | O |
 -------------
 | X | 2 | X |
 -------------

 Player 2 Enter move on board or 0 to quit: 2
 -------------
 | O | 8 | X |
 -------------
 | X | O | O |
 -------------
 | X | O | X |
 -------------

 Player 1 Enter move on board or 0 to quit: 8
 -------------
 | O | X | X |
 -------------
 | X | O | O |
 -------------
 | X | O | X |
 -------------
Game Over!
--------------------------------
Process exited after 44.65 seconds with return value 0
Press any key to continue . . .

*/