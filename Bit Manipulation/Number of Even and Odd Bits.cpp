// LeetCode 2595

// You are given a positive integer n. Let even denote the number of even indices in the binary representation of n with value 1.
// Let odd denote the number of odd indices in the binary representation of n with value 1.
// Note that bits are indexed from right to left in the binary representation of a number. Return the array [even, odd].

/*
Input: n = 50
Output: [1,2]
Explanation:
The binary representation of 50 is 110010. It contains 1 on indices 1, 4, and 5.
So even index = 1, odd indices = 2
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> evenOddBit(int n) {
    int even = 0, odd = 0, idx = 0;

    while(n > 0) {
        if(n % 2 == 1) { // check if current bit is 1
            if(idx % 2 == 0) even++;

            else odd++;
        }

        n /= 2; // move to the next bit

        idx++;
    }
    return {even, odd};
}

int main() {
    int n = 50;

    vector<int> ans = evenOddBit(n);

    for(int x : ans) cout << x << " ";

    return 0;
}

// TC = O(log n)
// SC = O(1)