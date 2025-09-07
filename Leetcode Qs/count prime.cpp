//COUNT PRIMES problem
///Using Sieve of Eratosthenes approach

//Given an integer n, return the number of prime numbers that are strictly less than n.
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

#include <iostream>
#include <vector>
using namespace std;


int countPrime(int n)
{
    //create a vector to store whether a no. from 0 to n is a prime no. or not

    vector <bool> isPrime(n+1, true); //size of vector is (n+1) as we need to store for n elements and initialised each value with "true"
    //We have initially assumed that each no. is a prime number

    int count=0; //for storing ans

    for(int i=2; i<n; i++) //starting from 2 as, in prime numbers we don't consider 0 and 1. //i<n as it is given we need to check for strictly < n
    {
        if(isPrime[i]) //means i is considered as prime no.
        {
            count++;

            for(int j=i*2; j<n; j=j+i) //loop to remove the multiples of 2
            {
                isPrime[j]=false; //multiples of i is declared as non prime
            }
        }
            
    }
    return count;

}

int main()
{
    int n=10;
    cout<< countPrime(n) <<endl;
    return 0;
}