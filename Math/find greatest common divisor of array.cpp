// Leetcode 1979

// Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
// The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

/*
Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for gcd()
using namespace std;

int findGCD(vector<int>& nums) {
    int smallest = *min_element(nums.begin(), nums.end()); // finds smallest element in the array
    int largest = *max_element(nums.begin(), nums.end()); // finds largest element in the array

    return gcd(smallest, largest);
}

int main() {
    vector<int> nums = {2,5,6,9,10};
    cout << findGCD(nums);

    return 0;
}

// TC = O(n)
// SC = O(1)