// LeetCode 228

// You are given a sorted unique integer array nums. A range [a,b] is the set of all integers from a to b (inclusive).
// Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly 
// one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
// Each range [a,b] in the list should be output as: "a->b" if a != b, "a" if a == b

/*
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are: [0,0] --> "0" , [2,4] --> "2->4" , [6,6] --> "6", [8,9] --> "8->9"
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();

    vector<string> result;

    if(n == 0) return result;

    int start = nums[0];

    for(int i = 1; i <= n; i++) {
        // check whether current range should end. Range ends if we reach the end OR current no. is not consecutive
        if(i == n || nums[i] != nums[i-1] + 1) {
            // if it is a single number
            if(start == nums[i-1]) result.push_back(to_string(start));

            // multiple numbers are there in range
            else result.push_back(to_string(start) + "->" + to_string(nums[i-1]));

            if(i < n) start = nums[i]; // start a new range
        } 
    }
    return result;
}

int main() {
    vector<int> nums = {0,2,3,4,6,8,9};

    vector<string> result = summaryRanges(nums);

    for(string res: result) cout << res << endl;

    return 0;
}

