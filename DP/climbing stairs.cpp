// #newnotes
// Leetcode 70
// uses same logic as used for solving 1-D fibonacci using DP

// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

/*
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

#include <iostream>
#include <vector>
using namespace std;

// using tabulation + memory optimization
int climbStairs(int n) {
    if(n == 1 || n == 2) return n; // base case

    int prev2 = 1; // stores sol. of n = 1 , i.e (n-2)
    int prev1 = 2; // stores sol. of n = 2 , i.e (n-1)

    int result = prev1;

    for(int i = 3; i <= n; i++) {
        result = prev1 + prev2;

        prev2 = prev1;
        prev1 = result;
    }
    return result;
}

int main() {
    int n = 3;

    cout << climbStairs(n);

    return 0;
}

// TC = O(n)
// SC = O(1)