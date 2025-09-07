//PAIR SUM using BRUTE FORCE APPROACH
//For the given array ={2,7,11,15}, return the pair with the target sum of 9.

#include <iostream>
#include <vector>
using namespace std;

vector <int> pairSum(vector <int> nums, int target) //fn to get the indices of the req pair
{
    vector <int> ans;
    int n=nums.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(nums[i]+ nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;  //ans is returned in the form of vector
            }
        }
    }

    return ans; //will return empty vector if ans doesn't exist

}

int main()
{
    vector <int> nums={2,7,11,15};
    int target=9;
    int n=nums.size();

    vector <int> ans= pairSum(nums,target);
    cout<<ans[0]<<" , "<<ans[1]<<endl;

    return 0;
}