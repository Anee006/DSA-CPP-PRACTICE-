// #notes
//MERGE SORT ALGORITHM 

//It is a recursion based algorithm used to sort array/vector in increasing/ decreasing order.
//It works on divide and conquer. it works in two steps.
//In first step, we divide array into two equal  parts repeatedly till in the end we only have a single el in each part
//In second step, we merge these parts into a sorted array.
//We'll sort the elements while backtracking.

//Given array= {12,31,35,8,32,17}.
//sorted array = {8,12,17,31,32,35}

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int st, int mid, int end) //TC of this fn is O(n) where n is the total no of el in the array
{
    vector <int> temp; //temporary storage used to sort data

    int i = st; //starts from 1st value of left half
    int j = mid+1; //starts from 1st val of right half

    while( i<=mid && j<=end)
    {
        if(arr[i] <= arr[j])  //to sort in descending order, write this: if(arr[i] >= arr[j]) and rest of the code remains same
        {
            temp.push_back(arr[i]); //we'll push back the smaller of the two values first, to get the sorted order
            i++;
        }
        else
        {
            temp.push_back(arr[j]); //we'll push back the smaller of the two values first, to get the sorted order
            j++;
        }
    }

    //for the remaining elements: if in left half:
    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    
    //for the remaining elements: if in right half:
    while(j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    //using temp to change original arr
    for(int idx=0; idx<temp.size(); idx++)
    {
        arr[idx+st] = temp[idx]; //here, "idx+st" is the index at which the val in temp needs to be placed in the original array
    }

}

void mergeSort(vector<int>& arr, int st, int end)
{
    if(st<end)
    {
        int mid = st + (end-st)/2;

        //for left half
        mergeSort(arr, st, mid);

        //for right half
        mergeSort(arr, mid+1, end);

        merge(arr, st, mid, end); //to merge the parts
    }

}
int main()
{
    vector <int> arr = {12,31,35,8,32,17};

    mergeSort(arr, 0, arr.size()-1);

    for(int val: arr)
    {
        cout << val << "\t";
    }
    cout<<endl;

    return 0;
}

//TC = total no of rec calls * work done in each call
//TC = (log n) * n
//TC = O(n * log(n))

//SC = O(n)   ,[due to the temp vector we created]