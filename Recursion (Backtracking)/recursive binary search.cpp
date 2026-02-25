//RECURSIVE BINARY SEARCH

//BS algo works on a sorted array. Used to find a target in a sorted array.

//Given array = {-1,0,3,5,9,12} , target=9

//STEPS:
//find mid using formula.
//if mid ==target, then return mid, which is the req ans
//if mid<target, search in right half, i.e, now start becomes mid+1
//if mid>target, search in left half, i.e, now end becomes mid-1
//The above conditions will be checked for st <= end.

#include <iostream>
#include <vector>
using namespace std;

//helper fn
int recBinarySearch(vector<int>& arr, int target, int st, int end)
{
    if(st <= end)
    {
        int mid = st + (end-st)/2;

        if(arr[mid] == target) return mid;

        else if(arr[mid] <= target) //search in right half
        {
            return recBinarySearch(arr, target, mid+1, end);
        }

        else //search in left half
        {
            return recBinarySearch(arr, target, st, mid-1);
        }
    }
    return -1; //returns only if array is unsorted
}

//this is given in Q
int search(vector<int>& arr, int target)
{
    return recBinarySearch(arr, target, 0, arr.size()-1); //start=0 and end= n-1
}

int main()
{
    vector<int> arr = {-1,0,3,5,9,12};
    cout << search(arr,9) << endl; //returns the idx at which the target is, if it exists in the array
    return 0;
}

//TC = no. of calls * work in each call
//TC = log(n) * O(1)
//TC = O(log n)   ,[after ignoring base 2]

//SC = depth of recursive tree = O(log n)