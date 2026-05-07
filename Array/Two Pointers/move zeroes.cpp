// LeetCode 283
// using 2 pointers (i --> traverses array, j --> keeps track of pos where next non-zero el should be placed)

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
        
}

int main() {
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);
    cout << "Array after moving zeroes to end:\n";
    for(int i : nums) cout << i << " ";

    return 0;
}