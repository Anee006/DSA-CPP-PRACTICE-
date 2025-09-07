//3 SUM problem
//Using 2 pointer approach- The most optimal approach
//TC= O(n^2) and SC= O(1)

//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
// and nums[i] + nums[j] + nums[k] == 0.

//solution set must not contain duplicate triplets.
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]

//In the less optimised approach, we use this logic:
//We use an unordered_set to store only unique values. But we can use unordered_set when we have to store data types like int,char etc.
//If we have to store data types like vector in an unordered_set, it becomes difficult. So use a set to store vectors
//In sets, to store only unique pairs or triplets, first sort the triplets and then store it in set.
//This will ensure that only unique triplet gets stored and all its future permutations won't be stored.


//In the 2 pointer approach
//First sort the nums array. So that it becomes easier to find triplets.
//after sorting given array we'll have: [-4,-1,-1,0,1,2].
//Let the first val in triplet i.e, i = -4. Since, we've got i, now we need to find j and k in the remaining sorted array.
//In the remaining array: [-1,-1,0,1,2], we'll take j=-1 and k=2. i.e, we take the extreme ends in the remaining array as our j and k.
//Now if we calculate nums[i]+nums[j]+nums[k], we'll have sum= -4+(-1)+2 = -3, which is smaller than the req. sum i.e 0.
//So to increase overall value of sum, we need to increase our j by one step. So now our j=-1 and the sum still remains -3.
//Again, increasing j by one step, we get j=0. So sum= -4+0+2= -2. Still sum is smaller than 0, so again increase j.
//Now j=1 and sum= -4+1+2=-1. A soon as j==k, we see that for the chosen i=-4, no unique triplet exists whose sum=0.
//So we'll update our i and continue the same logic for j and k values, till we get a unique triplet with sum=0.

//So if our sum<0 --> do j++
//And if sum>0 --> do k--


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> threeSum(vector <int>& nums)
{
    int n= nums.size();
    vector <vector<int>> ans; //to store the ans

    sort(nums.begin(), nums.end()); //to sort the vector

    for(int i=0; i<n; i++)
    {
        if(i>0 && nums[i]==nums[i-1]) //means we got the same value as our i again so, we'll keep on updating till we find a unique i
            continue; 

        int j= i+1; //starting from i+1, as we i!=j!=k
        int k= n-1; //our last value in the sorted vector becomes k

        while(j<k) //cannot write j<=k, as we i!=j!=k
        {

            int sum= nums[i]+nums[j]+nums[k];

            if(sum<0)
            {
                j++;
            }
            else if(sum>0)
            {
                k--;
            }
            else //means sum==0, i.e, we have found the triplet
            {
                ans.push_back({nums[i], nums[j], nums[k]});

                j++;
                k--;

                while(j<k && nums[j]==nums[j-1]) //means we got the same val as j again, so keep on updating j till we get a unique val
                    j++;
            }
        }
    }
    return ans;

}

int main()
{
    vector <int> nums= {-1,0,1,2,-1,-4};

    vector <vector<int>> ans= threeSum(nums);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}