// geeksforgeeks

// Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

// Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
// Output: true
// Explanation: b[] is a subset of a[]

// Note: elements in "b" can occur in any order in "a"

// LOGIC:
// check whether every element of "b" occurs in "a"

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSubset(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> freq; // {num, freq}

    for(int num : a) freq[num]++;  // count freq of elements in "a"

    // check whether "b" can be formed from "a"
    for(int x : b) {
        if(freq[x] == 0) return false; // b does not exist in a

        freq[x]--; // decrease freq to handle duplicate values in "b"
    }

    return true;
}

int main() {
    vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> b = {11, 3, 7, 1, 7};

    if(isSubset(a, b)) cout << "True";
    else cout << "False";

    return 0;
}

// TC = O(n + m) , where n = a.size() and m = b.size()
// SC = O(n) (for hash map)