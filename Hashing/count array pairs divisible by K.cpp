// LeetCode 2183

// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:
// 0 <= i < j <= n - 1 and
// nums[i] * nums[j] is divisible by k.

/*
Input: nums = [1,2,3,4,5], k = 2
Output: 7
Explanation: The 7 pairs of indices whose corresponding products are divisible by 2 are
(0, 1), (0, 3), (1, 2), (1, 3), (1, 4), (2, 3), and (3, 4). Their products are 2, 4, 6, 8, 10, 12, and 20 respectively.   
*/

// LOGIC:
// for each el, calc: g = gcd(arr[i], k). store freq of each gcd.
// if g1 x g2 is divisble by k --> then pair is valid.
// for each of gcd values, if (g1 x g2) % k ==  0 --> add their freq in count.

// If gcd(a,k) * gcd(b, k) is divisible by k, then a*b is also divisible by k.

// STEPS:
// create a map whose key --> gcd(arr[i], k) and val --> freq of that gcd
// check whether map's elements are divisible by X (X = quotient when k is divided by gcd(arr[i], k)).
// - if yes, add occurence of that el from map to the ans.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long countPairs(vector<int>& arr, int k) {
    long long ans = 0;
    unordered_map<int, int> m;

    for(auto val : arr) {
        long long gcd = __gcd(val, k); // calc gcd of (arr[i], k)
        long long X = k / gcd;

        for(auto it : m) { // iterate over all possible gcd
            if(it.first % X == 0) ans += it.second; // add count to ans
        }
        m[gcd]++; // add gcd to map
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int k = 2;

    cout << countPairs(arr, k);

    return 0;
}

// TC = O(N * √k) , SC = O(√k)