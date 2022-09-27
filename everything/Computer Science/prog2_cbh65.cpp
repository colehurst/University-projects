/****************************************************
File Name:prog05__cbh65.cpp

Lab Section Number: 14
Lab Section Instructor: Jessica

Author: Cole Hurst
Date: 1.31.2017
Problem Number: 2
CS 1428 Spring 2017
Lecture Instructor: Priebe

Lecture Session: TTH 12:30-2:00


*****************************************************/

#include <iostream>

using namespace std;

int main()
{

    //function isPrime
    //input parameter - positive integer greater than 1
    //returns true if the number is prime, otherwise false
    //
    bool isPrime (int number);



    //function findPrimes
    //input parameter - positive integer
    //Uses the isPrime method to print a list of prime numbers between 1 and n.
    void findPrimes (int n);


    //function findFibo
    //input parameter - positive integer
    //returns the nth fibonacci number where
    //Fib(0) -> 0
    //Fib(1) -> 1
    //Fib(N) -> Fib(N-2) + Fib(N-1)
    //Note: You must use a loop in your solution. Also, if passed a 0, return 0.
    int findFibo (int n);

    int first = 0;
    int second = 1;
    int fibo = 1;
    int n;

    cout << "Enter a positive integer" << endl;
    cin >> n;

    for ( int i = 0; i <= n; i++)
    {
        fibo = first + second;
        first = second;
        second = fibo;
    }
    cout << "Fibo " << n << " = " << fibo;

    return 0;

    //function findFactors
    //input parameter - positive integer
    //prints the prime factors of the given number to standard output (cout)
        //example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
    //Hint: You will need nested loops for your solution.
    void findFactors (int number);

}
