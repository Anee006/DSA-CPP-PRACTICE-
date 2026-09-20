// LeetCode 264

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5. Given an integer n, return the nth ugly number.

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nthUglyNumber(int n) {
    vector<long long> dp(n); // dp[i] stores i'th ugly number

    dp[0] = 1; // 1st ugly number is 1

    // create 3 pointers
    int p2 = 0, p3 = 0, p5 = 0; // tells which ugly number to multiply by 2, 3, 5

    for(int i = 1; i < n; i++) {
        // possible next ugly numbers:
        long long next2 = dp[p2] * 2;
        long long next3 = dp[p3] * 3;
        long long next5 = dp[p5] * 5;

        // choose the smallest of the three (gives the smallest next ugly number)
        dp[i] = min({next2, next3, next5});

        // move pointers that produced the min
        if(dp[i] == next2) p2++;
        if(dp[i] == next3) p3++;
        if(dp[i] == next5) p5++;
    }

    return dp[n-1]; // stores the req n'th ugly number
}

int main() {
    int n = 10;

    cout << nthUglyNumber(n);
    
    return 0;
}

// TC = O(n)
// SC = O(n)