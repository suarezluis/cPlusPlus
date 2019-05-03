/*
  Author:
  Assignment:      Lab 10
  Topic:           memory diagram with stack, heap structures
  File Name:
  Course/Section:  COSC 1337
  Due Date:        See syllabus or blackboard
  Instructor:      Thayer
*/

/*
This lab is on pointers. It covers: values, addresses, pointers, the heap,
dynamic memory allocation using new, delete, delete [].
It also has a very brief introduction to linked lists, a basic data structure.

Create a program that uses memory as shown in the memory diagram provided.
Start with this startup code, which has useful macros to display variables.
Wherever possible, set the values of all variables indirectly using
pointers. Use pointer dereferencing to set the values of the "pointed to"
variables. You can "dereference" pointers with the '*' operator.  For example,
to set price to $19.95, do NOT use the variable price. Instead, use the pointer
variable *p_price. To set pi_div_2, dereference p_PI to get 3.141592, divide it
by two, and place the result into PI_div_2.

To create the "linked list" containing Person "Harry" and Person "Sally",
you need the following data structure. You should enhance this, as desired,
with constructors, setters, etc.

class Person {
  string name;     // name of the person
  Person *next;    // pointer to the next person in the list
};

To create instances of Person, use:
  1) stack allocation: Person wizard will be on the stack, allocated statically when entering scope;
  2) heap allocation:  Persons "Harry" and "Sally" are allocated dynamically on the heap with new

To manipulate an object of class Person, you need to create some constructors,
getters and setters to fill in the name and set the pointers, or, you could make
the data members public and use  "dot" notation, such as: Person wizard;
wizard.name="Gandalf"; wizard.next=nullptr;
For dynamically allocated instances, you can use arrow notation,
such as: personList -> name="Harry".

Use the keyword "nullptr" (since C++11/14) as the recommended way of setting
a pointer to point to nothing. Do NOT use NULL or 0; this invites errors.

To create variables on the heap, with no names, you have to use new to dynamically
allocate the memory. See sample output (bottom page). IMPORTANT: Every new should
be matched by a delete to prevent a memory leak! IMPORTANT: Make sure you delete
all memory you dynamically allocate before leaving main(). Don't allow any memory
leaks. Match all new with delete. When deleting an array, use delete [] array.

After items are placed in memory, use cout statements to output the addresses
and values of all variables. Output the addresses of all variables
(both pointer and named) in hexadecimal format, and output the contents (values)
of all int, float, double and string variables.

You cannot force the memory layout to be exactly in the order in the memory diagram.
As a programmer, you don't  control exactly WHERE in memory the compiler places
variables. The important thing is for you to create the pointer variables,
value variables, and set them up (nearly) as depicted in the memory diagram.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
  public:
	string name;  // name of the person
	Person *next; // pointer to the next person in the list
};

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own function that does something similar
#define show_addr_value(var, width)                                                  \
	cout << "address of " << setw(width) << left << #var << " is: &" << &var << "  " \
		 << "contents of " << setw(width) << left << #var << " is: " << var << endl;

#define show_addr(var, width) \
	cout << "address of " << setw(width) << left << #var << " is: &" << &var << endl;

int main()
{
	cout << "Output from Lab10 memory diagram on pointers:\n\n";

	float price = 0;
	float *p_price = &price;
	*p_price = 19.95;
	show_addr_value(price, 8);
	show_addr_value(p_price, 8);
	cout << "The contents of *p_price is: " << *p_price << endl;

	//	My code starts here ----->

	cout << endl;
	double PI = 3.141592;
	double *p_PI = &PI;
	double PI_div_2 = *p_PI / 2;
	show_addr_value(PI, 8);
	show_addr_value(PI_div_2, 8);
	show_addr_value(p_PI, 8);
	cout << "The contents of *p_PI is: " << (dec) << *p_PI << endl;

	// p_size ------>

	cout << endl;
	int maxSize = 5028;
	int *p_size = &maxSize;
	show_addr_value(maxSize, 8);
	show_addr_value(p_size, 8);
	cout << "The contents of *p_size is: " << (dec) << *p_size << endl;

	// p_ammount ------->

	cout << endl;
	int *p_amount;
	p_amount = new int;
	*p_amount = 1234;
	show_addr_value(p_amount, 8);
	cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
	delete p_amount;
	cout << "After delete, the contents of p_amount is: " << p_amount << endl;
	p_amount = nullptr;
	cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl;

	// p_array ------->

	cout << endl;
	int *pArray, arraySize = 3;
	pArray = new int[arraySize];

	for (int count = 0, val = 11; count < arraySize; count++, val += 11)
	{
		pArray[count] = val;
	}
	show_addr_value(pArray, 8);
	show_addr_value(pArray[0], 8);
	show_addr_value(pArray[1], 8);
	show_addr_value(pArray[2], 8);
	delete[] pArray;
	cout << "After delete [], the contents of pArray is: " << pArray << endl;
	pArray = nullptr;
	cout << "After reset to nullptr, the contents of pArray is: " << pArray << endl;

	cout << endl;
	Person *emptyList;
	show_addr_value(emptyList, 8);

	cout << endl;
	cout << "static (uses: Person wizard):\n";
	Person wizard;
	wizard.name = "Gandalf";
	wizard.next = nullptr;
	show_addr(wizard, 8);
	show_addr_value(wizard.name, 8);
	show_addr_value(wizard.next, 8);
	cout << endl;

	cout << endl;
	cout << "dynamic (uses: personList, Person(\"Harry\"), Person(\"Sally\"):\n";
	Person *personList = new Person; // create a person object on the heap
	show_addr_value(personList, 8);
	personList->name = "Harry";		 // Giving a name through pointer
	(*personList).next = new Person; // create another person object on the heap
	show_addr_value(personList->name, 8);
	show_addr_value(personList->next, 8);
	personList->next->name = "Sally"; // Giving a name through pointer
	personList->next->next = nullptr;
	cout << " <follow link to next Person on personList>\n";
	show_addr_value(personList->next->name, 8);
	show_addr_value(personList->next->next, 8);

	delete personList; //Return to the daemon

	/* Output comments, formats results, use as desired.
  cout << "The contents of *p_PI is:    " << *p_PI << endl;
  cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
  cout << "After delete, the contents of p_amount is: " << p_amount << endl;
  cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl;
  cout << "After delete [], the contents of pArray is: " << pArray << endl;
  cout << "After reset to nullptr, the contents of pArray is: " << pArray << endl;
  cout<<"stack allocation (uses: Person wizard):\n";
  cout<<"heap allocation (uses: personList, Person(\"Harry\"), Person(\"Sally\"):\n";
  cout << "  <follow link to next Person on personList>\n";
  */

	//  Finally perform output
	cout << "The contents of *p_PI is:    " << *p_PI << endl;
	cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
	cout << "After delete, the contents of p_amount is: " << p_amount << endl;
	cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl;
	cout << "After delete [], the contents of pArray is: " << pArray << endl;
	cout << "After reset to nullptr, the contents of pArray is: " << pArray << endl;
	cout << "static (uses: Person wizard):\n";
	cout << "dynamic (uses: personList, Person(\"Harry\"), Person(\"Sally\"):\n";
	cout << " <follow link to next Person on personList>\n";
	return 0;
} // end of main

/*

Output from Lab10 memory diagram on pointers:

address of price    is: &0x70fdf0  contents of price    is: 19.95
address of p_price  is: &0x70fde8  contents of p_price  is: 0x70fdf0
The contents of *p_price is: 19.95

address of PI       is: &0x70fde0  contents of PI       is: 3.14159
address of PI_div_2 is: &0x70fdd0  contents of PI_div_2 is: 1.5708
address of p_PI     is: &0x70fdd8  contents of p_PI     is: 0x70fde0
The contents of *p_PI is: 3.14159

address of maxSize  is: &0x70fdcc  contents of maxSize  is: 5028
address of p_size   is: &0x70fdc0  contents of p_size   is: 0x70fdcc
The contents of *p_size is: 5028

address of p_amount is: &0x70fdb8  contents of p_amount is: 0xad1580
The contents of *p_amount is: 1234
After delete, the contents of p_amount is: 0xad1580
After reset to nullptr, the contents of p_amount is: 0

address of pArray   is: &0x70fdb0  contents of pArray   is: 0xad1580
address of pArray[0] is: &0xad1580  contents of pArray[0] is: 11
address of pArray[1] is: &0xad1584  contents of pArray[1] is: 22
address of pArray[2] is: &0xad1588  contents of pArray[2] is: 33
After delete [], the contents of pArray is: 0xad1580
After reset to nullptr, the contents of pArray is: 0

address of emptyList is: &0x70fda8  contents of emptyList is: 0

static (uses: Person wizard):
address of wizard   is: &0x70fd90
address of wizard.name is: &0x70fd90  contents of wizard.name is: Gandalf
address of wizard.next is: &0x70fd98  contents of wizard.next is: 0


dynamic (uses: personList, Person("Harry"), Person("Sally"):
address of personList is: &0x70fd88  contents of personList is: 0xad1580
address of personList->name is: &0xad1580  contents of personList->name is: Harry
address of personList->next is: &0xad1588  contents of personList->next is: 0xad5ae0
 <follow link to next Person on personList>
address of personList->next->name is: &0xad5ae0  contents of personList->next->name is: Sally
address of personList->next->next is: &0xad5ae8  contents of personList->next->next is: 0
The contents of *p_PI is:    3.14159

--------------------------------
Process exited after 0.7603 seconds with return value 3221225477
Press any key to continue . . .


*/
