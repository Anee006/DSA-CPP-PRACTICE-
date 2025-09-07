//Bubble Sort
//T.C= O(n^2)

//Given an array={4,1,5,2,3}. We need to sort this using bubble sort

//Logic of bubble sort:
// - In (n-1) iterations, we will compare adjacent elements.
// - The larger of those two will be pushed to the last, using swaps.

//For the given array: {4,1,5,2,3}
//In the 1st iteration,
//4>1, so the new array after swapping will be: {1,4,5,2,3}.
//4<5, so no change in array, the array is still: {1,4,5,2,3}
//5>2, so the new array after swapping will be: {1,4,2,5,3}
//5>3, so the new array after swapping will be: {1,4,2,3,5}. So the 1st largest el in array i.e, 5 here is pushed to the last

//In the 2nd iteration,
//The array now is: {1,4,2,3,5}. 
//1<4, so array remains same i.e, {1,4,2,3,5}
//4>2, so new array after swapping: {1,2,4,3,5}
//4>3, so the new array after swapping will be: {1,2,3,4,5}
//So the 2nd largest el in array i.e, 4 here is also pushed to its correct position

//In the 3rd iteration,
//Even though our array is sorted now, but in bubble sort the iterations will happen for (n-1) times.
//So we'll do the comparisons again for this iteration and at the end we'll have {1,2,4,3,5}.

//In the 4th iteration, i.e, the (n-1)'th iteration
//After doing comparison we'll have, {1,2,4,3,5}. Which is our sorted array. We don't need to do the n'th iteration as, if all
//the rest of the el in array are sorted then the remaining one el will also be sorted automatically.

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i=0 ; i<n-1 ; i++) //outer loop
    {
        bool isSwap=false; //initially assumed that no swapping is happening

        //"isSwap" variable is used to track ki swapping ho rahi hai ya nhi. if swapping nhi ho rahi means our array is sorted, before
        //n-1 iterations happened, as was the case in the given array. So this will help to stop the swapping once swapping isn't
        //happening. Thus optimises bubble sort.

        for(int j=0 ; j<n-i-1 ; j++) //inner loop
        {
            if(arr[j] >arr[j+1]) //if true, means we have to swap the el and push larger el to back
            {                    //if instead of arr[j] >arr[j+1] we write: arr[j]< arr[j+1], we will get array in desc order.
                swap(arr[j], arr[j+1]);
                isSwap= true; //means ki swapping ho rahi hai
            }
        }
        
        if(!isSwap) //means koi swapping nhi hui inner loop ke andar //means array is already sorted
        {
            return;
        }
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

    bubbleSort(arr,n); //to sort the array
    printArray(arr,n); //to print sorted array
    return 0;
}



