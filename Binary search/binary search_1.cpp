// #notes
//BINARY SEARCH ALGORITHM
//Using iterative method: TC= O(log n) and space complexity= O(1)

//For, the given array, arr[]= {-1,0,3,4,5,9,12}, target=12 //given array is already sorted in asc order
//If target is present in array return idx else return -1.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch( vector <int>& arr, int target)
{
    int n= arr.size();
    int start= 0, end= n-1;

    while( start<=end) //we are taking equal to case as well bcoz when start=end, i.e our answer
    {
        int mid= start + (end-start)/2; //calculating the mid value of array
        //We are not using : (start+end)/2, as this can lead to incorrect mid calc in case of overflow.

        if( target > arr[mid]) //means we need to search the 2nd half
            start= mid+1;

        else if( target < arr[mid]) //means we need to search the 1st half
            end= mid-1;

        else
            return mid; //the final ans
    }
    return -1; //this executes, if target doesn't exist in the array
}

int main()
{
    vector <int> arr= {-1,0,3,4,5,9,12};
    cout<<binarySearch(arr,12)<<endl;

    return 0;
}
