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
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Golfer
{
   string name;
   int handicap;
   string email;
};

int compareGolfers(Golfer g1, Golfer g2)
{
   int difference = g1.handicap - g2.handicap;

   return difference;
}


int main()
{

   string fileName = "golf_struct.txt";

   const int MAX_GOLFERS = 100;
   Golfer golfers[MAX_GOLFERS];
   int numGolfers = 0;

   ifstream inFile;
   inFile.open(fileName.c_str());

   string name;

   while (inFile >> name)
   {
      //shows two different ways of reading from the input file
      golfers[numGolfers].name = name;
      inFile >> golfers[numGolfers].handicap;
      inFile >> golfers[numGolfers].email;

      numGolfers++;
   }

   for (int i = 0; i < numGolfers; i++)
   {
      cout << golfers[i].name << " "
           << golfers[i].handicap << " "
           << golfers[i].email << endl;
   }

   cout << compareGolfers(golfers[0], golfers[1]) << endl;


   //helpful math stuff
   double x1 = 0.5;
   double x2 = 3.4222;

   double diffSquared = pow((x2-x1), 2);
   cout << diffSquared << endl;

   cout << sqrt(diffSquared) << endl;


   cout << "Hey!" << endl;

}
