Chapter 8, Programming Challenge, Tic-Tac-Toe game. See programming challenge #15, page 573, (7ed); programming challenge #16, page 592 (8ed); programming challenge #19, page 600 (9ed). Write a modular program that allows two players ('X' and 'O') to play a game of tic-tac-toe. The game board should be a class. Use a two-dimensional array (or vector) to store the state of the game board as private data within the "Board" class. Alter the state of the board using public member functions of class Board. See program description for more details. You must use a programmer-defined class data-type for this lab! Submit one file: DDHH_L8_Lastname.cpp. (As usual, replace DDHH with the course designator, and Lastname with your last name.)

Tip: The textbook suggests entering moves by row and column. You could do this, but consider the ease-of-use of your game. You could draw the game board with the numbers 1 to 9 in the open squares. Ask the user which square number to put X or O. Notice the numerical keypad provides a natural input for entering moves into a tic-tac-toe game. Can you make a function that changes the number 1 into row 0, column 0; the number 2 into row 0, column 1, the number 9 int row 2, column 2, etc? This way, the user can just type a number on the numeric keypad to enter his/her move.

Example:

## 7 | 8 | 9

## 4 | 5 | 6

1 | 2 | 3

Basic: Start out by displaying an empty game board, and ask for the move of player one. Redraw the board after every move. Alternate moves between player one and player two. Don't worry about checking for win/lose or keeping score. (max 25 points).

Medium: After each move, determine whether the move is valid. Was that space already occupied? Also determine whether: player 1 won, player 2 won, nobody won (play can continue) or nobody won and play is over (a "cat's game"). Hint: to determine if a game is won, first check 3 rows, then 3 columns, then diagonal (/) then diagonal (\). There are 8 ways to win. One way to determine a cat's game is to count the number of unused spots remaining on the board. If nobody won, and there are no open spots, you have a cat's game. There are many clever ways to determine win/loss/cats status. (max 28 points).

More: After the game ask the user if he/she wants to continue. Play as many games as the user desires. Keep score of how many games each player won. Provide percentage of win/loss/cats for both players. (max 30 points).

Most: Try using direct screen addressing. See textbook, pages 464 - 470 (7ed), pages 484 - 490 (8ed), pages 486 - 492 (9ed). This uses a screen handle to locate the cursor directly on the screen. This provides much flexibility on drawing output. Simple character-based games use this technique. You can also change the color of the character - see page 374 (7ed), page 392 (8ed), 392 (9ed). Use an enumerated type to name the colors and avoid "magic numbers". This makes the code more self-documenting. (max 34 points: 2 extra for direct cursor addressing; 2 extra for using color.).

Further consideration:
Once the game is working, one could enhance the game so the player plays the computer. The computer can use a random number generator to generate legal moves. Can you make the computer "smarter" than just generating random valid moves?

Consider making the computer play itself, without any input or output during the game. The program keeps track of game results. What if the computer plays itself 10 times? 100 times? 1000 times? 1 billion times? How many times did computer player 1 win? Computer player 2? How many cat's games? What does this tell you about the game of tic-tac-toe? This method is called Monte Carlo simulation, and allows programmers to develop winning game strategies.
