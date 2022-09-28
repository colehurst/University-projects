#ifndef QUESTION1_H_INCLUDED
#define QUESTION1_H_INCLUDED

//Cole Hurst
#include <iostream>

using namespace std;

class Question {
  private:
    string stem;
    string answers[4];
    char key;

  public:
    void setStem(string);
    string getStem();
    void setAnswers(string[]);
    string getAnswer(int) const;
    void setKey(char);
    char getKey() const;
    void display();
    Question ();
    Question (string , string [] , char);
    };

#endif // QUESTION1_H_INCLUDED
