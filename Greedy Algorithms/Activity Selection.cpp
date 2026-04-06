// Activity Selection (Task Scheduling)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> activities = {{1,3}, {2,5}, {4,7}, {6,9}};

    // sort by finish time
    sort(activities.begin(), activities.end(), 
    [](auto &a, auto &b) {return a.second < b.second; });

    int count = 1;

    int lastEnd = activities[0].second;

    for(int i=1; i < activities.size(); i++) {
        if(activities[i].first >= lastEnd) {
            count++;
            lastEnd = activities[i].second;
        }
    }

    cout << "Max activites: " << count << endl;

    return 0;
}

// TC = O(n log n)