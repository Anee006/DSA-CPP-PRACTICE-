// LeetCode 268

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

// LOGIC:
// use the formula --> sum of 1st n numbers = n(n+1)/2
// then subtract the actual sum of the array.

#include <iostream>
#include <vector>
using namespace std;


int missingNumber(vector<int>& nums) {
    int n = nums.size();

    int expected = n * (n + 1)/2;
    int actual = 0;

    for(int num : nums) {
        actual += num; // to find sum of the array.
    }

    return expected - actual;
}

int main() {
    vector<int> arr = {3,0,1};

    cout << "Missing number is: " << missingNumber(arr);

    return 0;
}