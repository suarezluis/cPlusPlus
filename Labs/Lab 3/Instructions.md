Lab Ch02
This lab is based on Chapter 2, page 73(7ed); page 75 (8ed, 9ed), problem #12, Diamond pattern, but it adds a bit more work. The steps are:

1. Write code that displays a 7-line diamond pattern on the screen. This can be done using a double-nested for-loop. The inner loop displays a line of stars, one column (space ' ' or star ‘\*’) at a time. The outer loop displays multiple lines, one row (“**\***”) at a time. This 7-line diamond pattern can easily be done with 7 cout statements, but then you cannot complete the next step.
   Test this. If you stop here, you have earned up to 12 points max.

2. Instead of only making diamonds with exactly 7 lines, ask the user how many lines to make the diamond, then make the diamond with the size desired. If the size requested is <=0, don’t make a diamond. It should work for both even and odd number of lines. See chapter 5, top of page 267 (7ed), page 270 (8ed), page 271 (9ed) for code that will loop using a for-loop. Position diamonds to the far left. Don't display unnecessary extra columns of spaces on the far left or right.
   Test this. If you stop here, you have earned up to 16 points max.

3. It is tedious to use and test a program if it does one thing and stops. In this step, put the diamond drawing code inside another loop. It is now triple-nested. The outer loop should repeatedly prompt the user for the number of lines to make the diamond. If the number is <= 0, quit. Otherwise, make a diamond pattern with the number of lines entered. Keep asking the user for the number of lines to draw, then draw one diamond shape, UNTIL the user wants to quit. A size of <=0 means to quit. This looping pattern is similar to the one described in Lab 1.
   Test this. If you stop here, you have earned up to 20 points max.

Extra credit: When creating the row of spaces (" ") and stars (“_\*\*”), you can construct a string with exactly the number of characters (' ' or ‘_’') you want in one statement without using a loop. Hint: This is described in Table 12-6 on page 806 (7ed) and Table 12-4 on page 817 (8ed). This string constructor was removed from Table 12-3 on page 840 (9ed), but here is a hint: string(int n, char ch); This simplifies the code by eliminating the inner-most loop.
Test this. If you stop here, you have earned up to 22 points max. This is the most possible points.

Example:
Enter the number of rows desired to make a diamond pattern (0 to quit): 5 \*

---

---

---

\*

Enter the number of rows desired to make a diamond pattern (0 to quit): 7 \*

---

---

---

---

---

\*

Enter the number of rows desired to make a diamond pattern (0 to quit): 4 \*

---

---

\*

Enter the number of rows desired to make a diamond pattern (0 to quit): 0
Goodbye!

Hint: Each row consists of spaces and stars. To compute the correct number of spaces and stars for each row, consider making a table: line number, spaces, stars. Think of the relationship between: line number, number of spaces for that line, number of stars for that line. For help with this, look in “Program Samples” for “Excel file to aid Lab 2: lines to diamonds”. This is a spreadsheet that helps to analyze the problem.

Even a simple lab like this has valid variations. For example, more symmetric diamonds may be drawn like this:

This program draws diamonds using simple ASCII

Enter number of rows in diamond, 0 to quit: 1 \*

Enter number of rows in diamond, 0 to quit: 2
\*\*
\*\*

Enter number of rows in diamond, 0 to quit: 3 \*

---

\*

Enter number of rows in diamond, 0 to quit: 4
\*\*

---

---

\*\*

Enter number of rows in diamond, 0 to quit: 0

Good-bye!

As in Lab 1 and ALL LABS IN THIS COURSE:

1. Add a comment block at the top of your code.
2. Provide properly formatted C++ code.
3. Paste the test run results at the bottom.
   The file name will be: DDHH_L2_Lastname.cpp (replace DDHH, Lastname, of course)
