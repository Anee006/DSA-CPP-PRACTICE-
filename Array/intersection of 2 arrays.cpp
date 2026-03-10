// LeetCode 349

// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must be unique and you may return the result in any order.

/*
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

}

int main() {
    int n1, n2, el;
    vector<int> nums1, nums2;

    cout << "Enter no. of elements for 1st array: ";
    cin >> n1;

    cout << "Enter elements of 1st array:\n";
    for(int i=0; i<n1; i++) {
        cin >> el;
        nums1.push_back(el);
    }

    cout << "\nEnter no. of elements for 2nd array: ";
    cin >> n2;

    cout << "Enter elements of 2nd array:\n";
    for(int i=0; i<n2; i++) {
        cin >> el;
        nums2.push_back(el);
    }

    cout << "Intersection is: ";
    vector<int> ans = intersection(nums1, nums2);

    for(int val : ans) cout << val << " ";

    return 0;
}