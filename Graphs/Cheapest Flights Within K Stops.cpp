// Leetcode 787
// Using BFS and modified Dijkstra

// There are n cities connected by some number of flights. You are given an array flights where 
// flights[i] = [from_i, to_i, price_i] indicates that there is a flight from city from_i to city to_i with cost price_i.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
// If there is no such route, return -1.

/*
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The optimal path with at most 1 stop from city 0 to 3 has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

// LOGIC:
// Can't use Dijkstra directly as we have to consider stops also. We also need to explore all paths so we use BFS.
// Don't explore those paths in which k exceeds the given limit.
// Use queue instead of priority_queue (min-heap) as now it's not necessary that the cheapest path is not exceeding the given k limit.
// If src and dest are same then no. of stops = -1
// Valid path will be one that has: current_stops + 1 <= k

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int, int>> graph[n]; // for every vertex 'u' we store --> (v, wt)

    // convert graph to adjacency list
    for(int i = 0; i < flights.size(); i++) {
        int u = flights[i][0];  // src
        int v = flights[i][1];  // dst
        int wt = flights[i][2]; // price

        graph[u].push_back({v, wt});
    }

    // BFS and Dijsktra

    queue<pair<int, pair<int, int>>> q; // queue stores {node, {cost, no. of stops}}
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    q.push({src, {0, -1}}); // cost to go from src to src = 0 and no. of stops = -1

    while(!q.empty()) {
        auto val = q.front();
        int u = val.first;
        int cost = val.second.first;
        int stops = val.second.second;

        q.pop();

        // visit neighbors of u
        for(auto edge: graph[u]) {
            int v = edge.first;
            int wt = edge.second;

            // perform edge relaxation only if it is a valid path
            if(dist[v] > cost + wt && stops + 1 <= k) {
                dist[v] = cost + wt;
                q.push({v, {dist[v], stops + 1}});
            }
        }
    }

    if(dist[dst] == INT_MAX) return -1; // if no valid route exists

    return dist[dst];
}

int main() {
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n = 4, src = 0, dst = 3, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}

// TC = O(kE) , where k = max no. of allowed stops, E = no. of flights (flights.size())
// Sc = O(V + E) , where V = no. of cities (n)