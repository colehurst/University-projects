/****************************************************
File Name: assign1_cbh65.cpp

Author: Cole Hurst
Date: 2.03.2018
Assignment Number: 1
CS 2308.262 Spring 2018
Lecture Instructor: Yijuan Lu


A program that takes the data about employees in a company
using arrays to display the employees name, age, and salary.
Also compares the employees to determine who has the lowest
and highest salary then displays the average age of all.
*****************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

struct Employee
    {
        string name;
        int age;
        int salary;
    };

int AverageAge (Employee employ[], double TOTAL_EMPLOYEES)
    {
        float total = 0;
        float average = 0;
        for (int i = 0; i < TOTAL_EMPLOYEES; i++)
        {
            total = employ[i].age + total;
        }
        average = total / TOTAL_EMPLOYEES;
        return average;
    }

void Low_and_high (Employee employ[], int TOTAL_EMPLOYEES, Employee temp)
    {
        for ( int i = 0; i < TOTAL_EMPLOYEES; i++)
        {
            for (int j = 0; j < TOTAL_EMPLOYEES; j++)
            {
                if (employ[i].salary > employ[j].salary)
                {
                    temp.name = employ[i].name;
                    temp.age = employ[i].age;
                    temp.salary = employ[i].salary;
                    employ[i].name = employ[j].name;
                    employ[i].age = employ[j].age;
                    employ[i].salary = employ[j].salary;
                    employ[j].name = temp.name;
                    employ[j].age = temp.age;
                    employ[j].salary = temp.salary;
                }
            }
        }
    }

int main()
{
    const int TOTAL_EMPLOYEES = 9;
    Employee temp = {"temp",0,0};
    Employee employ [TOTAL_EMPLOYEES];
    employ[0] = {"Ben", 25,29};
    employ[1] = {"Fred", 58, 31};
    employ[2] = {"Mark", 40, 33};
    employ[3] = {"Tom", 65, 29};
    employ[4] = {"Kevin", 48, 31};
    employ[5] = {"William", 37, 23};
    employ[6] = {"Lucy", 62, 29};
    employ[7] = {"Katherine", 48, 44};
    employ[8] = {"Tiger", 27, 19};

    for (int i = 0; i < TOTAL_EMPLOYEES; i++)
    {
        cout << employ[i].name << " ";
        cout << employ[i].age << " ";
        cout << employ[i].salary << endl;
    }

    cout << endl << "Average Age of all employees: ";
    cout << AverageAge(employ, TOTAL_EMPLOYEES) << endl << endl;

    Low_and_high(employ, TOTAL_EMPLOYEES, temp);

    cout << "employee with the highest salary is " << employ[0].name;
    cout << " and makes " << employ[0].salary << endl;
    cout <<"employee with the lowest salary is " << employ[8].name;
    cout << " and makes " <<employ[8].salary << endl;
}
