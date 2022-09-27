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

using namespace std;

bool isLetter(char c)
{
   bool letter = ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'));

   return letter;
}



int main()
{

   ifstream inFile;
   inFile.open("plain_text.txt");

   ofstream outFile;
   outFile.open("encrypted.txt");

   string word;

   int numWords = 0;

   while (inFile >> word)
   {
      numWords++;
      cout << "word " << numWords << " - " << word << endl;

      string eWord = "";

      for (int i = 0; i < word.length(); i++)
      {
         char c = word[i];

         if (isLetter(c))
         {
            c = (c + 5);
         }

         eWord = eWord + c;
      }


      outFile << eWord << " " << endl;

   }

   cout << "Hey!" << endl;

}
