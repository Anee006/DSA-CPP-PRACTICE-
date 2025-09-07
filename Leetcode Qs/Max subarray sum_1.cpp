//To print the sum of sub array which is max
//Using BRUTE FORCE APPROACH 

//Given array: {3,-4,5,4-1,7,-8}
//Max possible subarray: 5,4,-1,7.  //Max possible sub array sum is: 15

#include <iostream>
using namespace std;

int main()
{
    int arr[]= {3,-4,5,4-1,7,-8};
    int n= sizeof(arr)/ sizeof(int);

    int maxSum=INT_MIN; //to track the max sub array sum

    for(int start=0; start<n; start++)
    {
        int currentSum=0;
        for(int end=start; end<n; end++)
        {
            currentSum += arr[end];  //Optimization of brute force approach
            maxSum= max(currentSum, maxSum); //to calc max sub array sum
        }
    }

    cout<<"Max sub array sum: "<<maxSum<<endl;

    return 0;
}