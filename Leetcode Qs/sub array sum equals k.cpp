//SUBARRAY SUM EQUALS K problem
//Using Brute force approach whose TC is O(n^2) an sC= O(1)

//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

//Given arr= {9,4,20,3,10,5}, k=33
//Sub arrays whose sum is 33: {9,4,20} and {20,3,10}
//So total number of subarrays whose sum is 33 is 2, which is the ans.

#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector <int>& nums, int k) //where k is the target
{
    int n= nums.size();
    int count =0; //to count no. of subarrays whose sum is equal to k

    //i and j are used for the boundary of the subarray. When i is fixed, we keep on moving j and calc the sum
    for(int i=0; i<n; i++)
    {
        int sum=0; //to calculate sum of subarray

        for(int j=i; j<n; j++) //initially j and i are at the same position, then j keeps on updating
        {
            sum += nums[j]; //we are adding the j'th value to the previously calculated sum
            if(sum == k) count++; //means we have found our req subarry
        }
    }
    return count;
}

int main()
{
    vector <int> nums= {9,4,20,3,10,5};
    cout<< subarraySum(nums,33);

    return 0;
}