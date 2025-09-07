//SORT AN ARRAY WITH 0's, 1's and 2's
//This logic can be used to solve Leetcode Q75 (sort colors).

//Using DUTCH NATIONAL FLAG (DNF) algo. TC:O(n). and SC:O(1).
//using this algo. we can sort array in a single pass i.e, using a single loop.

//The given array will only have 0, 1 and 2s in it.
//Given, arr={2,0,2,1,1,0,1,2,0,0}. 
//Sort this array so that we have: {0,0,0,0,1,1,1,2,2,2}, without using inbuilt sort() fn which has TC: O(nlogn).

//LOGIC: see youtube video no. 25 of DSA series


#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector <int> &arr)
{
    int n=arr.size();
    int low=0, mid=0, high=n-1; //taking 3 pointers to point to 0s, 1s and 2s

    while(mid<=high) //if mid>high means unsorted part is finished and we are left with sorted part
    {
        if(arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }

        else if(arr[mid]==1)
        {
            mid++;
        }

        else
        {
            swap(arr[high], arr[mid]);
            high --;
        }
    }
}

int main()
{
    vector <int> arr= {2,0,2,1,1,0,1,2,0,0};
    sortArray(arr);

    for(auto val:arr)
    {
        cout<<val<<"\t";
    }
    cout<<endl;

    return 0;
}