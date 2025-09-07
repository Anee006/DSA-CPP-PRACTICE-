//PRODUCT OF AN ARRAY EXCEPT SELF
//using Optimal Approach (but without optimised space complexity)

//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//For the given array, nums = [1,2,3,4]
//Output should be: [24,12,8,6]
//But, we have to write an algorithm that runs in O(n) time complexity, without using the division operation. 
//We haven't optimised space complexity in this approach.

//In this approach, we will calculate the prod of all elements to the left of i'th index (prefix)
//and the product of all elements to the right of i'th index called suffix, and then multiply them together to get the final product.

#include <iostream>
#include <vector>
using namespace std;

vector <int> prodExceptSelf(vector <int> &nums)
{
    int n= nums.size();
    vector <int> ans(n,1);
    vector <int> prefix(n,1); //to store the prod of all prefix for the i'th index
    vector <int> suffix(n,1); //to store the prod of all suffix for the i'th index

    //for calculating prefix
    for(int i=1; i<n; i++) //the 0th index doesn't have any prefix, so starting loop from 1st idx
    {
        prefix[i]= prefix[i-1] * nums[i-1]; //the prefix of i'th index is the prefix of elements before it multiplied by the num before it
    }

    //for calculating suffix
    for(int i= n-2; i>=0; i--) //as we know the suffix of last index (n-1) is 1 (since we had initialised it with 1)
    {
        suffix[i]= suffix[i+1] *nums[i+1]; //the suffix of i'th index is the suffix of elements after it multiplied by the num after it
    }

    //the ans
    for(int i=0; i<n; i++)
    {
        ans[i]= prefix[i] * suffix[i];
    }
    return ans;
}
//Since we have used 3 loops in the above case, and since each loop has TC O(n), so the total TC is O(3n); ignoring the const TC=O(n).

int main()
{
    vector <int> nums= {1,2,3,4};
    vector <int> answer= prodExceptSelf(nums);

    cout<<"Product except self is: "<<endl;
    for(auto val: answer)
    {
        cout<<val<<"\t";
    }
    cout<<endl;
    return 0;
}