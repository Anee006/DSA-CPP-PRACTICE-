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
    unordered_set<int> s(nums.begin(), nums.end()); // put every element in a set

    int multiple = k; // start from k

    while(s.count(multiple)) multiple += k; // keep checking for multiples of k in the set

    return multiple; // as soon as a multiple is found that is not in the set, return it
}

int main() {
    vector<int> nums = {1, 4, 7, 10, 15};
    int k = 5;

    cout << missingMultiple(nums, k);

    return 0;
}

// TC = O(n)
// SC = O(n)