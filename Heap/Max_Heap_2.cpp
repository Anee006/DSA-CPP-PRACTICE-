//to build max heap

#include <iostream>
using namespace std;

void Heapify(int arr[], int i, int n)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, largest, n); //new index that needs to be put in its correct place is "largest"
    }
}

void printHeap(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void buildMaxHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >=0; i--)
    {
        Heapify(arr, i, n);
    }
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int n = sizeof(arr)/ sizeof(arr[0]);

    buildMaxHeap(arr, n);
    printHeap(arr, n);
    
    return 0;
}