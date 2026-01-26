// Given an integer array of which both first half and second half are sorted. Task is to merge two sorted halves of array into single sorted array.
// (this is the merge step of merge sort algo).

// Fisrt half is: arr[0....mid]
// Second half: arr[mid+1 ..... n-1]

#include <iostream>
#include <vector>
using namespace std;

void mergeSortedHalves(vector<int>& arr) {
    int n = arr.size();
    int mid = (n-1)/2;  // last index of first half

    vector<int> merged;
    
    int i = 0; // pointer for 1st half
    int j = mid+1; // pointer for 2nd half

    while(i <= mid && j <= n) {
        if(arr[i] <= arr[j]) {
            merged.push_back(arr[i++]);
        } else {
            merged.push_back(arr[j++]);
        }
    }

    // Copy remaining elements
    while(i <= mid) merged.push_back(arr[i++]);
    while(j <= n) merged.push_back(arr[j++]);

    // Copy back to original array
    for(int k=0; k<n; k++) {
        arr[k] = merged[k];
    }
}

int main() {
    vector<int> arr = {2 ,3 , 8 ,-1 ,7 ,10};

    mergeSortedHalves(arr);

    for(int x : arr) cout << x << " ";
    
    return 0;
}

// TC = O(n) and SC = O(n)