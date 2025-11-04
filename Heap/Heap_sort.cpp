// Heap sort

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

void buildMaxHeap(int arr[], int n)
{
    for(int i = n/2 - 1; i >=0; i--)
    {
        Heapify(arr, i, n);
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

//to sort the heap in ascending order
void HeapSort(int arr[], int n)
{
    for(int i= n-1; i>0; i--)
    {
        swap(arr[i], arr[0]);
        Heapify(arr, 0, i); //size is equal to "i"
    }
}

int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int n = sizeof(arr)/ sizeof(arr[0]);

    buildMaxHeap(arr, n);
    printHeap(arr, n);  //70 14 18 11 5 13 8 9 10 3 

    HeapSort(arr, n);
    
    printHeap(arr, n);  //3 5 8 9 10 11 13 14 18 70 
    
    return 0;
}