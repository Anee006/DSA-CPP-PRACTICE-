// LeetCode 3622

// You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
// The digit sum of n (the sum of its digits). The digit product of n (the product of its digits).
// Return true if n is divisible by this sum; otherwise, return false.

/*
Input: n = 99
Output: true
Explanation:
Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Input: n = 23
Output: false
Explanation:
Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.
*/

#include <iostream>
using namespace std;

bool checkDivisibility(int n) {
    int original = n; // to save the given number

    int sum = 0, prod = 1;

    while( n != 0) {
        int digits = n % 10; // find digit of the given num

        sum += digits; // sum of digits
        prod *= digits; // product of digits

        n /= 10;
    }

    return (original % (sum + prod) == 0) ? true : false;
}

int main() {
    int n = 99;

    checkDivisibility(n) ? cout << "True" : cout << "False";

    return 0;
}

// If n has d digits, the loop runs d times. And the number of digits in n is: d = (log n + 1).
// TC = O(log n)

// SC = O(1)