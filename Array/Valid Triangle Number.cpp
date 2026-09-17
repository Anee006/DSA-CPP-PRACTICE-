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
#include <algorithm>
using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int n = nums.size(); // number of elements present in the array
    int count = 0;

    // i --> smallest side of triangle
    // j --> middle side of triangle
    // k --> largest side of triangle

    for(int k = n-1; k >= 2; k--) {
        int i = 0;
        int j = k-1;

        while(i < j) {
            if(nums[i] + nums[j] > nums[k]) { // check triangle condition
                count += j-i; // all values b/w i & j (i.e, from i to j-1) can also form valid triangles
                j--;
            }

            else i++; // need a larger smallest side for the triangle
        }
    }
    return count;
}

int main() {
    vector<int> nums = {2, 2, 3, 4};

    cout << triangleNumber(nums);

    return 0;
}

// TC = O(n^2)
// SC = O(1)