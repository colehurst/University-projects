#include <iostream>

using namespace std;

int main()
{
    // 1.
    // There are a several errors with the below code
    // Fix the syntax and logical errors.

    // The Program should take two integers from the user and assign them to x and y.
    // The program should then print the square of x and y + 10

    int x;
	int y;

	x *= x;

	y += 10;

	cout << "Enter the value for X" << endl;
	cin >> x ;

	cout << "Enter the value for Y" << endl;
	cin >> y;


	cout << "X squared = " << x << endl
	     << "Y + 10  = " << y << endl;



    // 2.
    // Write code that takes the number of pounds the user
    // can lift (use cin), divides that number by 2.20462, and then
    // prints it to the screen. This will convert pounds to kg.
    // (200 pounds is equal to 90.7186 kilograms)

	cout << "Many pounds can you lift?" << endl;

	// write your code here

	int pounds;
	double const kg = 2.20462;

	cin >> pounds;

	double e = pounds / 2.20462;

	cout << "How much you lift in kilograms is: " << e << endl;








	return 0;
}
