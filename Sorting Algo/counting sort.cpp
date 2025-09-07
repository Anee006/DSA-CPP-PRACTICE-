//counting sort

#include <iostream>
using namespace std;

int getMax(int arr[],  int n)
{
    int max = arr[0];

    for(int i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n)
{
    //find the max element from the array: we need to create output array of the size of the max element
    int k = getMax(arr,n); //k is the max value

    //ideally we should make count[k], but here we do not have dynamic array
    int count[10] = {0}; //from 0-9
    int output[10];

    //count occurences of each element of the array:
    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }

    //to find cumulative count of each element of array , by adding count of its prev element
    for(int i=1; i<=k; i++) 
    {
        count[i] += count[i-1];
    }

    //build the output array by traversing backward
    for(int i=n-1; i>=0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    //copy output back to og array
    for(int i=0; i<n; i++)
    {
        arr[i] = output[i];
    }
}

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2,1,2,3,5,1};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << "Original array:\n";

    print(arr,n);

    countingSort(arr,n);

    cout <<"\nAfter sorting:\n"; //prints: 1 1 2 2 3 5
    print(arr,n);

    return 0;

}