/* mathStuff_cbh65.cpp

Roger Priebe and (Cole Hurst)
cs1428 10/15/07 (updated 3/11/08)

Cole Hurst completed at 3/7/2017

Finish comments here
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

//**********  Function Prototypes  ******************

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


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
//Hint: You will need nested loops for your solution.
void findFactors (int number);


//******************  MAIN  *****************************

int main () {

    int testNum;

    //test for the isPrime function
    cout << "Enter a test number - ";
    cin >> testNum;
    cout << endl;

    if (isPrime(testNum))
       cout << testNum << " is prime." << endl;
    else
       cout << testNum << " is not prime." << endl;

    //test for how many primes
    cout << "Enter n to print the prime numbers between 1 and n: ";
    cin >> testNum;
    cout << endl;

    findPrimes(testNum);

    cout << endl;

    //test for Fibonacci number finder
    cout << "Which Fibonacci number? ";
    cin >> testNum;
    cout << endl;

    cout << "The " << testNum;
    cout << " Fibonacci number is : " << findFibo(testNum) << endl;

    cout << endl;

    //test for prime factors
    cout << "Factor what number: ";
    cin >> testNum;
    cout << endl;

    findFactors(testNum);

    return 0;
}




//function isPrime
//input parameter - positive integer greater than 1
//returns true if the number is prime, otherwise false
//
bool isPrime (int number)
{

    bool prime = true;
    int divisor = 2;


    while (prime && divisor <= sqrt(number + 1))
    {
        if (number % divisor == 0)
            prime = false;
        else
            divisor++;
    }

    return prime;

}
//function findPrimes
//input parameter - positive integer
//Uses the is Prime method to print a list of prime numbers between 1 and n.
void findPrimes (int n)
{

    for ( int i = 2; i < n; i ++ )
   {
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
            else if (i == j+1)
                cout << i << " ";

        }
   }
}
//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)
//Note: You must use a loop in your solution. Also, if passed a 0, return 0.
int findFibo (int n)
{
    int total = 0;
    int first = 0;
    int second = 1;

    for ( int i = 0; i < n - 1 ; i++)
    {
        if (n <= 1)
        {
            total = i;
        }
        else
        {
            total = first + second;
            first = second;
            second = total;
        }

    }
    return total;
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
//Hint: You will need nested loops for your solution.
void findFactors (int number) {

   //YOUR CODE GOES HERE

}
