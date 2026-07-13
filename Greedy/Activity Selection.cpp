// Activity Selection (Task Scheduling)

// A student can do 'n' activities in a week. Each activity takes a particular number of hours (mention the start time and the end time). 
// Write a program to take 'n' such inputs from user so that a student can schedule maximum number of activities.

// LOGIC:
// Always pick the activity that finishes earliest. Then select next activity whose start time ≥ last selected finish time.
// Because choosing earliest finishing leaves maximum room for remaining activities.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// each pair represents: (start_time, end_time)
struct Activity {
    int start, end;
};

// Comparator to sort by end time (Greedy choice)
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;
    cout << "Enter no. of activities: ";
    cin >> n;

    vector<Activity> arr(n);

    cout << "Enter start and end time of activities:\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i].start >> arr[i].end;
    }

    // sort activities by end time
    sort(arr.begin(), arr.end(), compare);

    // select 1st activity
    int count = 1;
    int lastEnd = arr[0].end;

    cout << "\nSelected activities:\n";
    cout << "(" << arr[0].start << ", " << arr[0].end << ")\n";

    // traverse remaining activities
    for(int i=1; i<n; i++) {
        // if activity doesn't overlap
        if(arr[i].start >= lastEnd) {
            cout << "(" << arr[i].start << ", " << arr[i].end << ")\n";
            count++;
            lastEnd = arr[i].end;
        }
    }

    cout << "\nMax activites: " << count << endl;

    return 0;
}

// TC = O(n log n), SC = O(n)

/* Sample input:
Enter number of activities: 6
Enter start and end time:
1 2
3 4
0 6
5 7
8 9
5 9
*/