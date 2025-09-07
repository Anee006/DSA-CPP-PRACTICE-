//SEARCH IN A ROTATED SORTED ARRAY problem
//Using Binary search : TC= O(log n)

//Given arr= {3,4,5,6,7,0,1,2}, target=0
//The above array was originally: {0,1,2,3,4,5,6,7}, it was then rotated from 3 onwards and so the part 3,4,5,6,7 was thus brought to front.
//Since, it is a rotated sorted array, normal binary search rules can't be applied to this directly.

//In rotated sorted array, after calculating mid, either the right half or the left half will always be sorted.
//For eg, in the given array: {3,4,5,6,7,0,1,2}, mid=6 so, in this case, the left half of array (3,4,5) is sorted,
//so, can use BS in the left half.
//We'll check if arr[st]<= target <= arr[mid] i.e, we are checking whether the target lies b/w st & mid; if it is true then we'll check in left half
//else, we'll check in right half.

//Conditions for checking in left half: (st, mid-1)
//Conditions for checking in right half: (mid+1, end)

//To check if left half is sorted: arr[st] < arr[mid]. The else case will check if right half is sorted


//NOTE: if our right half was sorted then, we'll do this:
//Check, if arr[mid] <= target <= arr[end]



#include <iostream>
#include <vector>
using namespace std;

int search(vector <int> &arr, int target)
{
    int n= arr.size();
    int start=0, end= n-1;

    while(start <= end)
    {
        int mid= start + (end-start)/2;

        if(arr[mid] ==target)
            return mid; //returns the req index
        
        if(arr[start] <= arr[mid]) //for checking if left half is sorted
        {
            if(arr[start] <= target && target <= arr[mid]) //for checking if target lies b/w start and mid //if this is true, check in left half
                end= mid-1;

            else
                start= mid+1; //for checking in right half
        }

        else //for checking if right half is sorted
        {
            if(arr[mid] <= target && target <= arr[end]) //for checking if target lies b/w mid and end //if this is true, check in right half
                start= mid+1;
            
            else
                end= mid-1; //for checking in left half
        }
    }
    return -1;

}

int main()
{
    vector <int> arr= {3,4,5,6,7,0,1,2};
    cout<< search(arr,0);
    
    return 0;
}