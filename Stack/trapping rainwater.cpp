// #notes
//TRAPPING RAINWATER PROBLEM 
//using most optimal solution (not the prefix Array approach), with TC = O(n) and SC = O(1)

//Given 'n' non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water are being trapped.


//LOGIC for optimal approach:
//we will calculate leftMax and rightMax using two pointer approach but will not store its value in a new vector. We will directly calculate ans 
//using leftMax and rightMax.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trapWater(vector<int>& height)
{
    int n = height.size();
    int ans = 0; //ans will always be +ve as "height" contains non negative integers

    //creating left and right pointers
    int l = 0, r = n-1; //left ptr points to 1st el and right ptr points to last el

    int leftMax = 0, rightMax = 0; //these two are used to track the left and right boundary for a particular bar. 
    //NOTE: here, instead of creating vectors leftMax and rightMax we have created two variables instead.

    while(l < r)
    {
        //calculate the boundaries:
        //we will compare the l and r pointers with the left and right boundaries( i.e, leftMax and rightMax).
        leftMax = max(leftMax, height[l]); //the value which is greater of leftMax and height[l] becomes leftMax
        rightMax = max(rightMax, height[r]);

        if(leftMax < rightMax) //if left bdry is smaller than right bdry then, left bdry will be deciding factor
        {
            ans += leftMax - height[l];  //leftMax - height[l] , is the water trapped by a single bar
            l++; //to calc for the next bar
        }
        else //right bdry will be the deciding factor
        {
            ans += rightMax - height[r];
            r--; //to calc for the next bar
        }
    }
    return ans;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trapWater(height) << endl;
    
    return 0;
}