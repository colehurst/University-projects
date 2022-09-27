/****************************************************
File Name:prog08_e_b181.cpp

Lab Section Number: L14
Lab Section Instructor: Jessica Cruz

Author: Erika Bieber- Mitchell
Date: 4/21/2017
Problem Number: 8
CS 1428 Spring 2017
Lecture Instructor: Priebe



A short description of what the program does.
*****************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;

struct City
{
    string city_Names;
    double x_coordinate;
    double y_coordinate;
};

bool getData (string inFile, City cities[], int &numCities);
void printRoute(City cities[], int numCities);
double getDistance(City city1, City city2);
double totalDistance( City cities[], int numCities);
void improveRoute(City cities[], int numCities);
double improveRate (double totaldist1, double totaldist2);

int main ()
{
    int MAX_CITIES = 100;
    City cities[MAX_CITIES];
    int numCities= 0;
    City city1;
    City city2;
    double totaldist2;
    double totaldist1;
    double difference;

    getData("route_data.txt", cities, numCities);
    getDistance(city1, city2);
    totaldist1= totalDistance(cities, numCities);
    cout << "The total distance is: " << totaldist1 << endl;
    cout << "Improved Route:" << endl;
    improveRoute (cities, numCities);
    totaldist2= totalDistance(cities, numCities);
    printRoute(cities, numCities);
    cout << "The total distance is now: " << totaldist2 << endl;
    difference= improveRate (totaldist1, totaldist2);

    cout << "The rate of improvement is: " << difference << "%" << endl;

    return 0;
}
bool getData (string inFile, City cities[], int &numCities)
{
        ifstream fin;
        fin.open(inFile.c_str());
        if (!fin)
        {
          return false;
        }
        else
        {
            //cout << "good open" << endl;
            string city;

            while(fin >> city)
            {
                cities[numCities].city_Names= city;
                cout << endl << cities[numCities].city_Names;
                fin >> cities[numCities].x_coordinate;
                cout << " " << cities[numCities].x_coordinate << " ";
                fin >> cities[numCities].y_coordinate;
                cout << cities[numCities].y_coordinate << " ";
                numCities++;
            }
            cout << endl;
        }
        fin.close();
        return true;
}
void printRoute(City cities[], int numCities)
{
    //cout << "in printRoute" << endl;
    for (int i= 0; i < numCities; i++)
    {
       // cout << "In for loop: i = " << i << endl;
        cout << cities[i].city_Names << endl;
    }
   // cout << "leaving printRoute" << endl;
}
double getDistance(City city1, City city2)
{
    double distance = 0;
    double temp = 0;
    distance = (city2.x_coord - city1.x_coord)*(city2.x_coord - city1.x_coord);
    temp = (city2.y_coord - city1.y_coord)*(city2.y_coord - city1.y_coord);
    distance = distance + temp;
    return distance;

}
double getDistance(City city1, City city2)
{
    double distance= sqrt(pow((city2.x_coordinate- city1.x_coordinate),2) + pow((city2.y_coordinate- city1.y_coordinate),2));

    return distance;

}
double totalDistance( City cities[], int numCities)
{
    int totaldist=0;
    for (int i= 0; i < numCities -1; i++)
    {
       totaldist+= getDistance(cities[i], cities[i+1]);
    }
   return totaldist;
}
void improveRoute(City cities[], int numCities)
{
    int j;
    for (int i= 0; i < numCities-1; i++)
    {
        int closest = i+1;
        double distance= getDistance(cities[i], cities[closest]);
        for (int j= i+2; j < numCities; j++)
        {
            if (getDistance(cities[i], cities[j]) < distance)
                {
                    closest= j;
                    distance= getDistance(cities[i], cities[closest]);
                  swap (cities [i+1], cities[closest]);
        }
    }
    }
}
    void swap (City &city1, City &city2)
    {
        City temp= city1;
        city1= city2;
        city2= temp;
    }
double improveRate (double totaldist1, double totaldist2)
{
    double difference= 0;
    difference= totaldist1 -totaldist2;
    difference/= totaldist1;
    difference *= 100;
    return difference;

}
