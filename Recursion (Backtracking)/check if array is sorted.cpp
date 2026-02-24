//to check if a vector is sorted i.e, if it is in strictly increasing order. 
//return "true" if it is sorted, return "false" if it is not sorted.

//LOGIC:
//If an array is sorted in increasing order, then while moving in forward direction in the array, arr[i] >= arr[i-1].
//If the above condition is not true, then array is not sorted.

//TO SOLVE THE ABOVE LOGIC USING RECURSION
//We have been given "n" , which is the size of the array.
//Check if arr[n-1] >= arr[n-2]. For the given array, arr= {1,2,3,4,5},
//n-1 = 5 and n-2 = 4. Here, 5>4. So is sorted till now for n=5.
//to check for the rest of the array, call the recursive fn again but this time for n-1 (instead of for n).
//So now, n=4. Thus, n-1= 3 and n-2= 2. Since, 3>2, so is sorted for n=4.

//The array will be sorted if both conditions are true i.e if: arr[n-1] >= arr[n-2] && isSorted(arr,n-1).

//Base Case:
//if n=0, means there are no elements in the array, hence array is sorted
//if n=1, means a single element is there in the array. A single el is always sorted, hence array is also sorted.

//NOTE: for n=1; n-1 and n-2 does not exist hence, it would give error. Hence it becomes necessary to include n=1 in the base case.

#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector <int> arr, int n) //n is the size of the vector
{
    //base case:
    if(n==0 || n==1) return true;

    return arr[n-1] >= arr[n-2] && isSorted(arr,n-1); 
    //arr[n-1] >= arr[n-2] is written first here out of the two conditions since, it is more logical to check if the el where we are at is greater 
    //or not than its previous el. If not, then there is no need to make the recursive call again, bcoz the array is unsorted.
    
}
int main()
{
    vector <int> arr= {1,2,3,4,5};
    int n= arr.size();
    cout<<isSorted(arr,n)<<endl;

    vector <int> a= {1,2,8,4,5};
    n= a.size();
    cout<<isSorted(a,n)<<endl;

    return 0;
}

//TC = total calls * work done in each call
//TC = n * O(1)        ,[in each call, const work is done]
//TC = O(n)

//SC = O(n)   ,[considering worst case scenario, height of call stack will be n]