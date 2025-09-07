// #notes
//COMBINATION SUM PROBLEM
//using recursion

//Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where 
//the chosen numbers sum to target. You may return the combinations in any order

//The same number may be chosen from candidates an unlimited number of times. 

//Input: candidates = [2,3,5], target = 8
//Output: [[2,2,2,2],[2,3,3],[3,5]]



#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<vector<int>> s; //to store only unique combinations: helps avoid duplicates

//helper fn to get all possible combinations:
void getAllCombinations(vector<int>& arr, int idx, int target, vector<vector<int>>& ans, vector<int>& combination)
{

    //base cases:
    if(idx == arr.size() || target < 0) 
    {
        return;
    }

    if(target == 0) //means found all combinations
    {
        if(s.find(combination) == s.end()) //means the combination does not exist in the set already
        {
            ans.push_back(combination);
            s.insert(combination);
        }
        return;
    }

    combination.push_back(arr[idx]); //inserting el first and then taking choice

    //to take a single choice for an element:
    getAllCombinations(arr, idx+1, target - arr[idx], ans, combination); //for a single choice we'll update the idx ansd subtract the el from the target

    //to take multiple choice for an element:
    getAllCombinations(arr, idx, target - arr[idx], ans, combination); //for multiple choice we'll not update the idx as we want to inc same el again and again

    combination.pop_back(); //bactracking step: to remove the element we last inserted so that it can be excluded from the combination

    //to take exclude element: 
    getAllCombinations(arr, idx+1, target, ans, combination); //for exclusion, target remains same
}

vector <vector <int>> combinationSum(vector <int>& arr, int target)
{
    vector<vector<int>> ans; //to return all combinations as a vector
    vector<int> combination;

    getAllCombinations(arr, 0, target, ans, combination);

    return ans;

}

int main()
{
    vector<int> candidates = {2,3,5};

    vector<vector<int>> ans = combinationSum(candidates, 8);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j] <<" ";
        }
        cout<<endl;

    }

    return 0;
}

//TC = O(N∗2^N)
//SC = O(N∗2^N)