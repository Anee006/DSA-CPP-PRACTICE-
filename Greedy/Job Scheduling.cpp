// Job Scheduling with Deadlines

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit; // sort in desc order
}

int main() {
    vector<Job> jobs = {{1,2,100}, {2,1,19}, {3,2,27}, {4,1,25}, {5,3,15}}; // (job_id, deadline, profit)

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 3; // max of all deadlines given
    vector<int> slot(maxDeadline + 1, -1);
    int profit = 0;

    for(auto job : jobs) {
        for(int i = job.deadline; i > 0; i--) {
            if(slot[i] == -1) {
                slot[i] = job.id;
                profit += job.profit;
                break;
            }
        }
    }

    cout << "Max Profit: " << profit << endl;

    return 0;
}

// TC = O(n^2)