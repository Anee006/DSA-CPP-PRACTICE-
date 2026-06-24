// Leetcode 169
// using BRUTE FORCE

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

//If n = 8, then floor n/2 = 4
//If n = 9, then floor n/2 = 4 (taken 4.5 as 4)

//Given array is: {1,2,2,1,1}

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> nums) {
    int n = nums.size();

    for(auto val: nums) {
        int freq = 0; // to count the freq of each element

        for(auto num:nums) {
            if(num ==val) freq++;  
        }

        if(freq > n/2) return val; // given that there will always be a majority el, so this line will always execute
    }
    return -1; // if not written, then shows error
}

int main() {
    vector<int> nums = {1,2,2,1,1};
    cout << "Majority element is: " << majorityElement(nums) << endl;

    return 0;
}

// TC = O(n^2)
