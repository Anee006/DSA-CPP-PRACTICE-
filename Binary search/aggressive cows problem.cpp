// #notes
//AGRESSIVE COWS PROBLEM
//(Kinda similar logic to that of Book Allocation prob)

//We have to assign N stalls such that min distance b/w them is the largest. The cows are agressive so we can't assign them too close.
//We have to return the largest minimum distance.

//Given, arr= {1,2,8,4,9} , N=5,  C=3. Where, C is the no. of cows to be placed.

#include <iostream>
#include <vector>
#include <algorithm> //to use sort()
using namespace std;


bool isPossible(vector <int> &arr, int n, int c, int minAllowedDis)
{
    int cows=1; //initially we have only one cow needed to be placed
    int lastStallPos= arr[0]; //placed the first cow at 1st stall pos. 

    for(int i=1; i<n; i++) //starting from i=1, as we have already set our first cow at 0th pos, so start placing other cows from 1st pos.
    {
        if((arr[i]- lastStallPos) >= minAllowedDis) //if true means can place more cows
        {
            cows++;
            lastStallPos =arr[i];
        }
        if(cows==c) //means we have placed all the req cows
        {
            return true;
        }
    }
    return false; //when we haven't been able to place all cows
}

int getDistance(vector <int> &arr, int n,int c)
{

    sort(arr.begin(), arr.end()); //to sort the given arr

    int st=1, end= arr[n-1]-arr[0]; //for the range in which we need to search our ans //end= MaxValue-MinValue;
    int ans=-1;

    while(st<=end)
    {
        int mid= st+ (end-st)/2;

        if(isPossible(arr,n,c,mid)) //if true, we need to find a bigger ans so search in right
        {
            ans=mid;
            st= mid+1;
        }

        else //if false, we need to find a smaller ans so search in left
        {
            end= mid-1;
        }
    }
    return ans;
}


int main()
{
    vector <int> arr= {1,2,8,4,9}; //arr[i] is the position of i'th stall
    int n=5; //No. of stalls
    int c=3; //no. of cows to be placed

    cout<<getDistance(arr, n, c) <<endl;

    return 0;
}