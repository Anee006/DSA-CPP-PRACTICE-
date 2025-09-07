//MAJORITY ELEMENT PROBLEM using OPTIMISED APPROACH
//majority element is the one which appears more than n/2 times in the given array. n is the no. of elements
//If n=8, then floor n/2= 4
//If n=9, then floor n/2= 4 (taken 4.5 as 4)

//Given array is: {1,2,2,1,1}

#include <iostream>
#include <vector>
#include <algorithm>  //to use sort()
using namespace std;

int majorityElement(vector <int> nums)
{
    int n=nums.size();
    sort(nums.begin(), nums.end()); //we are sorting the vector first in this case

    int freq=1;
    int ans= nums[0]; //we are assuming the first element as the majority element
    for(int i=1; i<n; i++) //starting the loop from 1st index as we have already assumed the freq of first element as 1
    {
        if(nums[i]==nums[i-1]) //means is the i'th el is equal to its prev element, means it is the same el
            freq++;
        else
        {
            freq=1; //bcoz we have encountered a new num
            ans=nums[i]; //the new el now is the majority el bcoz its prev el was not the majority el 
        }

        if(freq> n/2)
            return ans;
    }

    return ans;
}

int main()
{
    vector <int> nums= {1,2,2,1,1};
    cout<<"Majority element is: "<< majorityElement(nums) <<endl;

    return 0;
}
