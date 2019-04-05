// Author: Luis F Suarez Harasic;  Course: COSC 1337 Spring 2019 TT17;  Instructor: Thayer
// Lab 7: Inventory Class.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <typeinfo>
using namespace std;

class InventoryItem

{

  private:
    string description;

    int itemNumber;

    double cost;

    int quantity;

  public:
    InventoryItem()

    {

        description = "Empty Inventory";

        itemNumber = 0;

        cost = 0.0;

        quantity = 0;
    }

    // Constructor

    InventoryItem(string desc, int num, double c, int q)

    {
        if (num >= 0 && c >= 0 && q >= 0)
        {
            description = desc;

            itemNumber = num;

            cost = c;

            quantity = q;
        }

        else
        {
            setError();
        }
    }

    void setError()
    {
        description = "Unable to create inventory";

        itemNumber = 0;

        cost = 0.0;

        quantity = 0;
    }

    void setItemNumber(int num)

    {
        if (num >= 0)
        {
            itemNumber = num;
        }
        else
        {
            setError();
        }
    }

    int getItemNumber()

    {

        return itemNumber;
    }

    // Setters

    void setDescription(string des)

    {
        description = des;
    }

    string getDescription()

    {
        return description;
    }

    void setCost(double co)

    {
        if (co >= 0)
        {
            cost = co;
        }
        else
        {
            setError();
        }
    }

    // getters

    double getCost() const
    {
        return cost;
    }

    double getTotalCost()
    {
        return cost * quantity;
    }

    void setQuantity(int qu)
    {
        if (qu >= 0)
        {
            quantity = qu;
        }
        else
        {
            setError();
        }
    }

    int getQuantity() const
    {
        return quantity;
    }
};

int main()

{

    cout << endl
         << endl;
    cout << "               ****************************************" << endl;
    cout << "               *            Inventory Class           *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               *                 LAB7                 *" << endl;
    cout << "               *                                      *" << endl;
    cout << "               ****************************************" << endl
         << endl
         << "        This Lab creates an inventory with the help of classes" << endl
         << endl;

    system("pause");

    cout << endl
         << " Here is an example of an inventory, created with default constructor:" << endl;
    cout << "";
    InventoryItem item0;

    cout << endl
         << "   Item 0:" << endl;

    cout << "   Description: " << item0.getDescription() << endl;

    cout << "   Item Number: " << item0.getItemNumber() << endl;

    cout << "   Quantity: " << item0.getQuantity() << endl;

    cout << "   Cost: " << item0.getCost() << endl;

    cout << "   Total Cost: " << item0.getTotalCost() << endl
         << endl;

    system("pause");

    cout << endl
         << " Here is an example of an inventory, created with a parametrized constructor:" << endl;
    cout << "";
    InventoryItem item1("Silver Hammer", 1, 20, 5);

    cout << endl
         << "   Item 1:" << endl;

    cout << "   Description: " << item1.getDescription() << endl;

    cout << "   Item Number: " << item1.getItemNumber() << endl;

    cout << "   Quantity: " << item1.getQuantity() << endl;

    cout << "   Cost: " << item1.getCost() << endl;

    cout << "   Total Cost: " << item1.getTotalCost() << endl
         << endl;

    system("pause");

    cout << endl
         << " Here is an example of an inventory using setters and getters;" << endl;
    cout << "";
    InventoryItem item2;

    item1.setDescription("Golden Axe");

    item1.setItemNumber(2);

    item1.setCost(72.99);

    item1.setQuantity(10);

    cout << endl
         << "   Item 2:" << endl;

    cout << "   Description: " << item1.getDescription() << endl;

    cout << "   Item Number: " << item1.getItemNumber() << endl;

    cout << "   Quantity: " << item1.getQuantity() << endl;

    cout << "   Cost: " << item1.getCost() << endl;

    cout << "   Total Cost: " << item1.getTotalCost() << endl
         << endl;

    system("pause");

    cout << endl
         << " Here is an example of an inventory using wrongfull data;" << endl;
    cout << "Item number = 3 ; Quantity = 100 ; Cost = -$0.10" << endl;
    InventoryItem item3;

    item1.setDescription("Wooden Nail");

    item1.setItemNumber(3);

    item1.setQuantity(100);

    item1.setCost(-0.10);

    cout << endl
         << "   Item 3:" << endl;

    cout << "   Description: " << item3.getDescription() << endl;

    cout << "   Item Number: " << item3.getItemNumber() << endl;

    cout << "   Quantity: " << item3.getQuantity() << endl;

    cout << "   Cost: " << item3.getCost() << endl;

    cout << "   Total Cost: " << item3.getTotalCost() << endl
         << endl;
}

/*


               ****************************************
               *            Inventory Class           *
               *                                      *
               *                                      *
               *                 LAB7                 *
               *                                      *
               ****************************************

        This Lab creates an inventory with the help of classes

Press any key to continue . . .

 Here is an example of an inventory, created with default constructor:

   Item 0:
   Description: Empty Inventory
   Item Number: 0
   Quantity: 0
   Cost: 0
   Total Cost: 0

Press any key to continue . . .

 Here is an example of an inventory, created with a parametrized constructor:

   Item 1:
   Description: Silver Hammer
   Item Number: 1
   Quantity: 5
   Cost: 20
   Total Cost: 100

Press any key to continue . . .

 Here is an example of an inventory using setters and getters;

   Item 2:
   Description: Golden Axe
   Item Number: 2
   Quantity: 10
   Cost: 72.99
   Total Cost: 729.9

Press any key to continue . . .

 Here is an example of an inventory using wrongfull data;
Item number = 3 ; Quantity = 100 ; Cost = -$0.10

   Item 3:
   Description: Empty Inventory
   Item Number: 0
   Quantity: 0
   Cost: 0
   Total Cost: 0


--------------------------------
Process exited after 2.449 seconds with return value 0
Press any key to continue . . .



*/