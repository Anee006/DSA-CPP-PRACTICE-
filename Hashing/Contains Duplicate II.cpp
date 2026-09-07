// LeetCode 219

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that 
// nums[i] == nums[j] and abs(i - j) <= k.

/*
Input: nums = [1,0,1,1], k = 1
Output: true
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
}

int main() {
    vector<int> nums = {1, 0, 1, 1};
    int k = 1;

    if(containsNearbyDuplicate(nums, k)) cout << "True";
    else cout << "False";

    return 0;
}