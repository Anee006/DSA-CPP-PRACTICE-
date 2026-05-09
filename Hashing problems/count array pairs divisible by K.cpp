// LeetCode 2183

// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:
// 0 <= i < j <= n - 1 and
// nums[i] * nums[j] is divisible by k.

/*
Input: nums = [1,2,3,4,5], k = 2
Output: 7
Explanation: The 7 pairs of indices whose corresponding products are divisible by 2 are
(0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4). Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.   
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countPairs(vector<int>& nums, int k) {
        
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int k = 2;

    cout << countPairs(nums, k);

    return 0;
}