//Interpolation search
//used to search in a sorted array.
//TC = O(log log n)

//given array: {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 }.


#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key)
{
    int low =0, high = n-1;

    while(low <= high && key >= arr[low] && key <= arr[high])
    {
        //estimate position using this formula:
        int pos = low + ((key - arr[low]) * (high - low) / (arr[high] - arr[low]));

        //if estimated position was correct --> idx is found
        if(arr[pos] == key)
        {
            return pos;
        }

        if(arr[pos] < key ) // move right
        {
            low = pos + 1;
        }
        else // move left
        {
            high = pos-1;
        }
    }
    return -1; //if not found
}

int main()
{
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << interpolationSearch(arr, n, 18) << endl; //returns 4
    cout << interpolationSearch(arr, n, -10) << endl; //returns -1

    return 0;
}