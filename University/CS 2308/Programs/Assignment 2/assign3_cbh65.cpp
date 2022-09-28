/****************************************************
File Name: assign3_cbh65.cpp

Author: Cole Hurst
Date: 3.3.2018
Assignment Number: 3
CS 2308.262 Spring 2018
Lecture Instructor: Yijuan Lu


This program will make use of four different functions to demonstrate
the use of pointers in C++.
*****************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

/*****************************************************
isSorted: takes an array of integers and converts it into a pointer while
it is inside the function.
int *arr : creates a pointer that points to the location of arr1, arr2, arr3
int arrSize: the size of the array
******************************************************/
bool isSorted (int * arr, int arrSize)
{
    bool result;
    for (int i = 0; i < arrSize ; i++)
        {
            if ( *(arr + i) <= *(arr + i + 1))
                result = true;
            else
            {
                //if the next number in the sequence is lower, it will return a
                //false result
                result = false;
                return result;
            }
        }
    //if it successfully went through the loop it will return true.
    return result;
}

/*******************************************************
chain: This function takes in a constant of inches by using pass by
reference when calling to the function and then switching to pointer when
calculating the data then returns the results as a double.
int totalInches: a constant of the total amount of inches
int *in: pointers that point to the location of the inches integer
int *fe: pointers that point to the location of the feet integer
*********************************************************/
double chain (int totalInches, int *in, int *fe)
{
    *fe = totalInches/12;
    *in = totalInches%12;
    return *fe*3.49 + *in*.30;
}

/********************************************************
*grow: This function takes an array of integers and creates a new array
that doubles each element in an array so the array is double the size.
int *pregrow: a pointer that points to the location of the array growArr.
int bigness: the size of the array growArr
********************************************************/
int *grow (int *pregrow, int bigness)
{
    int Newbigness = bigness * 2;
    //creating a dynamic memory allocation
    int *temper = new int[Newbigness];

    for (int i = 0; i < bigness; i++)
    {
        if (i == 0)
        {
            *(temper + i) = *(pregrow + i);
            *(temper + i + 1) = *(pregrow + i);
        }
        else
        {
            *(temper + (i * 2)) = *(pregrow + i);
            *(temper + ((i * 2) + 1)) = *(pregrow + i);
        }
    }
    return temper;
}

/*******************************************************
duplicateArray: This function takes a parent array, then creates a duplicate
array that will be identical to the original by using a pointer
*arr: the input array that will be copied
*******************************************************/
int *duplicateArray (int *arr, int size)
{

   int *newArray;
   if (size <= 0)
      return NULL;

   newArray = new int [size];

   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];

   return newArray;
}
/******************************************************
Creates a pointer called result that contains the address of the new array
int *array:pointer to the address of the array sArray
int start: references the int start
int length: references the int length
******************************************************/
int *subArray (int *array, int start, int length)
{
 int *result = duplicateArray((array + start), length);
 return result;
}

int main()
{
// isSorted function is called to here
    const int ARRAYSIZE = 8;
    int arr1[ARRAYSIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[ARRAYSIZE] = {8, 7, 6, 5, 4, 3 ,2 ,1};
    int arr3[ARRAYSIZE] = {1, 2, 3, 5, 4, 6, 7, 8};
    bool isSorted_Return1;
    bool isSorted_Return2;
    bool isSorted_Return3;

    //calls to the isSorted function using the 3 different arrays
    isSorted_Return1 = isSorted (arr1, ARRAYSIZE);
    isSorted_Return2 = isSorted (arr2, ARRAYSIZE);
    isSorted_Return3 = isSorted (arr3, ARRAYSIZE);

    //displays the names of each array then declares whether the results
    //will be true or false using an if else statement for each of the results.
    cout << "testing isSorted:" << endl;
    cout << "test data array 1: 1 2 3 4 5 6 7 8" << endl;
    cout << "Expected result: true" << endl;
    cout << "Actual result: ";
    if (isSorted_Return1 == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "test data array 2: 8 7 6 5 4 3 2 1" << endl;
    cout << "Expected result: false" << endl;
    cout << "Actual result: ";

    if (isSorted_Return2 == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "test data array 1: 1 2 3 5 4 6 7 8" << endl;
    cout << "Expected result: false" << endl;
    cout << "Actual result: ";

    if (isSorted_Return3 == 1)
        cout << "true" << endl << endl;
    else
        cout << "false" << endl << endl;

    //declaring the variables for the chain function
    int feet;
    int inches;
    int totalinches = 53;
    double chainResults;

    chainResults = chain (totalinches, &inches, &feet);

    cout << "testing chain for 53 inches:" << endl;
    cout << "Expected result: 15.46 feet: 4 inches: 5" << endl;
    cout << "Actual Results : " << chainResults << " feet: " << feet;
    cout << " inches: " << inches << endl << endl;

    //declaring the variables for the grow function
    int const GROWSIZE = 9;
    int const NEWGROW = 18;
    int growArr[GROWSIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int * temper = grow(growArr, GROWSIZE);

    cout << "testing grow:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 9" << endl;
    cout << "Expected result: 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9" << endl;
    cout << "Actual result: ";

    for (int i = 0; i < NEWGROW; i++)
        cout << *(temper + i) << " ";
    //deleting the dynamic memory allocation created
    delete [] temper;

    //creating the variables for the subArray function
    int const SUBMAX = 9;
    int length = 4;
    int start = 5;
    int sArray[SUBMAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * newarray;


    cout << endl << endl << "testing subArray: " << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 9" << endl;
    cout << "start: 5 length: 4" << endl;
    cout << "Expected result: 6 7 8 9" << endl;
    cout << "Actual result:  ";

    newarray = subArray(sArray, start, length);
    for (int i = 0; i < length; i++)
    {
       cout << *(newarray + i) << " ";
    }
}
