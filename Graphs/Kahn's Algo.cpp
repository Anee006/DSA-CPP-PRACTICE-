// Topological sorting using BFS

// works by calculating indegree (no. of incoming edges to the node).

// STEPS:
// 1. calc indegree of each node
// 2. the nodes that have indegree = 0 will come first in the Topo order (as they have no dependencies).
// these nodes become the starting nodes for the Topo sorted order.

// 3. run BFS logic
// push indegree = 0 nodes in queue. Pop them one by one and do indegree-1 for neighbors of that node.
// if indegree of that neighbor becomes 0, push it into queue.

// NOTE: we don't need to use "visited" vector for BFS in this case bcoz it is a DAG

// To check if graph is DAG or not:
// if size of the final "result" vector == V (no. of nodes in original graph) --> graph is DAG, 
// else cycle exists in graph due to which topo sort couldn't be performed.

#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v); // as it is a directed graph, u-->v
    }

    void topoSort() {
        vector<int> result;

        // calc indegree
        vector<int> indegree(V, 0); // initialized with 0

        for(int u=0; u<V; u++) {
            for(int v : l[u]) {
                indegree[v]++; // as it is u-->v so indegree of v becomes +1
            }
        }

        // add 0 indegree nodes to queue
        queue<int> q;
        
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        // BFS
        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            for(int v : l[curr]) {
                indegree[v]--; 

                if(indegree[v] == 0) q.push(v); // add neighbor to queue if its indegree becomes 0
            }
        }

        cout << "Topological Sorted Order:\n";
        for(int val : result) cout << val << " ";
    }
};

int main() {
    Graph g(6);

    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(5, 0);
    g.addEdge(5, 2);

    g.topoSort();

    return 0;
}