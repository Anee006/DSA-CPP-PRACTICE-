// LeetCode 238
// using Optimal Approach (with oprimised space complexity)

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// For the given array, nums = [1,2,3,4]
// Output should be: [24,12,8,6]

// LOGIC:
// we will calculate the prod of all elements to the left of i'th index (prefix)
// and the product of all elements to the right of i'th index called suffix, and then multiply them together to get the final product.
// but, we won't calculate the prefix and suffix separately here, in order to optimise space complexity.

#include <iostream>
#include <vector>
using namespace std;

vector<int> prodExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n,1);
    
    int suffix = 1; // instead of creating a vector for storing suffix, we are creating a variable

    // for calculating prefix
    for(int i=1; i<n; i++) {
        ans[i] = ans[i-1] * nums[i-1]; // prefix of i'th index //directly storing prefix in the ans itself
    }

    //for calculating suffix
    for(int i= n-2; i>=0; i--) {
        suffix *= nums[i+1]; // suffix = existing value of suffix multiplied by the number at next index i.e, at (i+1)'th idx
        ans[i] *= suffix; // calculates the final ans as ans[i] = prefix[i] * suffix[i]
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> answer = prodExceptSelf(nums);

    cout << "Product except self is: " << endl;
    for(auto val: answer) cout << val << "\t";
    return 0;
}