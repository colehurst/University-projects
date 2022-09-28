//Cole Hurst
#include <iostream>
#include "Question.h"
using namespace std;


/***************************
Question::Question() : A constructor that initializes the values of a new object
by using the Question class
****************************/
Question::Question()
{
    stem;
    answers[4];
    key = 'X';
}

/****************************
Question::setStem is a void function that calls to a private variable in the
Question class and indirectly changes it using the string st.
****************************/
void Question::setStem (string st)
{
    stem = st;
}

/****************************
Question::getStem is a function thats only use is to retrieve the private
variable called stem.
****************************/
string Question::getStem ()
{
    return stem;
}

/****************************
Question::setAnswers is a voided function that takes an array from the main() and
copies it to the private array called Answers and replaces all 4 variables
inside.
String an[] is the name of the array from the main()
****************************/
void Question::setAnswers (string an[])
{
   answers[0] = an[0];
   answers[1] = an[1];
   answers[2] = an[2];
   answers[3] = an[3];

}

/****************************
Question::getAnswer is a string function that takes a integer called 'i' and
uses it as an address within a private string array called answers, then returns
the single string to the main function.
****************************/
string Question::getAnswer(int i) const
{
    return answers[i];
}

/****************************
Question::setKey is a void function that indirectly changes the private char
called Key. the argument char k is taken from the main() and is used to assign
the new Key.
****************************/
void Question::setKey(char k)
{
   key = k;
}

/***************************
Question::getKey is a char function that indirectly accesses the private
variable key and returns it to the main() without changes.
***************************/
char Question::getKey () const
{
    return key;
}

/***************************
Question::Question is a overloaded constructor that takes the arguments
string st (stem), string an [] (array answers), char k (key) and assigns them
all to private functions within the Questions class for that set object.
***************************/
Question::Question(string st, string an [], char k)
{
    stem = st;
    answers [0] = an [0];
    answers [1] = an[1];
    answers [2] = an[2];
    answers [3] = an[3];
    key = k;
}

/**************************
Question::display() is a void function that takes the values within an object
and displays them to the console. it references the getStem(), getAnswer()
functions within to indirectly access the Question class.
**************************/
void Question::display()
{
    cout << getStem() << endl;
    cout << "A. " << getAnswer (0) << endl << "B. " << getAnswer(1) << endl;
    cout << "C. " << getAnswer (2) << endl << "D. " << getAnswer(3) << endl;

}
