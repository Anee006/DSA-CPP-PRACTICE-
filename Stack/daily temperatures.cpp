// Leetcode 739
// uses logic of "next greater element" Q

// Given an array of integers 'temperatures' represents the daily temperatures, return an array answer such that answer[i] is the number of days you 
// have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

/*
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Explanation:
For day 0 -> 73 : next warmer (higher) temp is 74 --> which is 1 day later --> ans = 1
For day 1 -> 74 : next warmer (higher) temp is 75 --> which is 1 day later --> ans = 1
For day 2 -> 75 : next warmer (higher) temp is 76 --> which is 4 days later --> ans = 4
For 76 : No higher temp exists so --> ans = 0

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
*/

// LOGIC:
// Find the next day that has a higher temp. We need to find the 1st greater temp (similar to next greater Q).
// In the stack, store indices (not temp), because the req ans is difference of indices.

// STEPS:
// For each day, while: (stack is not empty) && (current temp > stack.top()) --> resolve ans --> pop --> push current idx 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);

    stack<int> s;

    for(int i=0; i<n; i++) {
        while(!s.empty() && temperatures[i] > temperatures[s.top()]) { // if found a higher temp than curr, store its idx and pop it
            int idx = s.top();
            s.pop();

            ans[idx] = i - idx;
        }
        s.push(i);
    }
    return ans;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = dailyTemperatures(temperatures);
    for(int i : ans) cout << i << " , ";

    return 0;
}

// TC = O(n) , where n = number of days
// SC = O(n)

// NOTE: whenever we need first future element satisfying some condition --> use monotonic stack
