// #newnotes
// LeetCode 611

// Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take 
// them as side lengths of a triangle.

/*
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
*/

#include <iostream>
#include <vector>
using namespace std;

int triangleNumber(vector<int>& nums) {

}

int main() {
    vector<int> nums = {2, 2, 3, 4};

    cout << triangleNumber(nums);

    return 0;
}