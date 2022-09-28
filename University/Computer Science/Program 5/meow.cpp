/****************************************************
File Name:prog01__RP44.cpp

Lab Section Number:
Lab Section Instructor:

Author: Your Name Here
Date: 8/31/2015
Problem Number: 1
CS 1428 Fall 2016
Lecture Instructor: Priebe



A short description of what the program does.
*****************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void getData(int exams[], int &examCount)
{
   ifstream inFile;
   inFile.open("exams.txt");

   int exam;

   while (inFile >> exam)
   {
      exams[examCount] = exam;
      examCount++;
   }

}

void bumpScores(int exams [], int numExams, int MAX_SCORE, int bonus)
{
   for (int i = 0; i < numExams; i++)
   {
      exams[i] = exams[i] + bonus;

      if (exams[i] > MAX_SCORE)
         exams[i] = MAX_SCORE;
   }
}


int findLowest(int exams[], int numExams)
{
   int low = 0;

   for (int i = 1; i < numExams; i++)
   {
      if (exams[low] > exams[i])
         low = i;
   }

   return low;
}

double calcAverage(int exams[], int numExams)
{
   int total = 0;

   for (int i = 0; i < numExams; i++)
   {
      total = total + exams[i];
   }

   double avg = static_cast<double> (total) / numExams;

   return avg;

}



int main()
{
   const int MAX_STUDENTS = 50;
   const int MAX_SCORE = 100;
   int exams[MAX_STUDENTS];

   int numExams = 0;

   //function to fill the array with the input file
   getData(exams, numExams);

   for (int i = 0; i < numExams; i++)
      cout << i << " " << exams[i] << endl;

   bumpScores(exams,numExams,MAX_SCORE,10);

   cout << endl;
   for (int i = 0; i < numExams; i++)
      cout << i << " " << exams[i] << endl;

   //returns the index of the smallest element
   int lowest = findLowest(exams, numExams);

   cout << exams[lowest] << " in spot " << lowest << endl;

   cout << "the average is "
        << calcAverage(exams, numExams) << endl;



   cout << "Hey!" << endl;

}
