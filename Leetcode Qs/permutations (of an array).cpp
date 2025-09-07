//TO PRINT PERMUTATIONS OF AN ARRAY
//Using recursion

//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

//for an array of size "n", no. of permutations = n!
//Here, n=3 so, n!= 3! = 6

//we need to take a variable, idx, to track which place we are trying to currently fill with the choice.
//for eg, initially idx=0, means we are trying to fill the first space with either 1,2 or 3.
//then we do idx+1 and go to the second place and fill it with the remaining two choices, and so on for all the choices.

//instead of creating a separate vector for storing the permutations, we'll make the changes in the same vector nums, and swap values inside
//it to get the desired arrangement.

#include <iostream>
#include <vector>
using namespace std;

//helper fn
void getPermute(vector<int>& nums, int idx, vector<vector<int>>& ans)
{
    //base case:
    if(idx == nums.size())
    {
        ans.push_back({nums}); //pushing back elements of nums vector, in the form of vector in the ans
        return;
    }

    for(int i=idx; i<nums.size(); i++)
    {
        swap(nums[idx], nums[i]); //hamare "idx" place ke liye, "i'th" element ki choice le rahe hai aur usse swap kar re hai
        getPermute(nums, idx+1, ans);

        swap(nums[idx], nums[i]); //backtracking step //replacing the permute with the original array say, {1,2,3}, to make right choices later

    }
}
vector <vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> ans; //to store the permutations
    getPermute(nums, 0, ans);


    return ans;

 //NOTE: backtracking happens after recursive call
}

int main()
{
    vector <int> nums= {1,2,3};
    vector<vector<int>> ans= permute(nums);

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

//TC = no. of calls * work in each call
//TC = n! * n
//TC+ O(n*n!)

//SC = n! + n     ,[as n! space is req to make n! calls, and in worst case the call stack can go "n" levels deep]
//SC = O(n!)