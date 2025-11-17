// Kruskal's algorithm for finding the Minimum Spanning Tree (MST).

// Kruskal's algorithm is a "Greedy" algorithm. It builds the MST by always picking the smallest available edge in the entire graph, 
// as long as that edge doesn't form a loop (cycle).

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

// to represent a weighted edge in the graph
struct Edge
{
    int src, dest, weight;
};

// We need to pick edges, but we cannot pick an edge if it connects two nodes that are already connected (that would create a cycle).
// create a Disjoint Set Union (DSU) data structure (also known as Union-Find).
struct  DSU
{
    int* parent;

    DSU(int V)
    {
        parent = new int[V];

        // Initially, every vertex is its own parent
        for(int i=0; i<V; i++)
        {
            parent[i] = i;
        }
    }

    // Destructor to free memory
    ~DSU()
    {
        delete[] parent;
    }

    // Finds the root of the set that 'i' belongs to
    int find(int i)
    {
        if(parent[i] == i) // If i is the parent of itself, then it is the root
        {
            return i;
        }

        // Recursively find the root
        return parent[i] = find(parent[i]);
    }

    // Union operation
    // Merges the sets containing x and y
    void unite(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);

        // If they are not already in the same set, merge them
        if(root_x != root_y)
        {
            parent[root_x] = root_y; // Make one root parent of the other
        }
    }
};

// Comparison function to sort edges by their weight
bool compareEdges(const Edge& a, const Edge& b)
{
    return a.weight < b.weight;
}

class Graph
{
    int V; // no. of vertices

    list<pair<int, int>>* l; // Adjacency list: list of (neighbor, weight) pairs

    vector<Edge> edgeList; // Vector to store all edges for Kruskal's algorithm

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<pair<int,int>> [V];
    }

    ~Graph()
    {
        delete[] l;
    }

    // Add a weighted, undirected edge
    void addEdge(int u, int v, int w)
    {
        // Add to adjacency list
        l[u].push_back({v,w});
        l[v].push_back({u,w});

        // Add to the edge list for Kruskal's
        edgeList.push_back({u,v,w});
    }

    // Print the (now weighted) Adjacency List
    void printAdjList()
    {
        cout << "Adjacency List:\n";
        for(int i=0; i<V; i++)
        {
            cout << i << " : ";
            for(auto neighbor: l[i])
            {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Kruskal's algorithm to find MST
    int kruskal_mst()
    {
        // 1. sort all edges from lowest weight to highest weight.
        sort(edgeList.begin(), edgeList.end(), compareEdges);

        // 2. Initialize DSU
        DSU dsu(V);

        int mst_cost = 0;
        int edges_in_mst = 0;

        cout << "Edges included in MST:" << endl;

        // 3. Iterate through all sorted edges
        for(auto edge : edgeList)
        {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;

            // 4. Check if adding this edge forms a cycle
            int root_u = dsu.find(u);
            int root_v = dsu.find(v);

            // If roots are different, it's a safe edge (no cycle)
            if(root_u != root_v)
            {
                // 5. Include this edge in MST
                cout << u << " - " << v << " (weight: " << w << ")" << endl;
                mst_cost += w;
                edges_in_mst++;

                // 6. Union the two sets
                dsu.unite(u,v);
            }

            // Optimization: A tree with V vertices always has exactly V-1 edges. 
            // Once we reach that count, the tree is complete. We stop the loop to save time.
            if(edges_in_mst == V-1)
            {
                break;
            }
        }
        return mst_cost;
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 20);

    g.printAdjList();

    int mst_cost = g.kruskal_mst();
    cout << "\nTotal cost of MST = " << mst_cost << endl;

    return 0;
}