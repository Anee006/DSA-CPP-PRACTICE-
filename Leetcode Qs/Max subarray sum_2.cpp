//To print the sum of sub array which is max
//Using KADANE'S ALGORITHM (most optimized approach) (greedy / dynamic programming approach)

// TC = O(n)

//Given array: {3,-4,5,4-1,7,-8}
//Max possible subarray: 5,4,-1,7.  //Max possible sub array sum is: 15

//Logic of this algo:
// +ve  +   +ve = +ve
// small -ve    +   +ve = +ve
// +ve  +   large -ve value = -ve
//Acc to the algo, if sum comes as -ve then reset the sum to 0.

#include <iostream>
using namespace std;

int  main()
{
    int currentSum=0; 
    int maxSum= INT_MIN;
    int arr[]= {3,-4,5,4-1,7,-8};
    int n= sizeof(arr)/ sizeof(int);

    for(int i=0; i<n; i++)
    {
        currentSum += arr[i];
        maxSum= max(currentSum, maxSum);

        if(currentSum<0)
            currentSum=0; //reseting currentSum to 0 whenever the sum becomes -ve //we write it in end, so that if the array has only -ve numbers then also max sum is shown instead of 0.
    }
    
    cout<<"Max Sub array sum is: "<<maxSum<<endl;
    
    return 0;
}