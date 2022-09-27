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
    ifstream inFile;
    inFile.open(inputFile.c_str());

    while (inFile >> name)
    {
        cities[numCities].name = name;
        inFile >> cities[numCities].x_coord;
        inFile >> cities[numCities].y_coord;

        numCities ++;
    }
    if (!!inFile)
    {

        cout << "File error" << endl;
        return false;
    }

    else
    {
        cout << "Good Open" << endl;
        return true;
    }
}

void printRoute(City cities[], int numCities)
{
    for (int i = 0; i < numCities; i++)
   {
      cout << cities[i].name << endl;

   }
}

double improveRate (double totaldist1, double totaldist2)
{
    double difference= 0;
    difference= totaldist1 -totaldist2;
    difference/= totaldist1;
    difference *= 100;
    return difference;

}

double getDistance(City city1, City city2)
{
    double distance= sqrt(pow((city2.x_coord- city1.x_coord),2) + pow((city2.y_coord- city1.y_coord),2));

    return distance;

}

double totalDistance(City cities[], int numCities)
{
    double distance = 0;
    double total = 0;
    for(int i = 0; i < numCities-1; i++)
    {
        int j = i +1;
        distance = getDistance (cities[i], cities[j]);
        total = total + distance;
    }
    return total;
}


int main ()
{
    string inputFile = "route_data.txt";

    const int MAX_CITIES = 100;
    City cities[MAX_CITIES];
    int numCities = 0;
    double total = 0;
    double distance = 0;
    double distance1 = 0;
    double distance2 = 0;
    double improvement = 0;

    //gotta get that data!
    getData (inputFile, cities, numCities);

    //printing out the route
    printRoute (cities, numCities);

    //Finding total distance for initial route
    total = totalDistance (cities, numCities);

    cout << "The total distance of the initial route is: " << total << endl;
    distance1 = total;


    //Improving the route!
    for (int i = 0; i < numCities - 1; i++)
    {
        int closest = i + 1;
        double distance = getDistance(cities[i], cities[closest]);
        for(int j = i + 2; j < numCities; j++)
        {
            if(getDistance (cities[i], cities[j]) < distance)
            {
                closest = j;
                distance = getDistance(cities[i], cities[closest]);
            }
            swap(cities[i + 1], cities [closest]);

        }

    }

    //printing out the new route
    cout << "New route: " << endl;
    printRoute (cities, numCities);

    //printing out the new total distance
    total = 0;
    total = totalDistance (cities, numCities);
    distance2 = total;
    cout << "New total distance: " << total << endl;

    improvement = improveRate (distance1, distance2);

    cout << "The rate of improvement is: " << improvement << "%" << endl;



}



