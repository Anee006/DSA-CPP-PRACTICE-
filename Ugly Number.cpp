// LeetCode 263

// An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.
// Given an integer n, return true if n is an ugly number.

/*
Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7
*/

#include <iostream>
using namespace std;

bool isUgly(int n) {
    if(n == 1) return true; // 1 has no prime factors

    if(n <= 0) return false; // reject non-positive nums (ugly no. must be +ve)

    while(n % 2 == 0) n /= 2; // remove all factors of 2

    while(n % 3 == 0) n /= 3; // remove all factors of 3

    while(n % 5 == 0) n /= 5; // remove all factors of 5

    return n == 1; // if only 1 is remaining, means no. contained only 2,3,5 as prime factors
}

int main() {
    int n = 6;

    isUgly(n) ? cout << "True" : cout << "False";

    return 0;
}