// LeetCode 56

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping 
// intervals that cover all the intervals in the input.

/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

// DRY RUN:
// for intervals = [[1,3],[2,6],[8,10],[15,18]]
// result is initially empty. 1st interval is: [1,3]. So add it: result = [[1,3]]
// check [2,6]. Current interval: [2,6], Last interval in result: [1,3]
// check: interval[0] > result.back()[1]. That means: 2 > 3 ---> False. Therefore, they overlap.
// merge them: result.back()[1] = max(result.back()[1], interval[1]). max(3,6) = 6. Result becomes: [1,6]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end()); // sort intervals by their starting point

    vector<vector<int>> result;

    for(auto interval : intervals) {
        // no overlap is there
        if(result.empty() || interval[0] > result.back()[1]) result.push_back(interval);

        // merge overlapping intervals
        else result.back()[1] = max(result.back()[1], interval[1]); // for an interval [a, b], find the new 'b' value after merging intervals
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> res = merge(intervals);

    for(int i = 0; i < intervals.size(); i++) {
        for(int j = 0; j < intervals[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// TC = O(log n)
// SC = O(n)