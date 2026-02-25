// Finding global and local inv using Divide and conquer --> TC = O(n logn)

// Given an array ARR of size N which is a permutation of numbers from 0 to N-1. 
// Global Inversion: A pair (i, j) such that: i < j AND ARR[i] > ARR[j].
// Local Inversion: An index i such that: ARR[i] > ARR[i+1] 
// Task: Return True if: Number of Global Inversions = Number of Local Inversions Otherwise return False.

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    int invCount = 0;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        }
        else {
            temp.push_back(arr[j++]);
            invCount += (mid-i+1);
        }
    }

    while(i <= mid) temp.push_back(arr[i++]);

    while(j <= high) temp.push_back(arr[j++]);

    for(int k= 0; k< temp.size(); k++) {
        arr[k + low] = temp[k];
    }

    return invCount;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = low + (high-low)/2;

        int leftCount = mergeSort(arr, low, mid);
        int rightCount = mergeSort(arr, mid+1, high);
        int invCount = merge(arr, low, mid, high);

        return leftCount + rightCount + invCount;
    }
    return 0; // if no inversion happens
}

int main() {
    vector<int> arr = {1, 0, 2, 4, 3};
    int n = arr.size();

    // Count Local Inversions
    int localInv = 0;

    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1]) {
            localInv++;
        }
    }

    int globalInv = mergeSort(arr, 0, n-1);

    if(globalInv == localInv) cout << "True";
    else cout << "False";

    return 0;
}

/*
TO SOLVE SAME PROBLEM IN O(N) TC:
"Global inversions = Local inversions, iff no element is more than 1 position away from its index"
Meaning: | arr[i] - i | <= 1  --> gives O(N) TC
*/