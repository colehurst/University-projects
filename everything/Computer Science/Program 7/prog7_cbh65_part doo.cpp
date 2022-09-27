/*
File Name: prog07__cbh65.cpp

Lab Section Number: 14
Lab Section Instructor: Jessica

Author: Cole Hurst
Date: 4.12.2017
Problem Number: 7
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
    int numExams = 0;
    int student_num = 1;
    int student_score = -1;
    string key;
    string exam;
    const int MAX_NUM = 11;
    int scores[MAX_NUM];
    double total = 0;
    double average = 0;
    int highest = 0;
    int lowest = 0;

    for(int i = 0; i < MAX_NUM; i++)
        scores[i] = 0;

    //Get Key
    ifstream inFile;
    ofstream outFile;
    inFile.open("grade_data.txt");
    outFile.open("grade_report.txt");
    inFile >> key;


    //grade exam
    while(inFile >> exam)
    {

        for (int i = 0; i <= key.length(); i++)
        {
            if(key[i] == exam[i])
            student_score = student_score + 1;
        }

        //finding the total value of all the grades
        total = total + student_score;
        //assigning grades to the final report array

        outFile << "student " << student_num << " - " << student_score
         << endl;

        scores[student_score] =  scores[student_score] + 1;
        student_score = -1;
        student_num ++;

    }

    outFile << "Final Report" << endl << "-----------" << endl;

    for (int i = 10; i >=  0; i--)
    {
        outFile << i << " - " << scores[i] << endl;
    }

     //finding the highest grade
     for (int i = 0; i < MAX_NUM; i++)
     {
        if (scores[i] > 0)
            highest = i;
     }

    outFile << "high score - " << highest << endl;

    //finding the lowest score
    for (int i = 10; i >= 0; i--)
    {
        if (scores[i] > 0)
            lowest = i;
    }

    outFile << "lowest score - " << lowest << endl;

    //taking the mean(ing) of it all
    student_num = student_num - 1;
    average = total / student_num;
    outFile << "mean score - " << average;
    outFile.close();

}
