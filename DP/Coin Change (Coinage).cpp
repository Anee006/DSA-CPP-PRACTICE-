// LeetCode 322

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest no. of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

/*
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {

}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Min coins: " << coinChange(coins, amount);
    return 0;
}