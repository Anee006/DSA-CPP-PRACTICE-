// COURSE SCHEDULE II (LeetCode 210)
// Using Topological sorting

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
// If it is impossible to finish all courses, return an empty array.

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Another correct ordering is [0,1,2,3].

// LOGIC:
// numCourses = no. of vertices
// prerequisites = directed edges of graph

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// to detect cycle in directed graph using DFS
bool hasCycleDFS(int src, vector<bool>& vis, vector<bool>& recPath, vector<vector<int>>& prerequisites)
{
    vis[src] = true;
    recPath[src] = true;

    // loop through all the edges of the graph
    for(int i=0; i<prerequisites.size(); i++)
    {
        int v = prerequisites[i][0]; // for an edge: u---->v
        int u = prerequisites[i][1];

        if(u == src)
        {
            if(!vis[v]) // if neigh "v" is not visited
            {
                if(hasCycleDFS(v, vis, recPath, prerequisites))
                {
                    return true;
                }
            }
            else if(recPath[v]) // condition for "back edge" --> cycle is present
            {
                return true;
            }
        }
    }

    recPath[src] = false;
    return false;
}

// to get the topologically sorted order
void topoSort(int src, vector<bool>& vis, stack<int>& s, vector<vector<int>>& prerequisites)
{
    vis[src] = true;

    // visit all neighbors 
    for(int i=0; i<prerequisites.size(); i++)
    {
        int v = prerequisites[i][0];
        int u = prerequisites[i][1];

        if(u == src)
        {
            if(!vis[v])
            {
                topoSort(v, vis, s, prerequisites);
            }
        }
    }

    s.push(src); // push "src" to stack
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<bool> vis(numCourses, false);
    vector<bool> recPath(numCourses, false);
    vector<int> ans; // stores the req ans

    // visit all vertices
    for(int i=0; i<numCourses; i++)
    {
        if(!vis[i])
        {
            if(hasCycleDFS(i, vis, recPath, prerequisites)) // means cycle is present --> return empty vector
            {
                return ans; // returns an empty vector
            }
        }
    }

    // If reached till here means no cycle is present --> perform Topological Sorting
    stack<int> s;
    vis.assign(numCourses, false); // reinitialise "vis" vector with "false" val, to perform topo sort

    // visit all vertices
    for(int i=0; i<numCourses; i++)
    {
        if(!vis[i])
        {
            topoSort(i, vis, s, prerequisites);
        }
    }

    // push stack elements into the "ans" vector to get the topo sorted order
    while(s.size() > 0)
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    vector<int> ans = findOrder(numCourses, prerequisites);

    cout << "Topologically sorted order : ";
    for(int val : ans)
    {
        cout << val << " ";   // 0 2 1 3 
    }
    cout << endl;

    return 0;
}