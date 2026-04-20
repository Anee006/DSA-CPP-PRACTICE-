// LeetCode 518

// You are given an integer array 'coins' representing coins of different denominations and an integer amount representing a total amount of money.
// Return the "number of combinations" that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.

/*
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5 = 5
5 = 2+2+1
5 = 2+1+1+1
5 = 1+1+1+1+1
*/

// LOGIC:
// dp[i] = number of ways to make amount i
// dp[0] = 1 -> base case

#include <iostream>
#include <vector>
using namespace std;

int change(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0); // DP array

    dp[0] = 1; // base case: there is only 1 way to make amount 0 --> choose nothing

    // fill DP table
    for(int c : coins) { // iterate over coins first
        for(int i = c; i <= amount; i++) {
            dp[i] += dp[i-c]; // add the no. of ways
        }
    }
    return dp[amount]; // required ans
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Number of combinations: " << change(coins, amount);
    return 0;
}

// TC = O(n * amount), SC = O(amount)