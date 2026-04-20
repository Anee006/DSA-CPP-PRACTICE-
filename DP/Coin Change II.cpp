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

}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "Bumber of combinations: " << change(coins, amount);
    return 0;
}