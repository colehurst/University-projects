// PreLab 5 Assignment

// The following is an extremely scientific personality test that can predict
// how well you will do in this course.
// Fill in the area below with the requested code.

#include <iostream>

using namespace std;

int main()
{
    char answer;

    cout << "Is Star Trek better than Star Wars? ('Y' or 'N')" << endl;
    cin >> answer;

    // TODO - Change the following IF-ELSE statement to an
    // equivalent switch statement.

    switch (answer)
    {
        case 'Y':
        case 'y':
                cout << "Wrong! You are likely to fail this class..." << endl;
                break;
        case 'N':
        case 'n':
                cout << "Correct!";
                cout << "You will undoubtedly ace this class!!!!" << endl;
                break;
        default:
                cout << "Invalid Input.";
                cout << "This does not bode well for you." << endl;
                break;
    }
}
