//To print the sum of sub array which is max (LeetCode 53)
//Using Divide & Conquer Approach --> TC = O(n logn) 

//Given array: {3,-4,5,4-1,7,-8}
//Max possible subarray: 5,4,-1,7.  //Max possible sub array sum is: 15

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find maximum crossing sum
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;

    // Include elements on left of mid
    for(int i= mid; i >= left; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    // Include elements on right of mid
    for(int i= mid+1; i <= right; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

// Main Divide & Conquer function
int maxSubArray(int arr[], int left, int right) {
    // base case:
    if(left == right) return arr[left];

    int mid = left + (right-left)/2;

    int leftMax = maxSubArray(arr, left, mid);
    int rightMax = maxSubArray(arr, mid+1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    return max(max(leftMax, rightMax), crossMax);
}


int main()
{
    int arr[] = {3,-4,5,4-1,7,-8};
    int n = sizeof(arr)/ sizeof(int);

    cout << "Max sub array sum: " << maxSubArray(arr, 0, n-1) <<  endl;

    return 0;
}