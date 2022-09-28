/*
File Name: prog08__cbh65.cpp

Lab Section Number: 14
Lab Section Instructor: Jessica

Author: Cole Hurst
Date: 4.27.2017
Problem Number: 8
CS 1428 Spring 2017
Lecture Instructor: Priebe

Lecture Session: TTH 12:30-2:00

*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

struct City
{
    string name;
    double x_coord;
    double y_coord;
};

bool getData(string inputFile, City cities[], int &numCities)
{
    string name;
    while (inFile >> name)
    {
        cities[numCities].name = name;
        inFile >> cities[numCities].x_coord;
        inFile >> cities[numCities].y_coord;
    }
}
int main ()
{
    string inputFile = "route_data.txt";

    const int MAX_CITIES = 100;
    City cities[MAX_CITIES];
    int numCities = 0;

    ifstream inFile;
    inFile.open(inputFile.c_str());

    getData (inputFile, cities, numCities);
}



