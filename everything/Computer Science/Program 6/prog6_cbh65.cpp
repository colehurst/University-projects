/*
File Name: prog06__cbh65.cpp

Lab Section Number: 14
Lab Section Instructor: Jessica

Author: Cole Hurst
Date: 3.27.2017
Problem Number: 6
CS 1428 Spring 2017
Lecture Instructor: Priebe

Lecture Session: TTH 12:30-2:00

*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

int main ()
{
    const int MAX_DAYS = 31;
    const int MAX_TEMP = 100;
    double temp [MAX_DAYS];
    double temper = 0;
    string month;
    int total = 0;
    int hot_days = 0;
    int high = 0;

    int num_days = 0;

    ifstream inFile;
    inFile.open("summer_temps.txt");

    inFile >> month;

    while (inFile >> temp[num_days])
    {
        num_days ++;

    }

    setprecision(2);
    ///////////////////////////////////////////////

    for (int i = 0; i < num_days; i++)
    {
      total = total + temp[i];
    }

    double avg = static_cast<double> (total) / num_days;

    cout << "Average daily high temperature in " << month << " is: ";
    cout << avg << endl;

    //////////////////////////////////////////////

    for (int i = 0; i < num_days; i++)
    {
        if(temp[i] > MAX_TEMP)
            hot_days++;

    }

    cout << "Number of days over 100 in " << month << ": " << hot_days << endl;
    ///////////////////////////////////////////////

    for (int i = 0; i < num_days; i++)
    {
        if (temp[high] < temp[i])
            high = i;
    }
    cout << "Maximum temperature: " << temp[high] << " (occurred on ";
    cout << month << " " << high + 1 << ")";
}
