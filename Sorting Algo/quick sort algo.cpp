//QUICK SORT ALGO

//We need to sort the array = {5,2,6,4,1,3} in ascending order.

//Quick sort algo works on pivot and partition.
//pivot is a special idx around which the sorting is done. 
//we'll pick the last el as our pivot element.
//we keep the el <= pivot on the left side of the pivot and all the el > pivot on the right side of pivot.

//for the given array, our pivot is 3 (which is the last el).
//So after placing elements on left and right we get: 2,1,3,5,6,4. 
//Note that it isn't necessary that the elements will be sorted while placing as seen, in the above case.

//Now, we'll repeatedly call quicksort for the left and right half

//we will create a partition fn in which we'll pass the given array. This fn will give us the correct idx of pivot i.e, 
//pivotIdx = partition(arr, st, end). Here, "st" points to start of array and "end" points to end of array.
//pivotIdx is the correct idx of the pivot in the sorted array.
//partition will basically return us the array in this form:  2,1,3,5,6,4

//pivot = arr[end]

//So, the left half is from: st to pivotIdx-1
//and, the right half is from: pivotIdx+1 to end

//In the partition fn: we'll take two iterators: idx  and j.
//idx is used to put elements <= pivot at its correct position. idx is initialised with st-1.
//j is used to compare all the elements with the pivot. j goes from st to end-1.

//in the left half i.e, (2,1) the pivot = 1. Since, 2>1 so place 2 to the right of 1. Thus, we get (1,2).
//in right half i.e, (5,6,4) pivot = 4. since 5 and 6 > 4 so we get: (4,5,6). Now pivot = 6, since 5<6 se get (5,6).
//Now, we'll backtrack and get (4,5,6) in the right half and in the left half we'll get (1,2).

//Our final sorted array will be: {1,2,3,4,5,6}

#include <iostream>
#include <vector>
using namespace std;

int partition(vector <int>& arr, int st, int end)
{
    int idx = st-1; //first iterator //used to place el less than pivot in the left half
    int pivot = arr[end]; //choosing last el as the pivot

    for(int j=st; j<end; j++) //second iterator //used to compare array elements with the pivot
    {
        if(arr[j] <= pivot) //to sort in descending order, write: if(arr[j] >= pivot)
        {
            idx++; //so that idx points at the first el of array and so on
            swap(arr[j], arr[idx]);
        }
    }

    //to put pivot at its correct position in the original array
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector <int>& arr, int st, int end)
{
    if(st<end)
    {
        int pivotIdx = partition(arr, st, end);

        //for the left half:
        quickSort(arr, st, pivotIdx-1);

        //for the right half:
        quickSort(arr, pivotIdx+1, end);
    }
}

int main()
{
    vector <int> arr = {5,2,6,4,1,3};

    quickSort(arr, 0, arr.size()-1);

    for(int val :arr)
    {
        cout << val <<"\t";
    }
    cout<<endl;

    return 0;
}

//TC in avg/ practical cases = O(n* log(n))
//TC in worst cases = O(n^2)

//worst-case occurs when our pivot is repeatedly either the smallest or the largest element of the array
//example in case of the array = {1,2,3,4,5,6}.

//SC = O(1)