// LeetCode 300

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

/*
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>& nums) {

}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout << "Length of LIS: " << LIS(nums);
    return 0;
}