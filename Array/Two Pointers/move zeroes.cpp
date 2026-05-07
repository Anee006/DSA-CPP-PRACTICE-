// LeetCode 283
// using 2 pointers (i and j)

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0; // position to place next non-zero el

    // move all non-zero el forward
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);
    cout << "Array after moving zeroes to end:\n";
    for(int i : nums) cout << i << " ";

    return 0;
}

// TC = O(n), SC = O(1)