// Given an array ARR of size N which is a permutation of numbers from 0 to N-1. 
// Global Inversion: A pair (i, j) such that: i < j AND ARR[i] > ARR[j].
// Local Inversion: An index i such that: ARR[i] > ARR[i+1] 
// Task: Return True if: Number of Global Inversions = Number of Local Inversions Otherwise return False.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 0, 2, 4, 3};
    int n = arr.size();

    return 0;
}