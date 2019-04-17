#include <iostream>
#include <iomanip>
#include <random> // needed for Orwell devcpp
using namespace std;
const int TARGET = 123456789;
// This target value will never be found, because it
// is larger than any random number generated by rand().
// Do not find the target to test for worst-case performance.
// helper functions
void showArray(int[], int);
bool verifySorted(int[], int);
// Each selection sort below does the same algorithm. The
// difference is in how well it documents its operation.
void selectionSort(int[], int);
void selectionSortDescribed(int[], int);
void selectionSortDescribedShowProgress(int[], int);
void selectionSortConcise(int[], int);
bool linearSearchArray(int[], int, int, int &);
void bubbleSort(int[], int);
void insertionSort(int[], int);
bool binarySearchArray(int[], int, int, int &);
const int testSizes[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 0};
// This code helps to automate multiple test runs.
// Call this code as many times as desired to test your sort algorithms.
float testSortAlgorithm(void sortAlgorithm(int[], int), int array[], int arraySize)
{
  // This is an interesting function. The first parameter is a "function pointer",
  // It accepts any function that returns a void and has parameters of type: (int [], int)
  // So, the first parameter (in the caller) can be the name of the sort function being tested.
  // This reduces redundant code, because the same sequence of tests are performed on each
  // sort function. (Our textbook does not mention function pointers.)

  // fill the array with random, unsorted numbers before sorting it
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();         // initialize array with random values
  int startTime = clock();         // start the test clock
  sortAlgorithm(array, arraySize); // ALGORITHM UNDER TEST
  int stopTime = clock();          // stop the test clock
  float duration = stopTime - startTime;
  if (!verifySorted(array, arraySize))
    cout << "Error! array not sorted!!!\n";
  return duration;
}
// Copy and/or reuse this code as desired to test your search algorithms.
float testLinearSearch(int array[], int arraySize)
{
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 1000; repeat++)                   // repeat test 1000 times to increase duration
    found = linearSearchArray(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  int duration = stopTime - startTime;
  return duration / 1000.0; // divide duration by 1000 to get time for single search
}
// To test binary search
float testBinarySearch(int array[], int arraySize)
{
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 1000; repeat++)                   // repeat test 1000 times to increase duration
    found = binarySearchArray(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  int duration = stopTime - startTime;
  return duration / 1000.0; // divide duration by 1000 to get time for single search
}
void testAlgorithms(int array[], int arraySize)
{
  // This draws a table of results for each algorithm tested.
  const int AlgorithmNameWidth = 16;
  const int DurationWidth = 10;
  cout << setw(AlgorithmNameWidth) << left << "Algorithm";
  for (int testCount = 0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << testSizes[testCount];
  cout << endl
       << string(AlgorithmNameWidth, '=');
  for (int testCount = 0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << " =======";
  // Copy and/or reuse this code as desired to test your algorithms.
  cout << endl
       << setw(AlgorithmNameWidth) << left << "selection sort";
  for (int testCount = 0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(selectionSort, array, testSizes[testCount]);
  // In the line above, I am passing the name of the function selectionSort as a parameter into
  // the function testSortAlgorithm. You can do the same thing for your sort algorithms, as long
  // as your sort algorithms return a void and have parameters: (int array[], int size).
  cout << endl
       << setw(AlgorithmNameWidth) << left << "linear search";
  for (int testCount = 0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testLinearSearch(array, testSizes[testCount]);
  cout << endl;
  // Add a loop to call and test your first sort algorithm here
  cout << endl
       << setw(AlgorithmNameWidth) << left << "bubble sort";
  for (int testCount = 0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(bubbleSort, array, testSizes[testCount]);
  // Add a loop to call and test your second sort algorithm here
  cout << endl
       << setw(AlgorithmNameWidth) << left << "insertion sort";
  for (int testCount = 0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(insertionSort, array, testSizes[testCount]);
  // Add a loop to call and test your search algorithm here
  cout << endl
       << setw(AlgorithmNameWidth) << left << "binary search";
  for (int testCount = 0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testBinarySearch(array, testSizes[testCount]);
  cout << endl;
}
// Useful test to verify that array is really sorted!
bool verifySorted(int array[], int size)
{
  // returns true if array is in ascending sorted order, else false.
  for (int i = 0; i < (size - 1); ++i)
    if (array[i] > array[i + 1])
      return false;
  return true;
}
int main()
{
  // the random number generator has to be "seeded" only once.
  unsigned int seed = time(0);
  srand(seed);
  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, uncomment the lines below.
  const int SMALLSIZE = 6;
  int smallArray[SMALLSIZE] = {5, 7, 2, 8, 9, 1}; // for testing purposes
  cout << "Optional testing of specific algorithms, prior to performance comparison table:\n\n";
  cout << "UNSORTED smallArray is: ";
  showArray(smallArray, SMALLSIZE);
  if (!verifySorted(smallArray, SMALLSIZE))
    cout << "Note: smallArray not sorted.\n";
  selectionSortDescribedShowProgress(smallArray, SMALLSIZE);
  cout << "SORTED smallArray is: ";
  showArray(smallArray, SMALLSIZE);
  if (verifySorted(smallArray, SMALLSIZE))
    cout << "Note: smallArray is sorted.\n";
  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, try it on smallArray below.
  const int BIGSIZE = 50000;
  int bigArray[BIGSIZE];
  float duration = 0.0; // time in milliseconds
  // Do a single test run using the full size of bigArray
  duration = testSortAlgorithm(selectionSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "\nSelection sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
  duration = testSortAlgorithm(bubbleSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "\nBubble sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
  duration = testSortAlgorithm(insertionSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "\nInsertion sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
  duration = testLinearSearch(bigArray, BIGSIZE);
  cout << "\nLinear search of bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
  duration = testBinarySearch(bigArray, BIGSIZE);
  cout << "\nBinary search of bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;
  // Test the algorithms on ever longer list of numbers. Only one
  // array is needed. Lengths of 1000, 5000, 10000, 20000, 30000,
  // 40000, 50000 are tested.
  testAlgorithms(bigArray, BIGSIZE);
  cout << endl;
  // system("pause"); // optional, commented out
  return 0;
} // end of main
// Add your first sort algorithm in here
// bubble sort
void bubbleSort(int array[], int size)
{
  // outter loop
  for (int startLooking = 0; startLooking < (size - 1); startLooking++)
  {
    // inner loop
    for (int index = startLooking + 1; index < size; index++)
    {
      //test if sorted
      if (array[index] < array[startLooking])
      {
        int temp = array[startLooking];
        // perform change
        array[startLooking] = array[index];
        array[index] = temp;
      }
    }
  }
}
// Add your second sort algorithm in here
// insertion sort
void insertionSort(int array[], int size)
{

  int startLooking, key, index;
  // outer loop
  for (startLooking = 1; startLooking < size; startLooking++)
  {
    key = array[startLooking];
    index = startLooking - 1;
    /* swap elements of array[0] all the way to array[startLooking - 1], that are
       bigger than array[startLooking], to one position in front of their current position */
    while (index >= 0 && array[index] > key)
    {
      array[index + 1] = array[index];
      index = index - 1;
    }
    array[index + 1] = key;
  }
}
// Add your search algorithm in here

// binary search
bool binarySearchArray(int a[], int s, int t, int &p)
{
  // calculate the initial top index of search within range.
  int topIndex = s - 1;
  // calculate the initial bottom index of search within range.
  int bottomIndex = 0;
  while (bottomIndex <= topIndex)
  { // loop until the bottom index is smaller than the top index.
    // calculate the middle index of the current range.
    int midIndex = (bottomIndex + topIndex) / 2;
    if (a[midIndex] == t)
    {               // check if the element at the curret mid index is the searched item or not
      p = midIndex; // store the midIndex
      return true;
    }
    else if (a[midIndex] < t)
    {                             // check if the element at the curret mid index is lower
      bottomIndex = midIndex + 1; // set the bottom index as the index
    }
    else if (a[midIndex] > t)
    {                          // check if the element at the curret mid index is higher than the searched item or not
      topIndex = midIndex - 1; // set the higher limit as the index
    }
  }
  p = -1;
  return false;
}
void showArray(int array[], int size)
{
  for (int count = 0; count < size; count++)
    cout << setw(2) << array[count] << ' ';
  cout << endl;
}
// Your new search algorithm cannot be linear search, because it is provided here.
bool linearSearchArray(int a[], int s, int t, int &p)
{
  // This is very terse, short, cryptic - not recommended!
  for (int i = 0; i < s; i++)
    if (a[i] == t)
    {
      p = i;
      return true;
    }
  p = -1;
  return false;
}
// Your new sort algorithm cannot be selection sort, because it is provided here.
// This is the selection sort from our textbook
void selectionSort(int array[], int size)
{
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size - 1); startScan++)
  {
    minIndex = startScan;
    minValue = array[startScan];
    for (int index = startScan + 1; index < size; index++)
    {
      if (array[index] < minValue)
      {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

// This is selection sort described in more detail
void selectionSortDescribed(int array[], int size)
{
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++)
  {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++)
    {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar)
      {
        // found a smaller value than I had before, save it for now
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is selection sort described in great detail
// It also shows the result of each pass of the outer loop.
void selectionSortDescribedShowProgress(int array[], int size)
{
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++)
  {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++)
    {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar)
      {
        // found a smaller value than I had before, save it for now
        cout << " previous min value: " << minValueSoFar << " at offset: " << minIndexSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        cout << "; found smaller value: " << minValueSoFar << " at offset: " << minIndexSoFar << endl;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    cout << " swapped the previous minimum value: " << array[minIndexSoFar]
         << " with with new minimum value: " << array[unsortedIndex] << endl;
    cout << "After pass " << unsortedIndex << " the array looks like this: ";
    showArray(array, size);
    cout << endl;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is a selection sort from a concise algorithm encyclopedia.
// As is, it is VERY CRYPTIC!
void selectionSortConcise(int array[], int size)
{
  int i, idx, val;
  for (i = 0; i < (size - 1); i++)
  {
    idx = i;
    val = array[i];
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] < val)
      {
        val = array[j];
        idx = j;
      }
    }
    array[idx] = array[i];
    array[i] = val;
  }
}

/*


UNSORTED smallArray is:  5  7  2  8  9  1
Note: smallArray not sorted.
 previous min value: 5 at offset: 0; found smaller value: 2 at offset: 2
 previous min value: 2 at offset: 2; found smaller value: 1 at offset: 5
 swapped the previous minimum value: 5 with with new minimum value: 1
After pass 0 the array looks like this:  1  7  2  8  9  5

 previous min value: 7 at offset: 1; found smaller value: 2 at offset: 2
 swapped the previous minimum value: 7 with with new minimum value: 2
After pass 1 the array looks like this:  1  2  7  8  9  5

 previous min value: 7 at offset: 2; found smaller value: 5 at offset: 5
 swapped the previous minimum value: 7 with with new minimum value: 5
After pass 2 the array looks like this:  1  2  5  8  9  7

 previous min value: 8 at offset: 3; found smaller value: 7 at offset: 5
 swapped the previous minimum value: 8 with with new minimum value: 7
After pass 3 the array looks like this:  1  2  5  7  9  8

 previous min value: 9 at offset: 4; found smaller value: 8 at offset: 5
 swapped the previous minimum value: 9 with with new minimum value: 8
After pass 4 the array looks like this:  1  2  5  7  8  9

SORTED smallArray is:  1  2  5  7  8  9
Note: smallArray is sorted.

Selection sort on bigArray took: 2859.00 milliseconds.

Bubble sort on bigArray took: 7024.00 milliseconds.

Insertion sort on bigArray took: 1611.00 milliseconds.

Linear search of bigArray took:    0.11 milliseconds.

Binary search of bigArray took:    0.00 milliseconds.
Algorithm             1000      5000     10000     20000     30000     40000     50000
================   =======   =======   =======   =======   =======   =======   =======
selection sort        1.00     28.00    115.00    438.00   1007.00   1932.00   3088.00
linear search         0.00      0.01      0.02      0.05      0.07      0.09      0.15

bubble sort           3.00     76.00    323.00   1227.00   2745.00   5097.00   7577.00
insertion sort        1.00     18.00     71.00    323.00    668.00   1148.00   1740.00
binary search         0.00      0.00      0.00      0.00      0.00      0.00      0.00


--------------------------------
Process exited after 39.92 seconds with return value 0
Press any key to continue . . .

*/