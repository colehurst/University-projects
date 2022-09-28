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
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
   const int MAX_NUMBER = 10;
   int numbers[MAX_NUMBER];
   const int NUM_NUMS = 1000000;

   unsigned int currentTime = time(NULL);
   srand(currentTime);

   for (int i = 0; i < MAX_NUMBER; i++)
      numbers[i] = 0;

   for (int i = 0; i < NUM_NUMS; i++)
   {
      int num = rand() % MAX_NUMBER;
//cout << num << endl;
      numbers[num] = numbers[num] + 1; //numbers[num]++
   }

   for (int i = 0; i < MAX_NUMBER; i++)
      cout << i << " " << numbers[i] << endl;

   double pctTopHalf;
   int total = 0;

   for (int i = 0; i < MAX_NUMBER/2; i++)
      total = total + numbers[i];

   pctTopHalf = static_cast<double>(total) / NUM_NUMS;

   cout << " The pct of numbers in top half is " << pctTopHalf *100 << "%" << endl;


   cout << "Hey!" << endl;

}
