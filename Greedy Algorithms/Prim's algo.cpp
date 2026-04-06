// PRIMS'S ALGORITHM FOR MST

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int V = 6; // no. of vertices

    // Adjacency list: each entry stores (neighbor, weight)
    vector<vector<pair<int, int>>> adj(V);

    // Edges for undirected graph: adj[u] stores a list of (v, weight) pairs
    adj[0].push_back({1,7});
    adj[1].push_back({0,7});

    adj[0].push_back({2,8});
    adj[2].push_back({0,8});

    adj[1].push_back({3,6});
    adj[3].push_back({1,6});

    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    adj[2].push_back({4,3});
    adj[4].push_back({2,3});

    adj[2].push_back({3,4});
    adj[3].push_back({2,4});

    adj[3].push_back({4,2});
    adj[4].push_back({3,2});

    adj[3].push_back({5,5});
    adj[5].push_back({3,5});

    adj[4].push_back({5,2});
    adj[5].push_back({4,2});

    // Min Heap (priority queue). Stores (weight, vertex, parent)
    priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<>> pq; // is max-heap by default, so need to change it to min heap

    vector<bool> visited(V, false); // tracks visited nodes
    vector<int> parent(V, -1); // used to track MST edges

    pq.push({0, 0, -1}); // start from node 0

    int totalWeight = 0;
    
    while(!pq.empty()) {

        // extract always the min edge from a vertex
        auto [weight, u, p] = pq.top();
        pq.pop();

        // ignore if a vertex is already included in the MST
        if(visited[u]) continue;

        // otherwise, include vertex in MST
        visited[u] = true;
        totalWeight += weight;
        parent[u] = p;

        // 3. Traverse adj list of u --> explore neighbors
        for(auto edge: adj[u]) {
            int v = edge.first; // v is the adjacent node
            int wt = edge.second;

            if(!visited[v]) {
                pq.push({wt, v, u});  //parent[v] = u
            }
        }
    }

    cout << "Total MST weight = " << totalWeight << endl;

    cout << "\nEdges in MST:\n";
    for(int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << endl;
    }
    return 0;
}

// TC = O(E log V)