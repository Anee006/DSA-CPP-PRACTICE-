// #newnotes
// LeetCode 137

// Given an integer array nums where every element appears three times except for one, which appears exactly once. 
// Find the single element and return it. You must implement a solution with a linear runtime complexity and use only constant extra space.

// Input: nums = [2,2,3,2]
// Output: 3

// LOGIC:
// We have 32-bit integers. For every bit position from 0 to 31:
// Count how many numbers have that bit set. Take the count modulo 3. If the remainder is 1, set that bit in the answer.

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int i = 0; i < 32; i++) {
        int count = 0;

        for(int num : nums) { // count how many nums have the current bit set
            if((num >> i) & 1) count++;
        }

        if(count % 3 != 0) { // bits belonging to the req single number will have remainder = 1
            ans |= (1 << i); // set that bit in the ans

        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2,2,3,2};

    cout << singleNumber(nums);

    return 0;
}

// TC = O(n)
// SC = O(1)



