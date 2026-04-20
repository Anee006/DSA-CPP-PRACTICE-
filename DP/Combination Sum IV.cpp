// LeetCode 377
// similar to coin change II problem but in this: order matters (permutations)

// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

/*
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/

#include <iostream>
#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);
    dp[0] = 1; // base case

    for(int i=1; i <= target; i++) {
        for(int num : nums) {
            if(i-num >= 0) {
                dp[i] += dp[i-num];
            }
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {1,2,3};
    int target = 4;
    
    cout << "Number of possible combinations: " << combinationSum4(nums, target);
    return 0;
}

// TC = O(n * target), SC = O(target)
