//4 SUM
//Using two pointer approach
//TC= O(nlogn + n^3)
//SC= O(uniqueGroups)

//Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//0 <= a, b, c, d < n where, a, b, c, and d are distinct.
//nums[a] + nums[b] + nums[c] + nums[d] == target
//You may return the answer in any order.

//Given arr=[-2,-1,-1,1,1,2,2], target=0
//Output= {{-1,-1,1,1}, {1,-1,2,-2}}.

//Steps:
//1. sort the array
//2. let i= nums[i]. This is used to pick a unique i value each time
//3. let j= i+1, as we need only unique values. //we've got our nums[i] and nums[j] so far.
//4. use two pointer approach to find nums[k] and nums[l].
//5. In the remaining part of the array, let k point to the smallest val and let l point to the largest val in the sorted array. 
//i.e, k=j+1 and l=n-1

//So, for the given array, after sorting, i=-2, j=-1, k=-1 and l=2
//Right now, sum= -2-1-1+2 = -2, which is smaller than target. So do k++.
//If sum is greater than the target, then do l--.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> ans; //to return ans
    int n=nums.size();

    sort(nums.begin(), nums.end()); //to sort the array

    for(int i=0; i<n; i++) //to select i
    {
        if(i>0 && nums[i]==nums[i-1])  //means if we have two same i values, then we'll skip i till we get a unique val
            continue;

        for(int j= i+1; j<n;) //to select j //removed j++ from here and wrote it at end of this loop
        {
            int k= j+1; //using two pointer approach for selecting k and l
            int l= n-1;

            while(k<l)
            {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                //using long long, as sum can be a large value

                if(sum<target)
                {
                    k++;
                }
                else if(sum>target)
                {
                    l--;
                }
                else //means we have found our ans, so add it in the ans vector
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    while(k<l && nums[k]==nums[k-1]) //to avoid duplicates and get unique val
                        k++;
                }
            }
            j++; //j++ of the inner loop

            while(j<n && nums[j]==nums[j-1]) //if j is equal to its prev val then, do j++ till we get unique val
                j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums= {-2,-1,-1,1,1,2,2};
    vector <vector<int>> ans= fourSum(nums,0); //target=0

    for(int i=0; i<ans.size();i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}