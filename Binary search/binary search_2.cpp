//BINARY SEARCH ALGORITHM 
//Using recursive method

//For, the given array, arr[]= {-1,0,3,5,9,12}, target=3 //given array is already sorted in asc order
//If target is present in array return idx else return -1.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch( vector <int> &arr, int target, int st, int end)
{
    
    if( st<= end) //base case
    {
        int mid= st + (end-st)/2;

        if(target> arr[mid]) //means we need to search the 2nd half
            return binarySearch(arr,target, mid+1, end); //update the start to mid+1

        else if( target< arr[mid]) //means we need to serach the 1st half
            return binarySearch(arr, target, st, mid-1); //update end to mid-1
    
        else
            return mid; 
    }
    return -1; //executes if base case isn't met i.e, when the target doesn't exist      
}

int main()
{
    vector <int> arr= {-1,0,3,5,9,12};
    int n= arr.size();
    cout<<binarySearch(arr,3,0,n-1) <<endl;

    return 0;
}
