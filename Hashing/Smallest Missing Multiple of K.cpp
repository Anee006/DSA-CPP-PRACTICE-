// LeetCode 3718

// Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
// A multiple of k is any positive integer divisible by k.

/*
Input: nums = [1,4,7,10,15], k = 5
Output: 5
Explanation:
The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int missingMultiple(vector<int>& nums, int k) {
}

int main() {
    vector<int> nums = {1, 4, 7, 10, 15};
    int k = 5;

    cout << missingMultiple(nums, k);

    return 0;
}