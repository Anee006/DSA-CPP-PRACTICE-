//CONTAINER WITH MOST WATER PROBLEM
//using Two Pointer approach: We start our left pointer from 0th index and our right pointer from (n-1)th index.
//TC: O(n)

//We have been given the height of n lines, height= {1,8,6,2,5,4,8,3,7}. 
//Imagine these lines as a container now. 
//Return the max amount (area) of water container can store.

//to make a container we need two lines. One acts as the left boundary of the container and the other acts as the right boundary.

#include <iostream>
#include <vector>
using namespace std;

int maxArea( vector <int>& height)
{
    int n= height.size(); //lenght of vector height
    int lp= 0; //left pointer
    int rp= n-1; //right pointer
    int maxWater=0;

    while(lp<rp)
    {
        int width= rp-lp;
        int ht= min(height[lp], height[rp]);
        int curWater= width*ht; //water in current container

        maxWater= max(maxWater, curWater);

        height[lp]<height[rp] ? lp++ : rp--; //means, if height of lp is less than rp, then lp++ else do rp--
    }
    return maxWater;
}

int main()
{
    vector <int> height={1,8,6,2,5,4,8,3,7};
    cout<<"Max water that can be stored is: "<<maxArea(height)<<endl;

    return 0;
}