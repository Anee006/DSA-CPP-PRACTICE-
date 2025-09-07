//SLIDING WINDOW MAXIMUM
//using deque

//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to 
//the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.

/* 
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]

Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 */

//LOGIC:
//use a deque. In a deque we can access both the front and back el, insert el at front and back and pop el from front/back.
//in the deque we will store the idx of only the elements from the current window. If el from any other window exist, then pop them.
//if any value in the deque is smaller than or equal to the current el, then pop that as well.
//in deque the element at the front will be the largest el for the current window (which is the ans).

//in deque, while popping elements, we'll pop from the back, bcoz we want the elements in the deque to be stored in descending order 
//(since the front will store the largest val for the current window, so rest of the elements in the deque need to be smaller than it)

//for a window of size k , if we have its ending idx then we can find its starting idx using (i-k+1), where i is ending idx.
//if idx < (i-k+1) then that idx is not part of the current window.

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    deque <int> dq;
    vector <int> ans;

    //to analyse the first window of the array. //TC = O(k)
    for(int i=0; i<k; i++)
    {
        while(dq.size() > 0 && nums[dq.back()] <= nums[i]) //if val in deque os < current el, pop them
        {
            dq.pop_back(); //to remove smaller values from deque
        }
        dq.push_back(i); //to push the idx of the current val
    }

    //for the rest of the windows. //TC = O(n-k)
    for(int i=k; i<nums.size(); i++)
    {
        ans.push_back(nums[dq.front()]);

        //remove elements which are not part of current window
        while(dq.size() > 0  && dq.front() <= i-k)
        {
            dq.pop_front();
        }

        //to remove smaller values
        while(dq.size() > 0 && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]); //pushing ans for the last window


    return ans;
}

int main()
{
    vector <int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = maxSlidingWindow(nums, 3);

    for(auto val: ans)
    {
        cout << val << "\t";
    }
    cout << endl;

    return 0;
}

//TC =  O(n)
//SC = O(n)