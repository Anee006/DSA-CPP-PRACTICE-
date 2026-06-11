// BINARY SEARCH ALGORITHM 
// Using recursive method

// Given, arr[]= {-1 ,0, 3, 5, 9, 12}, target = 3 (given array is already sorted in asc order)
// If target is present in array return idx else return -1.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target, int st, int end) {
    if(st <= end) { // base case
        int mid = st + (end-st)/2;

        if(target > arr[mid]) //means we need to search the right half
            return binarySearch(arr,target, mid+1, end); 

        else if(target < arr[mid]) // means we need to search the left half
            return binarySearch(arr, target, st, mid-1); 
    
        else return mid;
    }
    return -1;      
}

int main() {
    vector<int> arr = {-1,0,3,5,9,12};
    int n = arr.size();
    cout << binarySearch(arr, 3, 0, n-1) << endl;

    return 0;
}

// TC = O(log n) , SC = O(log n)`