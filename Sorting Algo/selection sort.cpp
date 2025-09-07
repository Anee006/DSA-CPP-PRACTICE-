//Selection Sort
//T.C= O(n^2)

//Given an array={4,1,5,2,3}. We need to sort this using selection sort

//Logic of selection sort:
// - We imagine the array into two parts- sorted and unsorted
// - We try to bring the smallest el from the unsorted part into the sorted part of the array.
// - So, in (n-1) iterations we try to push (n-1) smallest el. to the front of the array.

//For the given array, we run a loop to find the smallest el, which in this case is 1.
//So, we place 1 at its correct pos i.e, the 0th pos. For doing this we swap 1 with 4 in the array.
//After swapping we'll have: {1,4,5,2,3}. So, 1 is our sorted part and {4,5,2,3} is our unsorted part.
//We'll again run a loop in the unsorted part i.e in {4,5,2,3}.
//Then for the unsorted part our smallest el is 2 in this case. So we'll swap 2 with the 1st el in the unsorted half, 
//so we'll swap 2 with 4. After swapping we'll have: {1,2,5,4,3}.
//So, {1,2} is our sorted part and {5,4,3} is our unsorted part.
//The smallest el in unsorted part is 3, we'll swap 3 with 1st el of unsorted part i.e 5 here.
//After swapping we'll have: {1,2,3,4,5}.
//SO, {1,2,3} is sorted part and {4,5} is unsorted part. 4 will be our smallest el now. So we will get our sorted array :{1,2,3,4,5}.

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for(int i=0 ; i<n-1 ; i++) //outer loop
    {
        int smallestIdx=i; //we are assuming the i'th index value to be the smallest value //i becomes the 1st el of unsorted part

        for(int j= i+1; j<n; j++) //starting from (i+1)'th idx as for i'th idx we have already assumed it to be the smallest.
        {
            if(arr[j]< arr[smallestIdx]) //if here we write: arr[j] > arr[smallestIdx]. array will be sorted in desc order
            {
                smallestIdx= j; //means j is now the smallest idx
            }
        }
        swap(arr[i], arr[smallestIdx]); //we are swapping smallest el in the unsorted part with the 1st el in the unsorted part.
    }
}

void printArray(int arr[], int n) //to print the array
{
    for(int i=0 ; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int arr[]= {4,1,5,2,3};
    int n=5; //size of array

    SelectionSort(arr,n); //to sort the array
    printArray(arr,n); //to print sorted array
    return 0;
}



