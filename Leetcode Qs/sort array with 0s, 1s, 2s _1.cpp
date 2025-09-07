//SORT AN ARRAY WITH 0's, 1's and 2's
//This logic can be used to solve Leetcode Q75 (sort colors).

//Using optimised sol. TC:O(n)

//The given array will only have 0, 1 and 2s in it.
//Given, arr={2,0,2,1,1,0,1,2,0,0}. 
//Sort this array so that we have: {0,0,0,0,1,1,1,2,2,2}, without using inbuilt sort() fn which has TC: O(nlogn).

//LOGIC:
//Run a loop to find the number of 0s, 1s and 2s in the array and store them.
//So for the given array:
//countOfZeroes=4, countOfOnes=3, countofTwos=3
//then we'll start overriding the values in the array.

#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector <int> &arr)
{
    int n=arr.size();
    int count_0=0, count_1=0, count_2=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0) count_0++;
        else if(arr[i]==1) count_1++;
        else count_2++;
    }

    int idx=0; //to help in overridding values

    for(int i=0;i<count_0;i++)
        arr[idx++]=0;     //overriding with 0

    
    for(int i=0;i<count_1;i++)
        arr[idx++]=1;     //overriding with 1

    
    for(int i=0;i<count_2;i++)
        arr[idx++]=2;     //overriding with 2
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