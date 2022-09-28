/****************************************************
File Name: assign4_cbh65.cpp

Author: Cole Hurst
Date: 4.1.2018
Assignment Number: 4
CS 2308.262 Spring 2018
Lecture Instructor: Yijuan Lu


This program makes a quiz utilizing classes, header files, and member files
that are called to via the driver  file. Without directly referencing specific
private variables called ls
 stem, answers[], and key.
*****************************************************/
using namespace std;
#include <iostream>
#include "Question.cpp"
int main()
{
    Question q[5];

    //makes a unique object using the Question class called Q1 then displays it
    string q1Answers [] = {"Nibble","Ort","Scrap","Snippet"}; //answer A
    Question q1 ("What name is given to half of a Byte (4 bits)?", q1Answers,'A');
    cout << "1. ";
    q1.display();
    cout << endl;

    //makes a unique object using the Question class called Q2 then displays it
    string q2Answers [] = {"China","India","Mexico","Australia"}; //answer D
    Question q2 ("Which country is home to the Kangaroo?", q2Answers, 'D');
    cout << "2. ";
    q2.display();
    cout << endl;

    //makes a unique object using the Question class called Q3 then displays it
    string q3Answers [] = {"Compass","Protractor","Ruler","T-Square"}; //ans B
    Question q3 ("What do you use to measure an angle?", q3Answers, 'B');
    cout << "3. ";
    q3.display();
    cout << endl;

    //makes a unique object using the Question class called Q4 then displays it
    string q4Answers [] = {"Camel","Eagle","Lion","Alligator"}; //answer C
    Question q4 ("The Great Sphinx has the head of a human "
                  "and the body of a what?", q4Answers,'C');
    cout << "4. ";
    q4.display();
    cout << endl;

    //makes a unique object using the Question class called Q5 then displays it
    string q5Answers [] = {"Birdie","Puck","Dart","Tile"}; //answer B
    Question q5("What is the flat rubber disc used in a game of ice hockey?",
                q5Answers, 'B');
    cout << "5. ";
    q5.display();
    cout << endl;

    //calls to the keys of all the objects (Q1-Q5) and displays them
    //uses the function getKey() to indirectly access the class Question
    cout << "Answers:" << endl;
    cout << q1.getKey() << " " << q2.getKey() << " " << q3.getKey() << " ";
    cout << q4.getKey() << " " << q5.getKey();
}
