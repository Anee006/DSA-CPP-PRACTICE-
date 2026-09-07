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
    unordered_map<int, int> m; // {latest index, val}

    for(int i = 0; i < nums.size(); i++) {
        if(m.find(nums[i]) != m.end()) { // found a duplicate
            if(abs(i - m[nums[i]]) <= k) return true;
        }

        m[nums[i]] = i; // update latest index of the duplicate
    }
    return false;
}

int main() {
    vector<int> nums = {1, 0, 1, 1};
    int k = 1;

    if(containsNearbyDuplicate(nums, k)) cout << "True";
    else cout << "False";

    return 0;
}

// TC = O(n)
// SC = O(n)