// LeetCode 312
// Uses Matrix Chain Multiplication pattern

// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a no. on it represented by an array nums. You have to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
// If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

/*
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/

// Instead of choosing the first balloon to burst, we use: Which balloon is burst last in a range?
// If k is the last balloon burst in range (i, j):
// dp[i][j] = max(dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j])


#include <iostream>
#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) {

}

int main() {
    vector<int> nums = {3, 1, 5, 8};

    cout << "Max coins: " << maxCoins(nums);
    return 0;
}

// TC = O(n^3),  SC = O(n^2)