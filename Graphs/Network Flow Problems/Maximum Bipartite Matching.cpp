// Maximum Bipartite Matching problem (Applicants <-> Jobs)

// There are M job applicants and N jobs. Each applicant has a subset of jobs that he/she is interested in. Each job opening can only 
// accept one applicant and a job applicant can be appointed for only one job. Implement an efficient algorithm to find an assignment 
// of jobs to applicants in such a way that as many applicants as possible get jobs.

/*
NOTE:
To identify Bipartite Matching problems:
- Two groups (Applicants ↔ Jobs, Boys ↔ Girls, Tasks ↔ Machines)
- One-to-one assignment
- Maximize number of matches
*/

// LOGIC:
/*
Treat: Left side -> Applicants (M) and, Right side -> Jobs (N).
If applicant i is interested in job j, draw an edge. Try to assign each applicant a job:
If job is free -> assign directly, else -> try to reassign the current applicant.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
    graph[i][j] = 1 → applicant i interested in job j
    Example:
    Applicant 0 → Job 0,1
    Applicant 1 → Job 1,2
    Applicant 2 → Job 0,3
    Applicant 3 → Job 2
    */

    vector<vector<int>> graph = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 0}
    };

    return 0;
}