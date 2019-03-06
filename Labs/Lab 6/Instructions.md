This lab was made by the instructor to practice using various features of C++ functions. These features are covered in the textbook in Chapter 6. You may start with demo code developed in class.

This is a very important lab. C++ functions are similar to Python functions, but have some different behaviors and features. It is very important to complete Lab 6 in preparation for Exam 1. Allow 6 - 10 hours or more to do this lab.

There are 6 skills to demonstrate in Lab 6:

1. Use functions. Functions sub-divide programming problems into independent parts.
2. Use function overloading, where several functions have the same name but different parameters.
3. Use pass-by-value and pass-by-reference parameters to functions.
4. Use static local variables, which work like global variables (values persist) and local variables (local scope). Their value persists between function calls, yet they can only be used within the function.
5. Use default parameters, which take on a default value if a parameter is not specified.
6. Use const parameters, which specify that the parameter cannot change. const reference parameters make good sense for strings.
   You get 4 points per skill. Do 5 of 6 skills to get 20 points, up to 24 points (4 points of extra credit) maximum for all 6 skills.

The problem scenario is to calculate the distance between two things. The two “things” might be: two letters in the alphabet, two numbers on a number line or two points on a graph. Use functions for three basic operations:

1. Input data. The data could be: letter, number, or point (x, y). Call this twice to get two “things”.
2. Determine distance. The distance (dist for short) could be: between two letters, between two numbers, or between two points on a graph. For example: dist(‘b’, ‘f’) is 4 (two letters), dist(-5.5, 20.5) is 26.0 (two numbers); dist(0.0, 0.0, 1.0, 1.0) is 1.41421 (two points: x1, y1; x2, y2).
3. Display the result. The result should be described with some explanatory text.

The program structure is similar to previous programs. The main loop has menu options for: letter, number, point, quit. Start the program, output the menu prompt. Based on the chosen option, get two appropriate values; compute and display the distance between the values; and prompt again. Keep running until the user quits. Scroll down to see sample output.

There are three different “things” and three different operations on these “things”, so you need nine functions. You need 3 overloaded input functions, 3 overloaded distance functions, and 3 overloaded display functions. An “overloaded function” is a function with the same name as another function. For each “thing”, you input a pair of values, compute the distance between them, and display the distance.

The three overloaded input functions look like this. (Provide the correct parameter type.):
char input(parameter_type prompt_text, parameter_type error_message_text); // for getting a letter
double input(parameter_type min_number, parameter_type max_number, parameter_type prompt_text, parameter_type error_message_text); // for getting a number
void input(parameter_type x, parameter_type y, parameter_type prompt_text); // for getting a point (x, y)

Each input function works a little differently. For char, print the prompt; get a character. If the character is valid (a-z or A-Z) return it. If it is NOT valid, display the error message and try again. Use isalpha() to verify the character is alphabetic. Loop until a valid character is entered. For the number, print the prompt. As part of the prompt, print the acceptable range (min, max) allowed for the value. Get a value. If it is within the range, return it. If NOT valid, print the error message and try again. Loop until a valid (within range) number is entered.

For the point, you need to get two numbers, x and y. Since C++ functions only return one object, use a void function (it returns nothing) but use two pass-by-reference parameters. This allows the function to change two "caller" values while inside the function ("callee"). The input function for getting the two points does not provide parameters for min, max or error message. When input for a point is called, input both the x and y values for each point. To do this, for each point, call the input function for a single number twice. Enforce a range from -100.0 to +100.0. Display an error message of your choice. Loop until you get valid numbers for both points: (x1, y1) and (x2, y2).

Three overloaded distance functions are also needed. They look like this:
int dist(char a, char b); // return the distance between two letters (a-z)
double dist(double d1, double d2); // return the distance between two numbers
double dist(double x1, double y1, double x2, double y2); // return distance between two points.

Each distance function works a little differently. For letters, use toupper or tolower to ignore case. Note: dist(‘A’, ‘c’), dist(‘a’, ‘C’), dist(‘a’, ‘c’) and dist(‘A’, ‘C’) should all be 2. The order of the letters should not matter: dist(‘c’, ‘a’) is also 2. For numbers, return the absolute value of the difference. For points, use the distance formula between two points: square root of ( (x2-x1) squared + (y2-y1) squared ). Look this up if you don’t remember it. To do the math, #include <cmath>; use abs() for absolute value; use pow(x,y) or sqrt() as needed. Look these functions up on a search engine or in the textbook for details.

Three overloaded display functions are also needed. They look like this:
void display(const string &msg, char ch1, char ch2); // display letters and letter distance
void display(const string &msg, double d1, double d2); // display numbers and number distance
void display(const string &msg, double x1, double y1, double x2, double y2); // display points and point distance.

The display functions are provided a message and two items. Inside in the display functions, use a static local variable to keep a count of how many times the function was called. Do not use a global value. Each time the display function is called, increment the count. In the display functions, call dist() to get the distance to display. When the result is displayed, include the “call count” as part of the output message. See pg 344-346 (7ed) or 363 (8ed, 9ed) for static local variables. The output should include: count, message, values of items, and their distance. See sample output below for details.

Use some default parameters. Default parameters can be set in the function definition, so if the function is called with some parameters missing, the defaults are used. Defaults must be used from right to left in the function parameter list. Try using default arguments (see textbook chapter 6, section 6.12: pages 347 - 350 (7ed), or 365-368 (8ed), or 364 - 367 9ed). With default parameters, you can often reduce two or more overloaded functions to just one function.

Add const to parameters where appropriate, like when passing in strings. Use const for parameters that should not change. This is not required for your program to work, but it serves as a safety net to prevent changing the value of parameters you do not want changed, such as strings (prompts, error message). Const reference parameters can be a big performance improvement, because the entire value of the parameter does not have to be copied - very good for strings. For small types, like int, float, double, etc. pass-by-value is used instead of pass-by-const reference because the value is no larger than the reference. The most common calling mechanisms are: call-by-value, call-by-reference, and call-by-const-reference.

Here is some sample output. Your program does not have to match this exactly. The extra spacing, indenting and formatting makes it easier to understand.

Display the distance between two items: letters, numbers, or points.

Options: l)etter; n)umber; p)oint; q)uit: l
Enter first letter (a to z): b
Enter second letter (a to z): f
(#1) Distance between letters b & f = 4

Options: l)etter; n)umber; p)oint; q)uit: n
Enter first number (-100, 100): -5.5
Enter next number (-200, 200): 20.5
(#1) Units between -5 and 20 = 26.0

Options: l)etter; n)umber; p)oint; q)uit: p
Enter the first point (x): 0
Enter the first point (y): 3
Enter the second point (x): 4
Enter the second point (y): 0
(#1) straight line distance between points (0, 3) and (4, 0) is: 5

Options: l)etter; n)umber; p)oint; q)uit: l
Enter first letter (a to z): 8
Sorry, try again.
Enter first letter (a to z): A
Enter second letter (a to z): z
(#2) Distance between letters A & z = 25

Options: l)etter; n)umber; p)oint; q)uit: n
Enter first number (-100, 100): -123.456
Sorry, out-of-range. Try again.
Enter first number (-100, 100): -10
Enter next number (-200, 200): 50
(#2) Units between -10 and 50 = 60

Options: l)etter; n)umber; p)oint; q)uit: p
Enter the first point (x): 0
Enter the first point (y): 0
Enter the second point (x): 1
Enter the second point (y): 1
(#2) straight line distance between points (0, 0) and (1, 1) is: 1.41421

Options: l)etter; n)umber; p)oint; q)uit: q
Good-bye!

Test your code. Paste the output at the bottom of your source. This lab can be written in about 100 lines of code. Knowledge and correct use of C++ skills results in smaller, cleaner code.
