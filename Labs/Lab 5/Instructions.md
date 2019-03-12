his lab is based on "Using Files - Population Bar Chart" at the end of Chapter 5. This is on page 303 Programming Challenge 23 (7ed); or page 322 Programming  Challenge 25 (8ed); or on page 322 Programming Challenge 27 (9ed). In this lab, you must read the data from a file.

The input data file: people.txt is attached above. It can also be found under Publisher Source, Chapter 5 (called people.dat) or, you can just make the data file with a text editor. This small file contains the numbers: 2000  4000  5000  9000  14000  18000. Use the file people.txt. I changed the extension from .dat to .txt because Windows is set up to easily display and edit files with the .txt extension.

Do not submit the people.txt file with your lab. I will use the above people.txt file for testing. If you want to provide your own different data file, submit it along with your source code; name your data file: DDHH_L5_lastname_people.txt to keep is separate from others. If you provide a data file, I will use your data file for testing.

You program can assume: 1) population numbers start at the year 1900 (or 1910); (some editions start at 1900, some start at 1910; it doesn't really matter) 2) population counts are provided in 20 year increments; 3) there are 6 population counts provided. To start out with working code which does most of what you need to read data from a file, see: "Program Samples", Simple FileIO. This provides a complete, working FileIO example.

Steps for this lab:

1) Read the file people.txt. If the file is not found, handle the situation appropriately with a good error message, including the name of the file not found. Do not attempt to display a chart if no data is available. If the file opens OK, then use the data to display a bar chart showing population growth.  (max 16 points).

2) At the top of the chart, display a title at the top, so the user knows what this chart represents. (max 18 points) For example, display:
PRAIRIEVILLE POPULATION GROWTH
(each * represents 1000 people)

3) Make the program more flexible: read population values from the file until end-of-file (instead of 6 times). This allow for more or fewer population data counts in the file. For example, it should also work if extra population values added for years 2020, 2040. Handle up to 10 population values. (max 20 points).

Example output: (bar chart)
PRAIRIEVILLE POPULATION GROWTH
(each * represents 1000 people) 
1900 **
1920 ****
1940 *****
1960 ***
1980 *******
2000 ********
2020 ************
2040 **********

Extra credit: Produce a column chart rather than a bar chart. That is, put the years along the bottom row, and have columns going up from the year. Make the column 2 stars wide centered over the year. You may use various techniques to do the column chart. You can use arrays if you like. (max 22 points).

For a nicer column chart, include data markers: year values along the x-axis AND population values along the y-axis (max 24 points).

Extra credit example output: (column chart with data markers)
PRAIRIEVILLE POPULATION GROWTH

12000                                     **
11000                                     **
10000                                     **    **
 9000                                     **    **
 8000                               **    **    **
 7000                         **    **    **    **
 6000                         **    **    **    **
 5000             **          **    **    **    **
 4000       **    **          **    **    **    **
 3000       **    **    **    **    **    **    **
 2000 **    **    **    **    **    **    **    **
 1000 **    **    **    **    **    **    **    **
     1900  1920  1940  1960  1980  2000  2020  2040

Use the file naming convention: DDHH_L5_lastname.cpp (replace the DDHH with your course designator and lastname with your last name) before you submit it.

