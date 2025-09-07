//PRODUCT OF AN ARRAY EXCEPT SELF
//using Brute Force Approach: in this case TC will be O(n^2).

//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//For the given array, nums = [1,2,3,4]
//Output should be: [24,12,8,6]

#include <iostream>
#include <vector>
using namespace std;

vector <int> productExceptSelf(vector <int> &nums)
{
    int n=nums.size();
    vector <int> ans(n, 1); //created a vector ans of size n i.e, same size as nums vector, and initialised it with value 1(as we need to find prod).

    for(int i=0; i<n; i++) //to access the elements
    {
        for(int j=0; j<n; j++) //to find the product
        {
            if(i!=j) //as we need to multiply all elements except the i'th element
            {
                ans[i] *=nums[j]; //mutiplying all elements except i, and storing it at i'th place in the ans vector
            } 
        }
    }
    return ans;
}

int main()
{
    vector <int> nums= {1,2,3,4};
    vector <int> answer= productExceptSelf(nums); //the req vector

    cout<<"Product of array except self: "<<endl;
    for(auto val: answer)
    {
        cout<<val<<"\t";
    }
    cout<<endl;
    return 0;
}