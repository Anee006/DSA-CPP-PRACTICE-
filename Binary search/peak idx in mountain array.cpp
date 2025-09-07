// #notes
//PEAK INDEX IN MOUNTAIN ARRAY problem
//Using Binary Search algo (as it has sorted data)

//You are given an integer mountain array, arr of length n where the values increase to a peak element and then decrease.
//Return the index of the peak element. Your task is to solve it in O(log(n)) time complexity.

//arr={0,3,8,9,5,2}
//Here, the peak element=9 and peak index=3

//Before the peak of mountain occurs i.e, in this case from 0,3,8 , then for this part it is arranged in asc order
//We can say, for this part arr[i-1] < arr[i] //means pichle idx se agli value badi hogi

//After the peak of mountain occurs i.e, in this case 5,2, then for this part it is arranged in desc order.
//i.e, for this part, arr[i] > arr[i+1] 

//Condition for peak index:
//If "i" is the peak index then,
//arr[i-1]< arr[i] and arr[i]> arr[i+1]  //peak idx is greatest amongst all

//Since, we know that the array given will always be a mountain array so we can say that,
//first idx and last idx can never be the peak element as then the mountain won't form
//i.e, idx=0 and idx=n-1 can never be the peak idx.

//Using BS algo, we'll find out the mid first (mid= st + (end-st)/2)

#include <iostream>
#include <vector>
using namespace std;

int peakIndex(vector <int> & arr)
{
    int n= arr.size();
    int st=1, end= n-2; //we have modified our search space, to avoid the edge cases

    while(st<=end)
    {
        int mid = st+ (end-st)/2;

        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) //checking if our mid is the peak idx
            return mid;

        else if(arr[mid-1] < arr[mid]) //means we are on the left side of mountain i.e, on inc slope
        {
            st= mid+1; //means search for peak idx on right side
        }

        else //means we are on the decreasing side of slope i.e, on right side
        {
            end= mid-1; //to search on left side
        }
    }
    return -1; //but this will never execute since peak idx will always exist (as it is given in Q).
}

int main()
{
    vector <int> arr= {0,3,8,9,5,2};

    cout<< peakIndex(arr)<<endl;
    return 0;
}
