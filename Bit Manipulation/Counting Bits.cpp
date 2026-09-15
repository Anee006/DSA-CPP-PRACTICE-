/// #newnotes
// LeetCode 338

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
}

int main() {
    int n = 5;

    vector<int> ans = countBits(n);

    for(int x : ans) cout << x << " ";

    return 0;
}