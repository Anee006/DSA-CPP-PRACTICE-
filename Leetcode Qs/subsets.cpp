//SUBSETS
//using recursion

//Given an integer array nums of unique elements, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.

//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

#include <iostream>
#include <vector>
using namespace std;

//helper fn to calculate all subsets:
void getAllSubsets(vector <int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets)
{
    //base case:
    if( i == nums.size())
    {
        allSubsets.push_back({ans}); //the ans will be pushed back as a vector due to {}
        return;
    }

    //to include element:
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allSubsets);

    ans.pop_back(); //backtracking

    //to exclude element:
    getAllSubsets(nums, ans, i+1, allSubsets);

}


//Given in Q:
vector <vector<int>> subsets(vector <int>& nums)
{
    vector <int> ans;
    vector <vector<int>> allSubsets;

    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main()
{
    vector <int> nums = {1,2,3};
    vector <vector<int>> ans = subsets(nums);

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

//TC = O(n * 2^n) or can also write as: O(2^n)
//SC= O(n)