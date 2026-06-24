// Leetcode 31

// Given an array of integers nums, find the next permutation of nums.
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
// If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographically larger rearrangement.

// Example :
// for arr = [1,2,3], the following are all the permutations: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
// Output: [1,3,2]

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void nextPermutation(vector<int>& A) {
    int n = A.size();
    int pivot = -1; 

    for(int i = n-2; i >= 0; i--) { // Starting from n-2 as next el of n-1 doesn't exist
        if(A[i] < A[i+1]) { // found pivot
            pivot = i;
            break; // after pivot is found, exit loop
        }
    }

    if(pivot == -1) { // means if pivot cannot be found i.e, if the vector is in decreasing order, then rev the vector
        reverse(A.begin(), A.end()); // made in place changes  // can also use two pointer approach to reverse
        return;                      
    }

    // as travelling backwards, means we'll get the smallest el which is greater than pivot
    for(int i = n-1; i > pivot; i--) { // to find the rightmost el, which is greater than pivot                             
        if(A[i] > A[pivot]) {
            swap(A[i], A[pivot]);
            break;
        }
    }

    // to reverse el from (pivot+1) to (n-1), using two pointer approach
    int i = pivot+1;
    int j = n-1;

    // instead of using the while loop below, can also use: reverse(A.begin() + pivot + 1, A.end())
    while(i <= j) {
        swap(A[i], A[j]);    // instead of these 3 lines can also write : swap(A[i++], A[j--])
        i++;
        j--;
    }
}

int main() {
    vector<int> arr = {1,2,3,6,5,4};
    nextPermutation(arr);

    for(auto val: arr) cout << val << "\t";
    cout << endl;

    return 0;
}

// TC = O(n) 
// SC = O(1)