/****************************************************
File Name:prog04__cbh65.cpp

Author: Cole Hurst

Lecture Section: TTH 12:30-1:50
Lab Instructor: Jessica
Lab Section: L14

Date: 2/21/2017
Problem Number: 4
CS 1428 Spring 2017
Instructor: Priebe

The program will take an input file of a student with
his first name, last name, how many tests he took and
his grade for the tests and will create a web page
with his calculated average, his grade letter and
whether the student passed or not.
*****************************************************/

#include <iostream>
#include <fstream>

using namespace std;

/****************
function - printWebStart

parameters - the output file stream, the title of the web page
returns - nothing

prints the HTML for the beginning of a web page to the output file
****************/

void printWebStart(ofstream &oFile, string pageTitle)
{
    oFile << "<html>" << endl;
    oFile << "<head>" << endl;
    oFile << "<title>" << pageTitle << "</title>" << endl;
    oFile << "</head>" << endl;
    oFile << "<body>" << endl;
}

/****************
function - printWebEnd

parameters - the output file stream
returns - nothing

prints the HTML for the end of a web page to the output file
****************/

void printWebEnd(ofstream &oFile)
{
    oFile << "</body>" << endl;
    oFile << "</html>" << endl;
}

/****************
function - calcAverage

parameters - the total of the exams (int), the number of exams (int)
returns - the average of the exams (double)

Returns the average of the exam scores when passed in the total and the number of exams
****************/

double calcAverage(int total, int numExams)
{
    double average = static_cast<double> (total) / numExams;

    return average;

}

/****************
function - processData

parameters - the output file stream
returns - nothing

Reads in the data and prints the report in HTML to the output file
****************/
void processData(ofstream &oFile)
{
    ifstream inFile;
    inFile.open("score_info.txt");

    string firstName;
    string lastName;
    int numExams;
    int examScores;
    int total = 0;
    const double PASSING_A = 89.5;
    const double PASSING_C =70.0;

    inFile >> firstName;
    inFile >> lastName;
    inFile >> numExams;

    oFile << "<b>" << "Grade Report for" << "</b>" << "</br>" << endl;
    oFile << "<br>" << endl;
    oFile << firstName << " " << lastName << "</br>" << "</br>" << endl;

    for (int i = 0; i < numExams; i++)
    {
        inFile >> examScores;
        oFile << "Exam " << i + 1 << " - " << examScores << "</br>" << endl;

        total = total + examScores;

    }

    double average = calcAverage(total, numExams);
    oFile << "</br>" << "Average - " << average << "</br>" << endl;

    if (average >= PASSING_A)
    {
        oFile << "Grade - A" << "</br>" << endl;
        oFile << "</br>" << endl;
        oFile << firstName << " " << lastName << " - " << endl;
        oFile << "<b>" << "Passed" << "</b>" << endl;
    }
    else if (average >= PASSING_C)
    {
        oFile << "Grade - C" << "</br>" << endl;
        oFile << "</br>" << endl;
        oFile << firstName << " " << lastName << " - " << endl;
        oFile << "<b>" << "Passed" << "</b>" << endl;
    }
    else
    {
        oFile << "Grade - F" << "</br>" << endl;
        oFile << "</br>" << endl;
        oFile << firstName << " " << lastName << " - " << endl;
        oFile << "<b>" << "Failed" << "</b>" << endl;
    }


}

/**************************************************************************************/

int main()
{
    ofstream outFile;
    outFile.open("prog4_output_cbh65.html");

    printWebStart(outFile, "Grade Report");

    processData(outFile);

    printWebEnd(outFile);

    outFile.close();

    return 0;
}
