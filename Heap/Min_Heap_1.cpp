//to build min heap

#include <iostream>
using namespace std;

void Heapify(int arr[], int i, int n)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if(right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if(smallest != i)
    {
        swap(arr[i], arr[smallest]);
        Heapify(arr, smallest, n); //new index that needs to be put in its correct place is "smallest"
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

void buildMinHeap(int arr[], int n)
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

    buildMinHeap(arr, n);
    printHeap(arr, n);
    
    return 0;
}