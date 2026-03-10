// Intersection of Two Sorted Arrays (finding the common elements in two sorted arrays)
// using 2 pointer (optimal approach), as arrays are sorted


// LOGIC:
// start ptr 'i' at arr1 and ptr 'j' at arr2. Compare elements:
// - if arr1[i] == arr2[j] --> add to intersection, move both ptr
// - if arr1[i] < arr2[j] --> move 'i'
// - if arr1[i] > arr2[j] --> move 'j'

#include <iostream>
using namespace std;

int main() {
    
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 2, 3, 5};

    int n = sizeof(arr1)/sizeof(arr1[0]); // size of 1st arr
    int m = sizeof(arr2)/sizeof(arr2[0]); // size of 2nd arr

    int i = 0, j = 0; // create ptrs

    cout << "Intersection = ";

    while(i < n && j < m) {
        if(arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++; 
            j++;
        }

        else if(arr1[i] < arr2[j]) {
            i++;
        }

        else j++;
    }

    return 0;
}

// TC = O(n + m) --> each el is vis at most once
// SC = O(1)
