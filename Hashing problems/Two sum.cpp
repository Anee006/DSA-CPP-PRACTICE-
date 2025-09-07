//2 SUM problem //Using Most optimised approach with TC: O(n) 
//(notes on sheet)
// -Is a hashing problem (uses sets and maps) //Maps and sets, Time complexity ko constant kardete hai

//We could have also used 2-pointer approach for this problem whose TC would've been O(nlogn). But that approach is not the best.

//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order.

//Input: nums = [5,2,11,7,15], target = 9
//Output: [1,3]
//Explanation: Because nums[1] + nums[3] == 9, we return [1, 3].

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector <int> twoSum(vector <int> &arr, int tar)
{
    unordered_map <int,int> m; //to store the second val and its index
    vector <int> ans; //to store both the indices which will be the ans

    for(int i=0; i<arr.size(); i++)
    {
        int first= arr[i];
        int second= tar - first;

        //to find the second val inside map:
        if(m.find(second) != m.end()) //means second val exists in map
        {
            ans.push_back(i); //idx of first 
            ans.push_back(m[second]); //idx of second
            break;
        }

        m[first] = i; //to store the second val and its idx, if the value does not already exist in the map

    }
   return ans;
}

int main()
{
    vector <int> arr= {5,2,11,7,15};

    vector <int> ans=twoSum(arr,9); //target=9

    for(int val: ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}