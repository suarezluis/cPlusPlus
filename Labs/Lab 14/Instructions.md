In this lab, you are provided with startup code which has six working functions that use looping (for, while, or do loops) to repeat the same set of statements multiple times. You will create six equivalent functions that use recursion instead of looping. Although looping and recursion can be interchanged, for many problems, recursion is easier and more elegant.

Like loops, recursion must ALWAYS contain a condition; otherwise, you have an infinite recursion (or loop). The condition decides whether to: 1) call the function again; or 2) return from the function.

If you call the function again, the recursion is going deeper (diving into the rabbit hole); if you return from the function, the iteration is unwinding or unravelling itself (climbing out of the rabbit hole).

The main work performed in a recursive call can occur near the top (head) or bottom (tail) of the function. Specifically, the “work” can occur BEFORE or AFTER the recursive call. If the work occurs BEFORE the recursive call, this is sometimes called "head" recursion. If the work occurs AFTER the return from the recursive call, this is “tail" recursion. Of course, “work” can be performed both before and after the recursive call. But usually, recursive functions do most of their “work” BEFORE (on the way in), or AFTER (on the way out) of the recursive function.

void head(T n) { void tail(T n) {
statements; // on the way in
if (condition involving n) if (condition involving n) {
head(modified n); tail(modified n);
statements; // on the way out
}
} }

A void return is not required. See the textbook, Chapter 14, for many examples. Some languages, like lisp, are designed to use recursion extensively.

When executing a sequence of recursive calls, you control the "order of operation" by inserting processing steps anywhere into the templates above and choosing where you want the work to be done. If things are not getting done in the right order, try moving the processing steps above or below the: 1) decision; 2) recursive call; and/or swap whether doing head or tail recursion.

If you create an infinite recursion, the program will not hang (like an infinite loop); instead, the program will crash due to memory exhaustion. Unlike a loop, each recursive call uses up more memory (on the stack). The stack will quickly be used up during "infinite" recursion, and the program will crash - out of memory.

void infinite(T n) {
// no change to n before recursive call
infinite(n);
}

Provide one or more simple base cases which return a direct result. If the base case does not apply, simplify the problem and make a recursive call. The problem passed to the recursive call MUST be simpler than the initial problem presented to the function. Simplify the problem until it reaches a base case, which avoids further recursive calls. To avoid an infinite recursion, some progress must be made during each recursive call.

Problems to be solved in pairs, iteratively (provided) and recursively (you provide):

1. display a list of numbers increasing from 1 to n
2. display a list of numbers decreasing from n to 1
3. reverse a string (show a palindrome, Example: "flood" becomes "doolf")
4. add two numbers together (use ++, -- operators; cannot use +, -, &, ^, <<, >> operators)
5. multiply two numbers together (use +, - operators, cannot use \* or / operator)
6. search for a number in an array

Scoring: 5 points per problem solved, total of 30 points. Extra credit: choose a looping algorithm NOT found in chapter 14, and implement BOTH a looping solution AND a recursive solution. For example, can you draw a diamond using both iteration and recursion? Can you sort an array both iteratively and recursively? Once you get the hang of it, you can do ANY looping (also called: “iterative”: 1, 2, 3, …) operation with recursion.

In your code, provide the body of the code for the (6) recursive functions. You do NOT have to change anything in main(). All the looping functions are provided. All the recursive prototypes are provided. All the calls in main are provided. Your job is to fill in the body of the code for the recursive functions. The functions to be written are very small, only about 3 to 5 lines of code. In ALL cases, the recursive solution MUST NOT use any loops!! Function show_test() is used to organize and simplify testing output.

IMPORTANT: Your recursive functions should NOT use any static local variables or global variables! The “state” of the function must be completely self-contained. Consider that recursive functions may be called simultaneously by several programs at the same time. This occurs when a recursive function is in a library, such as qsort(). If calls are not independent, the recursive function is limited to a single process.
