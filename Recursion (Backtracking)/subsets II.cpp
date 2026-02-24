//SUBSETS II
//Using backtracking

//Given an integer array nums that "may contain duplicates", return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.

//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

//If we find out all 8 subsets for the given array, we'll get:
//[1,2,2], [1,2], [1,2], [1], [2,2], [2], [2], []

//Now in this we have the remove the duplicate subsets: [1,2] ans [2]

//To remove the duplicates: we need to exclude an element which occurs again in the array, not include it later on.
//Here 2 occurs twice, so once we have made the choice to exclude the first 2 from the subset, we need to make the same choice for the second 2 
//as well, in order to avoid duplicates.

//STEPS: 
//1. Sort array
//2. Calc subsets
//3. To skip duplicates: idx= i+1, while(idx < arr.size() && arr[idx] == arr[idx-1]) do idx++

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//helper fn
void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets)
{
    //base case
    if(i== nums.size())
    {
        allSubsets.push_back({ans});
        return;
    }

    //to include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allSubsets);

    ans.pop_back(); //backtracking

    //to skip duplicate values
    int idx = i+1; //starting from next el to where we currently are
    while(idx < nums.size() && nums[idx] == nums[idx-1])
    {
        idx++;
    }

    //to exclude
    getAllSubsets(nums, ans, idx, allSubsets);

}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{

    //sorting array
    sort(nums.begin(), nums.end());

    vector<vector<int>> allSubsets; //to store ans
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;

}

int main()
{
    vector <int> nums = {1,2,2};
    vector <vector<int>> ans = subsetsWithDup(nums);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//TC = O(nlogn + (2^n*n))
//Here we can ignore nlogn, so actual TC= O(2^n * n)