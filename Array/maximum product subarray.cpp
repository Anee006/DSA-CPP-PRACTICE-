// #newnotes
// LeetCode 152

// Given an integer array nums, find a subarray that has the largest product, and return the product.

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6. [2,4] is not a subarray.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int currMax = nums[0];
    int currMin = nums[0]; // keep track of Min, bcoz multiplying 2 -ve nums can become a large +ve num
    int result = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        int num = nums[i];

        // if num is -ve, swap currMax and currMin
        if(num < 0) swap(currMax, currMin);

        currMax = max(num, currMax * num);
        currMin = min(num, currMin * num);

        result = max(result, currMax);
    }
    return result;
}

int main() {
    vector<int> nums = {2,3,-2,4};
    
    cout << maxProduct(nums);

    return 0;
}

// TC = O(n)
// SC = O(1)