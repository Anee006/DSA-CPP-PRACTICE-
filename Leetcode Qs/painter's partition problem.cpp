//PAINTER'S PARTITION PROBLEM
//(This problem's logic is similar to that of Books's Allocation problem)

//Given an array, arr={40,30,10,20}, N=4, M=2.
//Given N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of board.
//So, we can say, arr[i] is the time taken to paint the i'th board. N is the number of boards to be painted. M is the number of painters.
//We need to find the min time required to paint all boards under the condition that any painter will paint only continuos sections of board.

//So the possible min ans for this Q is 60 (when 1st painter takes 40 time and 2nd painter takes 30+10+20=60 time to paint).

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector <int> &arr, int n, int m, int MaxAllowedTime) //here "MaxAllowedTime" is the "mid" value only
{
    int painter=1; //initially the number of painters is one
    int time=0;

    for(int i=0; i<n;i++)
    {
        if(arr[i]>MaxAllowedTime) //edge case
        {
            return -1;
        }

        if(time+ arr[i] <= MaxAllowedTime) //means we can add more time to that painter
        {
            time += arr[i];
        }

        else
        {
            painter++; //means we req a new painter
            time= arr[i];
        }
    }
    return painter<=m; //if yes then returns true else returns false
}

//for the range of search space in which we will be searching our ans:
//st= max value of(arr) i.e, in this case, st=40 as 40 is the max val in the given arr.
//end= sum of all values of (arr) i.e, in this case=100 as 40+30+10+20=100.

int minTimeToPaint(vector <int> &arr, int n, int m)
{
    int sum=0, maxValue= INT_MIN;

    for(int i=0; i<n; i++)
    {
        sum+= arr[i];
        maxValue= max(maxValue, arr[i]);
    }

    int st= maxValue;
    int end= sum;
    int ans=-1; //for storing our ans i.e, the min time req

    while(st<=end)
    {
        int mid= st+(end-st)/2;

        if(m>n) return -1; //if our no. of painters are more and no. of boards are less, so not possible to calc ans.

        //checking if our mid is a valid ans
        if(isPossible(arr,n,m,mid))
        {
            ans=mid;
            end= mid-1; //whenever ans is possible, try to find a smaller ans so search in the "left" side of arr
        }

        else //when mid is invalid ans
        {
            st=mid+1; //whenever ans is not possible, try to find a bigger ans so search in the "right" side of arr
        }
    }
    return ans;
}

int main()
{
    vector <int> arr={40,30,10,20};
    int n=4, m=2;

    cout<<minTimeToPaint(arr,n,m)<<endl;
    return 0;
}
