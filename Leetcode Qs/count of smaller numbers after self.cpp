// Count of Smaller Numbers After Self (LeetCode 315)
// using Divide and Conquer Approach (uses modified Merge Sort)

// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

/* 
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Example 2:
Input: nums = [-1]
Output: [0]
*/

// LOGIC:
// While merging: If an element from the left half is greater than an element from the right half, then all remaining elements in the right half are smaller.
// We count how many elements from the right side move before each left element.

#include <iostream>
#include <vector>
using namespace std;

// we use vector<pair<int,int>>& arr  --> to store: {value, original_index}
/*
Our original nums array is: [5,2,6,1]
Now, after sorting, we still have:
{5,0}
{2,1}
{6,2}
{1,3}
i.e, original indices have been preserved.

So when we calculate inversion count, we update: count[arr[i].second] += rightCount;
Here:
arr[i].second → original index
So result goes to correct position
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int>>& arr, int low, int mid, int high, vector<int>& count) {
    vector<pair<int, int>> temp;
    int i = low;
    int j = mid + 1;
    int rightCount = 0;

    while(i <= mid && j <= high) {
        if(arr[i].first > arr[j].first) {
            rightCount++;
            temp.push_back(arr[j]);
            j++;
        }
        else {
            count[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }
    }

    while(i <= mid) {
        count[arr[i].second] += rightCount;
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int k = low; k <= high; k++) {
        arr[k] = temp[k - low];
    }
}

void mergeSort(vector<pair<int, int>>& arr, int low, int high, vector<int>& count) {
    if(low >= high)
        return;

    int mid = low + (high - low)/2;

    mergeSort(arr, low, mid, count);
    mergeSort(arr, mid + 1, high, count);
    merge(arr, low, mid, high, count);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int,int>> arr;

    for(int i = 0; i < n; i++)
        arr.push_back({nums[i], i});

    vector<int> count(n, 0);

    mergeSort(arr, 0, n - 1, count);

    return count;
}

int main() {
    vector<int> nums = {5, 2, 6, 1};

    vector<int> ans = countSmaller(nums);

    for(int val : ans)
        cout << val << " ";

    return 0;
}