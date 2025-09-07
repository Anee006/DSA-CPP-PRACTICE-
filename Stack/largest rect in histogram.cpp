// #notes
//LARGEST RECTANGLE IN HISTOGRAM 
//using stack

//Given an array of integers "heights" representing the histogram's bar height where the width of each bar is 1, return the area of the largest 
//rectangle in the histogram.

//Input: heights = [2,1,5,6,2,3]
//Output: 10
//Explanation: The above is a histogram where width of each bar is 1. Largest rectangle has an area = 10 units. (i.e, 2*5 = 10).

//LOGIC:
//for every individual bar, calculate its "left smaller" and "right smaller" value.
//Using the left smaller value (l) and right smaller value(r), we can find width.
//width = (r-l-1)

//To calc "right smaller nearest" value use the concept of "next greater element".
//To calc "left smaller nearest" value use the concept of "previous smaller element".

//TO FIND "RIGHT SMALLER":
//create a stack which will store the index of smaller values from height[i] element. matlab jo bhi value current bar se choti hogi, 
//uska idx store hoga. And we will pop the values which are greater, from the stack.
//start traversing the array from right side i.e, in reverse order bcoz we need to find the nearest smaller value in the "right".

//TO FIND "LEFT SMALLER":
//Create a forward loop as we need to find "left" smaller value.
//rest logic remains same as that of calculating right smaller value.

//after calculating left and right smaller values, the width = (right[i] - left[i] - 1)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();
    vector <int> left(n,0); //left vector is created to store the index of left smaller val for each heights[i]
    vector <int> right(n,0); //right vector is created to store the index of right smaller val for each heights[i]

    stack<int> s;

    //to calc right smaller nearest value: (TC of this loop = O(n))
    for(int i=n-1; i>=0; i--) //reverse loop
    {
        while(s.size() > 0 && heights[s.top()] >= heights[i]) //s.top() gives idx value. heights[s.top()] gives val at that idx
        {
            s.pop(); //to pop the values which are greater than the curr heights[i]
        }

        right[i] = s.empty() ? n : s.top(); 
        //if stack is empty, no rightvsmaller el exists so n becomes right bdry. else it stores the idx at top of stack

        s.push(i);
    }

    //to reuse the same stack, we need to remove any remaining elements from the stack
    while (!s.empty())
    {
        s.pop();
    }
    
    //to calc left smaller nearest value: (TC of this loop = O(n))
    for(int i=0; i<n; i++) //forward loop
    {
        while(s.size() > 0 && heights[s.top()] >= heights[i]) //s.top() gives idx value. heights[s.top()] gives val at that idx
        {
            s.pop(); //to pop the values which are greater than the curr heights[i]
        }

        left[i] = s.empty() ? -1 : s.top(); 
        //if stack is empty, no nearest smaller el exists so ans is -1. else it stores the idx at top of stack

        s.push(i);
    }

    //to calculate final ans i.e, area of largest rectangle
    int ans = 0;
    for(int i=0; i<n; i++) //(TC of this loop = O(n))
    {
        int width = right[i] - left[i] - 1;
        int currentArea = heights[i] * width;  //area = height * width

        ans = max(ans, currentArea); //max of these two will be the ans
    }
    return ans;
}

int main()
{
    vector <int> heights = {2,1,5,6,2,3};

    cout << largestRectangleArea(heights) << endl;

    return 0;
}

//TC = O(n)
//SC = O(n)