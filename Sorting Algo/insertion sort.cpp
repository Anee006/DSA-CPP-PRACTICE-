//Insertion Sort
//T.C= O(n^2)

//Given an array={4,1,5,2,3}. We need to sort this using insertion sort

//Logic of insertion sort:
//For the given array, let us assume that 4 is the sorted part and 1,5,2,3 is the unsorted part.
//Now we'll pick the first el from unsorted part i.e 1 in this case and we'll try to arrange it in its correct pos in the sorted part.
//we'll create a variable "current" in which we'll store the first el of unsorted part i.e, current=1 here.
//We'll compare this current val with each el in arr to see which is the correct pos for this current to be placed at.
//Let us assume arr[prev]=4. so we'll compare arr[prev] with arr[prev+1].
//When we compare arr[prev] with arr[prev+1] i.e for the array 4 and 1. We'll see that 4 is>1 so we will bring
//1 in the first pos and 4 in the 2nd pos. So we'll have{1,4,5,2,3}. Where 1,4 is sorted and 5,2,3 is unsorted part
//Now, current=5 (as 5 is now the first el of the unsorted part).
//we'll compare 4 with 5. since 4<5 so no change.
//So now, sorted part is 1,4,5 and unsorted part is 2,3.
//Now, current=2. On comparing 5 with 2 we see that 5>2. 
//So if(arr[prev]>current) then arr[prev+1]= arr[prev].
//After shifting is done we'll have 1,2,4,5,3.
//now sorted part is 1,2,4,5 and unsorted part is 3. so current=3
//As 5>3 so we need to shift el. after shifting we'll have 1,2,3,4,5 which is sorted array.


#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1 ; i<n ; i++) //outer loop needs to run n-1 times. starting from i=1, as we want to show i as the 1st el of unsorted part
    {
        int current= arr[i]; 
        int prev=i-1; //stores prev el

        while(prev>=0 && arr[prev]>current) //running the loop backwards //if arr[prev]>current then only we need to shift el. otherwise not
        {                                   //if  instead of arr[prev]>current we write: arr[prev]<current. we'll get arrary in desc order.
            arr[prev+1]= arr[prev];
            prev--;
        }
        arr[prev+1]= current; //current ko uski sahi jagah pahunchane ke liye
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

    insertionSort(arr,n); //to sort the array
    printArray(arr,n); //to print sorted array
    return 0;
}



