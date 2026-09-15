/// #newnotes
// LeetCode 338
// Using Dp

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's 
// in the binary representation of i.

/*
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0, 1 --> 1, 2 --> 10, 3 --> 11, 4 --> 100, 5 --> 101
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n+1);

    for(int i = 0; i <= n; i++) {
        ans[i] = ans[i/2] + (i % 2);
    }

    return ans;
}

int main() {
    int n = 5;

    vector<int> ans = countBits(n);

    for(int x : ans) cout << x << " ";

    return 0;
}

// TC = O(n)
// SC = O(n)