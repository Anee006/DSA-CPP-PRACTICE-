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

// DFS fn to find a job for applicant u
bool canAssign(int u, int N, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& jobAssigned) {
    for(int v = 0; v < N; v++) {
        // If applicant u is interested in job v and not visited
        if(graph[u][v] && !visited[v]) {
            visited[v] = true;

            // If job is not assigned OR we can reassign the previous applicant
            if(jobAssigned[v] == -1 || canAssign(jobAssigned[v], N, graph, visited, jobAssigned)) {
                jobAssigned[v] = u; // assign job v to applicant u
                return true;
            }
        }
    }
    return false;
}

int maxMatch(vector<vector<int>>& graph, int N, int M) {
    vector<int> jobAssigned(N, -1); // // jobAssigned[j] = applicant assigned to job j
    int result = 0;

    // try to assign each applicant
    for(int i=0; i < M; i++) {
        vector<bool> visited(N, false); // reset visited for each applicant

        if(canAssign(i, N, graph, visited , jobAssigned)) result++;
    }
    return result;
}

int main() {
    /*
    graph[i][j] = 1 → applicant i interested in job j
    Example:
    Applicant 0 → Job 0,1
    Applicant 1 → Job 1,2
    Applicant 2 → Job 0,3
    Applicant 3 → Job 2
    */

    int M = 4; // Number of applicants
    int N = 4; // Number of jobs

    vector<vector<int>> graph = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 0}
    };

    cout << "Max applicants assigned jobs: " << maxMatch(graph, N, M);

    return 0;
}

// TC = O(M * N²)
// SC = O(N)