//SUBARRAY SUM EQUALS K problem (notes on sheet)
//Using Hashing whose TC is O(n) and SC= O(n)

//Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

//Given arr= {9,4,20,3,10,5}, k=33
//Sub arrays whose sum is 33: {9,4,20} and {20,3,10}
//So total number of subarrays whose sum is 33 is 2, which is the ans.

//To track the no. of prefix sums of[i-1] we have, we will use an unordered_map, as in practical cases, it's TC is O(1).
//Create, unordered_map <int,int>, where first int is the "prefix sum" and the second int is for it's "frequency" i.e, no. of times it occurs

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector <int>& arr, int k) //where k is the target
{
    int n= arr.size();
    int count = 0; //to count no. of subarrays whose sum is equal to k
    vector <int> prefixSum(n,0); //vector to store all the prefix sums of the vector arr //size of this vector is n and initialised with 0

    prefixSum[0]= arr[0]; //sum of 0th idx is the no. itself
    for(int i=1; i<n; i++) //starting from i=1 as we have already calculated for i=0
    {
        prefixSum[i]= prefixSum[i-1] + arr[i]; //adding the new val to already calc sum so far
    }

    unordered_map <int,int> m; //to store the prefixSum and its freq in the prefixSum vector
    for(int j=0; j<n; j++)
    {
        if(prefixSum[j]==k) //means we have found the req subarray in the beginning itself
            count++;

        int val = prefixSum[j] - k; //val here means prefixSum[i-1]
        if(m.find(val) != m.end()) //means val is present in map already, i.e, we have found ans
        {
            count += m[val]; //m[val] means the freq of the prefixSum in the vector
        }

        if(m.find(prefixSum[j]) == m.end()) //means prefixSum[j] does not exist in map
        {
            m[prefixSum[j]] = 0; //initially stored in map with freq of 0
        }
        m[prefixSum[j]]++;
    }
    return count;
}

int main()
{
    vector <int> nums= {9,4,20,3,10,5};
    cout<< subarraySum(nums,33);

    return 0;
}