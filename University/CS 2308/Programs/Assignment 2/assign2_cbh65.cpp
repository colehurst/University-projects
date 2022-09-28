/****************************************************
File Name: assign2_cbh65.cpp

Author: Cole Hurst
Date: 2.17.2018
Assignment Number: 2
CS 2308.262 Spring 2018
Lecture Instructor: Yijuan Lu


This program allows the user to manage their small store's inventory by listing
out a menu that details a products name, SKU, quantity, and price to the user.
*****************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

//creating a structure to organize the values of a product.
struct Product
    {
        string name;
        int sku;
        int quantity;
        double price;
    };

//a function that sorts all the products in order using bubble sort
void SortSku (Product inventory [], int total)
{
    bool swap;
    Product temp;

    do
    {
        swap = false;
        for (int i = 0; i < (total- 1); i++)
        {
            if (inventory[i].sku > inventory[i + 1].sku)
            {
                temp = inventory[i];
                inventory[i] = inventory[i + 1];
                inventory[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

//a function that will search an array using a binary search
int SearchSku (int InputSku, int total, Product Inventory[])
{
    int first = 0;
    int last = total - 1;
    int middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (Inventory[middle].sku == InputSku)
        {
            found = true;
            position = middle;
        }
        else if (Inventory[middle].sku > InputSku)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

//uses a linear search to find the product name by exact match
int SearchName (string ProductName, int total, Product Inventory[])
{
    int i = 0;
    int position = -1;
    bool found = false;

    while (i < total && !found)
    {
        if(Inventory[i].name == ProductName)
        {
            found == true;
            position = i;
        }
        i++;
    }
    return position;
}

int main()
{
    const int MAX_PRODUCT = 100;
    Product inventory [MAX_PRODUCT];
    string name;

    ifstream inFile;
    inFile.open("inventory.dat");

    //reading in the values of the input file into the product array.
    int num_items = 0;
    while (inFile >> name)
    {
        inventory[num_items].name = name;
        inFile >> inventory[num_items].sku;
        inFile >> inventory[num_items].quantity;
        inFile >> inventory[num_items].price;
        num_items++;
    }
    //Sorting the inventory data
    SortSku (inventory, num_items);

    //These are the 4 options for the menu and variables needed for the options.
    const int DISPLAY_INVENTORY = 1;
    const int LOOKUP_SKU = 2;
    const int LOOKUP_NAME = 3;
    const int QUIT_CHOICE = 4;
    int choice;
    int InputSku;
    int SkuReturn;
    string ProductName;
    int NameReturn;

    //
    do
    {
        cout << endl << "Manage Inventory Menu" << endl << endl;
        cout << "1. Display inventory sorted by sku" << endl;
        cout << "2. Lookup a product by sku" << endl;
        cout << "3. Lookup a product by name" << endl;
        cout << "4. Quit the program" << endl;
        cin >> choice;

        //To assure only valid menu choices are selected
        while (choice < DISPLAY_INVENTORY || choice > QUIT_CHOICE)
        {
            cout << "Please enter a valid input: ";
            cin >> choice;
        }

        if (choice == 1)
        {
            //Displays all the products within the store in columns
            cout << setw(15) << "SKU" << setw(15) << "QUANTITY";
            cout << setw(15) << "PRICE" << setw(20) << "NAME" << endl;
            for (int i = 0; i < num_items; i++)
            {
                cout << setw(15) << inventory[i].sku;
                cout << setw(15) << inventory[i].quantity;
                cout << setw(15) << inventory[i].price;
                cout << setw(20)  << inventory[i].name << endl;
            }
        }

        if (choice == 2)
        {
            //asks for a products sku and calls to a function to find a match
            //within the inventory array.
            cout << "Please enter the sku of the product to find: ";
            cin >> InputSku;

            SkuReturn = SearchSku(InputSku, num_items, inventory);

            if (SkuReturn == -1)
                cout << "No product found with this sku. " << endl;
            else
            {
                cout << "Product name: " << inventory[SkuReturn].name << endl;
                cout << "SKU: " << inventory[SkuReturn].sku << endl;
                cout << "Quantity: " << inventory[SkuReturn].quantity << endl;
                cout << "Price: " << fixed << setprecision(2);
                cout << inventory[SkuReturn].price << endl;
            }
        }

        if (choice == 3)
        {
            //asks for a product name then compares it to those in the array
            //by calling to a linear search function.
            cout << "Enter the name of product to find:  ";
            cin >> ProductName;

            NameReturn = SearchName(ProductName, num_items, inventory);

            if (NameReturn == -1)
                cout << "No product found with this product name. " << endl;
            else
            {
                cout << "Product name: " << inventory[NameReturn].name << endl;
                cout << "SKU: " << inventory[NameReturn].sku << endl;
                cout << "Quantity: " << inventory[NameReturn].quantity << endl;
                cout << "Price: " << fixed << setprecision(2);
                cout << inventory[NameReturn].price << endl;
            }
        }
    } while (choice != QUIT_CHOICE);
        cout << "exiting program.";

}
