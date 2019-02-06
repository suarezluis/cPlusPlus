Lab 1 (click on "Lab Ch01" above and scroll down to upload, attach and submit file DDHH_L1_Lastname.cpp)

The first few labs transition into C++. The concepts should be review. C++ may be new to you. If you have not written a program for a while, have not used C/C++, are a bit "rusty", or have not set up a development environment (devcpp, code::blocks, Visual Studio, GCC, Xcode, etc.) these first few labs ease you back into the game.

We spend some time getting familiar with C++ syntax. If C++ is new to you, it may look odd at first. The concepts should be familiar: input, processing, output. Ask for user input with a prompt, get input, process the input, provide output. The skills needed for this lab are in the first few chapters of our textbook. Since you have programmed before, your main task for this lab is to learn how to do things in C++. Hopefully, you have done code like this before, perhaps in Python, Java, BASIC, C/C++, C#, Swift or whatever.

C++ is a strongly typed language. Whereas Python has numeric types int and float, C++ has: char, short, int, long, float, double, long double, etc. There are important consequences of using, mixing, and matching different types. One goal of this lab is to observe the use of multiple types. C++ will implicitly cast from one type to another. This can result in unexpected behavior. You can override implicit casting by explicit casting. Use the types specified in bold. Use casting as needed.

Write one program that solves two problems about nutrition: calculate a restaurant bill and calculate your body mass index (BMI). The steps are:
1) Restaurant bill - write code that calculates a restaurant bill given cost of food and tip percentage:
            a) Ask for and get the cost of food. Use data type double.
            b) Ask for and get the tip percentage. Use data type double.
            c) Internally, declare the tax rate: const double TAX_RATE = 0.0825. Do not ask for tax rate.
            d) Compute the total bill, using the: food cost, TAX_RATE and tip percentage.
                What should the tip be? Based on food cost? Food cost and tax? You decide; provide comments.
            e) Print out the total bill.
Test this. If you stop here, you have earned up to 10 points max.

2) Body Mass Index (BMI) – write code that computes BMI. The formula is:
     BMI = (weight in pounds / (height in inches x height in inches) ) x 703
            a) Ask for and get the required user data. Use data type int.
            b) Calculate the BMI. For the result, use data type double.
            c) Print out the BMI.
Test this. If you stop here, you have earned up to 14 points max.

3) Combine the two parts above into a menu. Prompt the user for whether they want to perform:
a) amount of bill; or b) BMI.
            a) Ask for and get the option desired. Use data type char.
            b) if option a, compute amount of restaurant bill; if option b, calculate BMI
Test this. If you stop here, you have earned up to 18 points max.

4) Loop the program, Add option q to quit. Loop until the user enters q to quit.
            a) Enter a loop.
            a) Ask for and get the option desired.
            b) if option a, compute amount of restaurant bill; if option b, calculate BMI; if option q, quit
Test this. If you stop here, you have earned up to 20 points max.

Extra credit:
            a) ignore the option’s case (uppercase or lowercase). Hint: use toupper() or tolower()
            b) format the output of the bill as: $xx.xx. format the BMI as xx.xx. (display 2 decimal places)
            c) display an error message if given an invalid option and continue the loop.
            d) ask for height in feet and inches instead of just inches; convert into inches.
Test this. If you stop here, you have earned up to 22 points max. This is the most possible points.

Example code for main loop:

while (true) {
    cout<<"Options: a)mount of restaurant bill; B)MI; q)uit: ";
    char option=' '; 
    cin >> option;
    if (option=='a') {
        // compute and display the amount of the restaurant bill.
    }
    else if (option=='b') {
        // compute and display the BMI
    }
    else if (option=='q')
        break;
    else
        // invalid option entered, display an error message
}

Use appropriate commenting and indenting style. See information on programming style under the 'Dev C++ Compiler' button. Attach a single .cpp file on the Blackboard assignment link. This can be done in about 30 to 40 lines of code. Use the file naming convention: TT17_L1_Lastname.cpp.

Provide a comment block which contains this information at the top of all labs for this class:
// Author: Sam Houston;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 1:  Provide menu-driven option loop that calculates: restaurant bill; BMI; or quits the loop.

<code goes here>

To verify you have tested your code, copy and paste the output from the cmd.exe display screen into your source code in a comment block at the very bottom. See instructions on how to do this under Assignments, Labs 1 - 3. “Test and Verify: How To Copy Program Output Into Source Code”

/*  Example test output. This goes at the bottom.
This program computes amount of restaurant bill and / or BMI. Use q to quit.
Options: a)mount of restaurant bill; B)MI; q)uit: a
  Food cost? 10
  Tip rate? .1
  Restaurant bill is: $11.82

Options: a)mount of restaurant bill; B)MI; q)uit: b
  Weight in pounds? 150
  Height in inches? 72
  BMI is: 20.34
Options: a)mount of restaurant bill; B)MI; q)uit: q
Good-bye!
*
You can use the sample C++ code above for looping and decisions. For more help, see chapter 4 on Making Decisions and chapter 5 on Looping. We will go into more detail on decisions and looping later.
