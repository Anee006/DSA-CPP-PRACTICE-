// Leetcode 169
// using MOORE'S VOTING ALGORITHM

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

//Given array is: {1,2,2,1,1}

// In this algo, we run a loop and count freq.
// We set the first el freq as 0. if the same el occurs again then do freq++ else, if a diff el appears, do freq--.
// Logic is that the freq of majority el is so large that even after doing freq--, it will still have the highest freq.

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int> nums) {
    int n = nums.size();
    int freq = 0;
    int ans = 0; // assuming the ans as 0

    for(int i=0; i<n; i++) {
        if(freq == 0) ans = nums[i]; // means have encountered a new el. Make the new el as our majority el

        if(ans == nums[i]) freq++; // means have encountered the same el

        else freq--;
    }
    return ans; // this will be the majority el automatically, no need to check if it is > n/2.
}

int main() {
    vector<int> nums = {1,2,2,1,1};
    cout << "Majority element is: " << majorityElement(nums) << endl;

    return 0;
}

// TC = O(n)
// SC = O(1)