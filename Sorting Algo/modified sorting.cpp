// to sort all even-placed numbers in increasing and odd-placed numbers in decreasing order. 
// The modified array contains all sorted even-placed numbers followed by reverse sorted odd-placed numbers.
// NOTE: first element is considered as even because of its index 0.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortEvenOdd(vector<int>& arr) {
    vector<int> evenPlace;
    vector<int> oddPlace;

    // Separate even and odd-placed elements
    for(int i=0; i<arr.size(); i++) {
        if(i % 2 == 0) { // for even indices --> 0, 2, 4...
            evenPlace.push_back(arr[i]);
        }
        else oddPlace.push_back(arr[i]);
    }

    // sort even-place in increasing order
    sort(evenPlace.begin(), evenPlace.end());

    // sort odd-place in decreasing order
    sort(oddPlace.begin(), oddPlace.end(), greater<int>());

    cout << "Even-place elements in increasing order: ";
    for(int x : evenPlace) cout << x << " ";

    cout << "\nOdd-place elements in decreasing order: ";
    for(int x : oddPlace) cout << x << " ";
    cout << "\n\n";

    // Merge both even-place and odd-place into a single array:
    int j = 0;
    for(int x : evenPlace) arr[j++] = x;
    for(int x : oddPlace) arr[j++] = x;
}

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7};

    sortEvenOdd(arr);

    cout << "Modified array: ";
    for(int x : arr) cout << x << " ";

    return 0;
}

// TC for separating el based on odd-even indices --> O(n)
// TC for sorting even and odd places --> O(n log n)
// TC of the fn --> O(n log n)
