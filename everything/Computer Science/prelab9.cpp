// Lab 9 Pre-Lab Assignment

// Move the indicated code into functions.

#include <iostream>
using namespace std;

void welcome_message()
{
    cout << "Welcome to my fabulous Jedi power level calculator!" << endl
         << "This program will take your age, weight, and" << endl
         << "midichlorean count and return your Jedi power level!"
         << endl << endl;

}

int main()
{

    double jedi_level;

    int age;
    int weight;
    int mcc;

    // TODO - write a void function to print out to console this welcome message
   welcome_message();

    // TODO - write a function that will prompt the user for his/her age,
    // weight, and midicholrean count. Then calculate and return their
    // jedi level (returns a double). Remember to assign the retuned value
    // to the variable 'jedi_level'.
    cout << "please enter your age : ";
    cin >> age;
    cout << "please enter your weight : ";
    cin >> weight;
    cout << "please enter your midicholrean count : ";
    cin >> mcc;
    jedi_level = static_cast <double>(mcc * age) / (weight * weight);

    // this should remain inside your main function
    cout << "Your Jedi Level is : " << jedi_level;

    return 0; }
