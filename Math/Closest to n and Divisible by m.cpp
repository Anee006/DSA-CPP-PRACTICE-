// geeksforgeeks

// Given two integers n and m (m != 0). The problem is to find the number closest to n and divisible by m. 
// If there is more than one such number, then output the one having the maximum absolute value.

// Input: n = 13, m = 4
// Output: 12
// Explanation: 12 is the Closest Number to 13 which is divisible by 4.

// LOGIC:
// Find 2 multiples of m surrounding n -> lower and upper . lower -> multiple <= n. upper -> multiple >= n
// Compare the distances of both multiples from n, whichever is smaller return that
// If tie exists -> choose the one which has max absolute val

#include <iostream>
using namespace std;

int closestNumber(int n, int m) {
    int q = n / m; // find quotient

    // find multiples of m
    int lower = q * m;
    int upper = (q + 1) * m;

    // find distances from n
    int d1 = abs(n - lower);
    int d2 = abs(n - upper);

    if(d1 < d2) return lower;

    else if( d2 < d1) return upper;

    else return (abs(lower) > abs(upper) ? lower : upper); // tie-case

}

int main() {
    int n = 13, m = 4;

    cout << closestNumber(n, m);

    return 0;
}

// TC = O(1)
// SC = O(1)