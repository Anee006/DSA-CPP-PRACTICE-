// To reverse an array using 2 pointers (Optimal approach)

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]); // size of array

    int left = 0, right = n-1;

    while(left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    cout << "Reversed array: ";

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// TC = O(n), SC = O(1)
