// geeksforgeeks

// Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

// Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
// Output: true
// Explanation: b[] is a subset of a[]

// Note: elements in "b" can occur in any order in "a"

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSubset(vector<int>& a, vector<int>& b) {
}

int main() {
    vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> b = {11, 3, 7, 1, 7};

    if(isSubset(a, b)) cout << "True";
    else cout << "False";

    return 0;
}