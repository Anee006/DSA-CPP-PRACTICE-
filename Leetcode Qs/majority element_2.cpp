// Leetcode 169
// using OPTIMISED APPROACH

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

//Given array is: {1,2,2,1,1}

#include <iostream>
#include <vector>
#include <algorithm>  // to use sort()
using namespace std;

int majorityElement(vector<int> nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); 

    int freq = 1;
    int ans = nums[0]; // assume the first element as the majority element
    for(int i=1; i<n; i++) { // start loop from 1st index as have already assumed the freq of first element as 1

        if(nums[i]==nums[i-1]) freq++; // means is the i'th el is equal to its prev element, means it is the same el
            
        else {
            freq = 1; // bcoz we have encountered a new num
            ans = nums[i]; // the new el now is the majority el bcoz its prev el was not the majority el 
        }

        if(freq > n/2) return ans;
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,2,1,1};
    cout << "Majority element is: " << majorityElement(nums) << endl;

    return 0;
}

// TC = O(n log n)
// SC = O(log n)