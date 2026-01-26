// Consider a sorted array A of n elements. The array A may have repetitive/duplicate elements. 
// For a given target element T, design an efficient algorithm to find T’s first and last occurrence in the array A. Print a message if an element was not present in the array.

// LOGIC:
// To find: First occurrence -> continue searching left
// for Last occurrence -> continue searching right
// If the element is not found, print the required message.

#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(arr[mid] == target) {
            ans = mid;
            high = mid-1; // search left --> to find the 1st occurrence
        } else if(arr[mid] < target) {
            low = mid+1; // search right
        } else {
            high = mid-1; // search left
        }
    }
    return ans;
}
// TC = O(log n)

int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size()-1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if(arr[mid] == target) {
            ans = mid;
            low = mid + 1; // search right --> to find the last occurrence
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
// TC = O(log n)

int main() {
    vector<int> arr = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int target = 5;

    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);

    if(first == -1) cout << "Element not found in the array";

    else {
        cout << "First Occurrence of " << target << ": " << first << endl;
        cout << "Last Occurrence of " << target << ": " << last << endl;
    }
    cout << "-------------------------------------------------------\n";

    target = 2;
    first = firstOccurrence(arr, target);
    last = lastOccurrence(arr, target);

    if(first == -1) cout << "Element not found in the array";

    else {
        cout << "First Occurrence of " << target << ": " << first << endl;
        cout << "Last Occurrence of " << target << ": " << last << endl;
    }
    cout << "-------------------------------------------------------\n";

    target = 100;
    first = firstOccurrence(arr, target);
    last = lastOccurrence(arr, target);

    if(first == -1) cout << "Element not found in the array\n";

    else {
        cout << "First Occurrence of " << target << ": " << first << endl;
        cout << "Last Occurrence of " << target << ": " << last << endl;
    }

    return 0;
}