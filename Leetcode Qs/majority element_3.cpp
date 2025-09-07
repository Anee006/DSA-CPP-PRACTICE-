//MAJORITY ELEMENT PROBLEM using MOORE'S VOTING ALGORITHM
//majority element is the one which appears more than n/2 times in the given array. n is the no. of elements
//If n=8, then floor n/2= 4
//If n=9, then floor n/2= 4 (taken 4.5 as 4)

//Given array is: {1,2,2,1,1}

//In this algo, we run a loop and count freq
//We set the first el freq as 0. if the same el occurs again then do freq++ else, 
//if a diff el appears, do freq--.
//The logic is that the freq of majority el is so large that even after doing freq--, it will still have the highest freq.

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector <int> nums)
{
    int n=nums.size();
    int freq=0;
    int ans=0; //assuming the ans as 0

    for(int i=0; i<n; i++)
    {
        if(freq==0)
            ans=nums[i]; //means we have encountered a new el. we are making the new el as our majority el

        if(ans==nums[i])
            freq++; //means we have encountered the same el

        else
            freq--;
    }
    return ans; //this will be our majority el automatically, we don't need to check if it is >n/2.
}

int main()
{
    vector <int> nums= {1,2,2,1,1};
    cout<<"Majority element is: "<< majorityElement(nums) <<endl;

    return 0;
}
