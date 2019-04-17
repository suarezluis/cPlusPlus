For the Chapter 9 lab, you add to a working program. Much of the work is reading and understanding the code that is provided. It contains one working sort algorithm and one working search algorithm. Your job is to add two new sort algorithms and one new search algorithm. When complete, the program implements and tests three different sort algorithms and two different search algorithms. (26 points max if you add one sort and one search. 30 points max if you add two new sorts and one new search.)

The choice of new algorithms is yours. The textbook provides algorithms and explanations for linear search and binary search; and source code and explanations for bubble sort and selection sort. These are commonly used algorithms for searching and sorting.

Note: The starting program is provided on the assignment link. Selection sort and linear search are already coded and tested. You have to add two more sorts and one more search algorithm. In the code you provide, use variable names (often very cryptic in textbooks) in your own terms, so the algorithm is easier to understand. Also provide good comments.

When you implement these algorithms, use your own variable names and comments, which reflect your own personal understanding of how these algorithms work. You can use the textbook code at first, but modify the names, and add comments, to show your understanding of what it is doing. Test your code to verify it works by sorting a small array properly.

Next, measure the performance of your algorithms and find out which is best. Performance measuring code is provided. To measure the performance, the program gets the time before and after your algorithm runs and subtracts the stop time from the start time to get the duration, in milliseconds, of your algorithm. Example:

typedef unsigned int uint
uint startTime, stopTime, duration;
startTime = clock();
algorithm(parameter1, parameter2, parameter3, etc); // search or sort algorithm
stopTime = clock();
duration = stopTime - startTime;
cout << "algorithm took: " << duration << "milliseconds."

For small data sizes, the time will be 0 milliseconds. To get a useful duration, it works better if it runs for at least 1/4 second (250 milliseconds). Two ways to get an algorithm to run longer: 1) increase the data size; 2) place a loop around the algorithm, so it runs many times. For example, perform a search 1000 times in a loop, and divide the duration by 1000.0 to get the milliseconds for one iteration.

Performance testing code is provided. It will try five different array sizes. Try to keep the maximum execution time to at most 10 seconds. Arrays of size: 5000, 10000, 20000, 30000, 40000, up to 100000 may work. Include the performance results of your experimentation here. Example (for each entry, there is some number, in milliseconds):

    Algorithm    1000  10000  20000  30000  40000   50000  (Array size)
    ----------  -----  -----  -----  -----  -----  ------
    sort1           x     xx    xxx   xxxx  xxxxx  xxxxxx
    sort2           y     yy    yyy   yyyy  yyyyy  yyyyyy
    sort3           z     zz    zzz   zzzz  zzzzz  yyyyyy
    search1         m     mm    mmm   mmmm  mmmmm  mmmmmm
    search2         n     nn    nnn   nnnn  nnnnn  nnnnnn

Observe: As the size of the array increases, how does the duration increase?

Note: Code for automating the performance testing of the algorithms is included. Read the code to understand how to performance test your own search and sort algorithms. Very short run-times (fast algorithms, small data) may register as 0 time, which is under 1 millisecond (1/1000th of a second).

When submitting this lab, change the file name from:: DDHH*L9_Lastname to: <course designator>\_L9*<your last name>.cpp
