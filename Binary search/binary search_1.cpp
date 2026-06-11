// #notes
// BINARY SEARCH ALGORITHM
// Using iterative method: TC = O(log n) and space complexity = O(1)

// Given, arr[]= {-1,0,3,4,5,9,12}, target = 12 (given array is already sorted in asc order)
// If target is present in array return that idx else, return -1.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;

    while(start <= end) { // we write <= bcoz when start=end, i.e our answer
        int mid = start + (end-start) / 2; 
        // We are not using : (start + end)/2, as this can lead to incorrect mid calc in case of overflow.

        if(target > arr[mid]) start = mid+1; // search the right half
            
        else if(target < arr[mid]) end = mid-1; // search the left half

        else return mid; 
    }
    return -1; // if target doesn't exist in the array
}

int main() {
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12};
    cout << binarySearch(arr,12) << endl;

    return 0;
}

// we can also use builtin fn to tell if a no. is present in an array or not (return true or false)
/*
vector<int> v = {1,2,3,4,5};
cout << binary_search(v.begin(), v.end(), 4); --> here, if 4 is present it prints 1 else prints 0
*/
