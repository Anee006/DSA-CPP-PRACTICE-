// #notes
//COUNT INVERSIONS problem 
//using the "merge" step of Merge Sort Algo.

//Benefit of using merge sort here: we can count multiple inversions at a time.

//Given arr = {6,3,5,2,7}. We need to return the count of total no. of inversions.

//What is inversion?
//for inversion we consider a pair of no. say arr[i] and arr[j].
//The pair should meet the two following conditions for it to be considered as inversion:
//1. i < j
//2. arr[i] > arr[j]

//In the given array: 
//The inversion pairs are - (6,3), (6,5) , (6,2) , (3,2) , (5,2)
//count of total no of inversions in arr = 5

#include <iostream>
#include <vector>
using namespace std;

int merge(vector <int>& arr, int st, int mid, int end)
{
    vector <int> temp;
    int i = st;
    int j = mid + 1;

    int invCount = 0; //to count inversions

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid-i+1); //to count multiple imversions at once
        }
    }

    //for the remaining elements
    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++)
    {
        arr[idx+st] = temp[idx];
    }

    return invCount;

}

int mergeSort (vector <int>& arr, int st, int end) //this fn will return the inversion count as well hence, the return type is "int"
{
    if(st < end)
    {
        int mid = st + (end - st)/2;

        //for left half
        int leftInversionCount = mergeSort(arr, st , mid);  //returns leftInversionCount

        //for right half
        int rightInversionCount = mergeSort(arr, mid+1 , end); //returns rightInversionCount

        int invCount = merge(arr, st, mid, end); //returns inv count 

        return invCount + leftInversionCount + rightInversionCount; //this is the total count of inversions
    }

    return 0; //means no inversion count exists
}

int main()
{
    vector <int> arr = {6,3,5,2,7};

    int ans = mergeSort(arr, 0, arr.size()-1);
    cout << ans <<endl;

    vector <int> arr_2 = {1,3,5,10,2,6,8,9};
    int answer = mergeSort(arr_2, 0, arr_2.size()-1);
    cout << answer <<endl;


    return 0;
}

//TC = O(n * log n)     ,[same as that of merge sort algo]
//SC = O(n)