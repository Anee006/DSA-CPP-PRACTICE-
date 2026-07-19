// Leetcode 47

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Input: nums = [1,1,2]
// Output: [[1,1,2], [1,2,1], [2,1,1]]

// LOGIC:
// At every recursion level (idx), remember which values have already been placed at position idx.
// If already used a value, skip i.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void solve(vector<int>& nums, int idx, vector<vector<int>>& ans) {

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;

    solve(nums, 0, ans);

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 2};

    vector<vector<int>> ans = permuteUnique(nums);
    
    for(int i = 0; i< ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC = 
// SC = 