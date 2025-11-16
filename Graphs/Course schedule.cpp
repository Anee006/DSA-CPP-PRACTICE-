// #newnotes
// COURSE SCHEDULE (LeetCode 207)
// (concept is of: topological sort)
// We will use "cycle detection in directed graph using DFS" to solve this Q.

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses (along with their dependencies). Otherwise, return false.

// numCourses --> No. of vertices in graph
// prerequisites --> directed edge in graph

// each course is a "vertex" of the graph.

// LOGIC:
// If a cycle is present in graph --> Then, graph is not a DAG --> return "false" as ans
// else, return "true" as the ans.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// to detect if a cycle is present in the graph, using DFS
bool isCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& prerequisites)
{
    vis[src] = true;
    recPath[src] = true; // storing src node in the recursion path

    for(int i=0; i<prerequisites.size(); i++) // loop on all "edges" of the graph
    {
        // find all "u" & "v" vertex for an edge: u----->v
        // eg, for [1,0] , "u" = 0 and "v" = 1.

        int v = prerequisites[i][0]; // the "first" val of the pair (say [1,0]) will be "v"
        int u = prerequisites[i][1]; // the "second" val of the pair (say [1,0]) will be "u"

        // find all neighbors of "src"
        if(u == src) // means "v" will be the neighbor of "u"
        {
            if(!vis[v])
            {
                if(isCycleDFS(v, vis, recPath, prerequisites))
                {
                    return true;
                }
            }

            else if(recPath[v]) // if neighbor is already visited and is also part of the rec path
            {
                return true;
            }
        }
    }
    recPath[src] = false; // backtracking
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<bool> vis(numCourses, false); // size of vector = no. of courses we have (vertices)
    vector<bool> recPath(numCourses, false);

    for(int i=0; i<numCourses; i++)
    {
        if(!vis[i])
        {
            if(isCycleDFS(i, vis, recPath, prerequisites)) // means cycle exists --> not a DAG --> return false
            {
                return false;
            }
        }
    }
    return true;
}

// TC = O(V+E), where V = no. of vertices and E = no. of edges
// SC = O(V) 

int main()
{
    int numCourses = 4; // no. of courses = 4

    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    if(canFinish(numCourses, prerequisites))
    {
        cout << "Can finish courses\n"; // returns this
    }

    else cout << "Cannot finish courses\n";

    cout << "\n--------------------------------------------\n\n";

    numCourses = 2; // no. of courses = 2

    vector<vector<int>> prerequisites_2 = {
        {0,1},
        {1,0},
    };

    if(canFinish(numCourses, prerequisites_2))
    {
        cout << "Can finish courses\n";
    }

    else cout << "Cannot finish courses\n"; // returns this


    return 0;
}