// Lab 10 Pre-Lab Assignment

// Add the following functions:

// 1. 'getRadius' asks the user to enter the radius of a circle
//     and returns the given value. (should return a double)

// 2. 'calcArea' takes the radius and returns the area of a circle.

// 3. 'printResults' void type function that should print the results to
//    console.

// Your function needs to have a local variable called 'PI' which holds the
// value '3.14159'.

// The function call is provided, you just need to implement the
// function prototype and function definition.

#include <cmath>
#include <iostream>
using namespace std;

// TODO - write the prototypes here
void printResults(double);

int main()
{
    double radius;
    double area;


    // TODO - call 'getRadius' function and assign the
	//        returned value to radius.

    double getRadius(double);
    radius = getRadius();

    double calc_area(radius);
    area = calc_area;

	// TODO - move the following cout to the 'printResults' function
	//        and call that function here instead.

    printResults(area);

    return 0;
}

// TODO - write the functions here

double getRadius(double radius)
{
    cout << "Please enter the radius of the circle" << endl;
    cin >> radius;

    return radius;
}

double calc_area(double radius)
{
   const double PI = 3.14159;
   double area;

   area = (radius * radius) * PI;

   return area;
}
void printResults (double area)
{
    cout << "The area of your circle is " << area << " units squared."
             << endl;

}
