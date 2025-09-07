//SINGLE ELEMENT IN SORTED ARRAY
//Using Binary Search

//Given array:  nums = [1,1,2,3,3,4,4,8,8]. Output=2
//Given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
//Return the single element that appears only once.
//The solution must run in O(log n) time and O(1) space.

//In this, we will always have odd no. of elements in the array, as each el is repeated and one element appears only once, hence odd.
//In an odd numbered array, the no. of el on both sides of mid are equal. 

//If On both sides of mid there are EVEN NO. OF ELEMENTS:
//Then check if arr[mid-1]= arr[mid], if true then the single element lies in left half only (as the repeated values pair together so left with odd)
//So when ans is left, end= mid-1
//Similarly, if arr[mid]= arr[mid+1], that means single el lies in the right half.
//so, when ans is on right, st= mid+1

//If on both sides of mid there are ODD NO. OF ELEMENTS:
//If arr[mid-1]= arr[mid], then on left side only duplicates will exist, so the single el exists on right side only.
//Similarly, if arr[mid]= arr[mid+1], then on right side duplicates exist, so the sinGLe el exists on left side.


//HOW TO CHECK IF THERE ARE EVEN OR ODD ELEMENTS ON BOTH SIDES OF "MID" ELEMENT:
//If our mid index i.e, arr[mid] is even then on both side we'll have even elements
//If mid index is odd i.e, arr[mid] is odd then on both sides we'll have odd elements


//Logic:
//Using BS algo, we'll calculate the mid first.
//Case 1: if ans is found at mid, then:
//If arr[mid-1] != arr[mid] and arr[mid]!= arr[mid+1], means arr[mid] appears only once, hence it is the req ans.

//Case 2: 
//If mid%2 ==0, means mid is even, means on both sides we have even no. of elements.

//Case 3: 
//If mid%2 !=0, means mid is odd, means on both sides we have odd no. of elements.


#include <iostream>
#include <vector>
using namespace std;

//EDGE CASES:
//Mid can be at st=0 i.e, at the start or at end=n-1 i.e, at the end.
//If single el is at first idx, then check if(mid==0 && arr[0]!= arr[1]). for the 0th el its arr[0-1] doesn't exist hence we are 
//comparing it with its next el. If it is not equal to its next el means it is the req single el.

//Similarly, if single el is at last idx, then check if(mid==n-1 && arr[n-1]!= arr[n-2]). for the last idx, arr[n] doesn't exist hence we
//are comparing it with its prev el.

//If there exists only a single el in array:
//check if(n==1), then arr[0] is the req ans

int singleElement(vector <int> &arr)
{
    int n= arr.size();
    int st=0, end=n-1;

    if(n==1) return arr[0];  //when we have only a single el in the array
    
    while(st<= end)
    {
        int mid= st+ (end-st)/2;

        if(mid==0 && arr[0]!= arr[1]) //single el occurs at first idx
            return arr[mid];
            
        if(mid== n-1 && arr[n-1]!= arr[n-2]) //single el occurs at last idx
            return arr[mid];

        //when mid= single el
        if(arr[mid-1]!= arr[mid] && arr[mid]!= arr[mid+1])
            return arr[mid];

        //if there are even number of el on both sides of mid
        if(mid%2==0)
        {
            if(arr[mid-1]==arr[mid]) //answer exists in left side
                end= mid-1;

            else //answer exists in right side
                st= mid+1; 
        }
        
        //if there are odd number of el on both sides of mid
        else
        {
            if(arr[mid-1]==arr[mid]) //answer exists in right side
                st= mid+1;
            else //answer exists in left side
                end= mid-1;
        }
    }
    return -1;
}

int main()
{
    vector <int> arr= {1,1,2,3,3,4,4,8,8};
    cout<< singleElement(arr) <<endl;
    return 0;
}