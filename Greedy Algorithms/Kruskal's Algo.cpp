// Kruskal’s Algorithm for Minimum Spanning Tree 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// struct to represent an edge
struct Edge
{
    int u,v,w; // u----v edge and 'w' is weight
};

// Comparator function to sort edges by weight in ascending order
// tells sort() on what basis the edges should be ordered.
bool compare(Edge a, Edge b)
{
    return a.w < b.w;
}

// Disjoint Set Union (DSU) or Union–Find
// to check whether two vertices belong to the same connected component, prevent cycles in the MST.
int findParent(int node, vector<int>& parent)
{
    if(parent[node] != node) // If node is not its own parent, it means- node is not the root.
    {
        parent[node] = findParent(parent[node], parent); // find the parent of the parent
    }
    return parent[node]; // node is the root, stop recursion.
}

// merge (unite) two disjoint sets.
// Here, Rank is an approximation of tree height. Keeps the DSU tree short and balanced for faster operations.
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank)
{
    // We do not directly attach u to v, we always attach root to root.
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    // If different roots -> merge them
    if(rootU != rootV)
    {
        if(rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;  // Smaller tree goes under bigger tree.
        }
        else if(rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else // rank[rootU] == rank[rootV]
        {
            // When both trees have same height, attach one under the other.
            parent[rootV] = rootU;
            rank[rootU]++; // Increase rank of the new root (height increases by 1)
        }
    }
}

int main()
{
    int V = 6; // 6 vertices

    vector<Edge> edges = {
        {0, 1, 7},
        {0, 2, 8},
        {1, 3, 5},
        {1, 2, 3},
        {2, 4, 3},
        {2, 3, 6},
        {3, 4, 2},
        {3, 5, 4},
        {4, 5, 2}
    };

    int E = edges.size();
    
    // sort edges by weight on the basis of the custom comparator
    sort(edges.begin(), edges.end(), compare); 

    vector<int> parent(V); // parent[i] stores the parent of vertex i
    vector<int> rank(V, 0);

    for(int i=0; i<V; i++)
    {
        parent[i] = i; // Make each vertex its own parent
    }
    
    int mstWeight = 0; // Keeps track of the sum of weights of selected edges.
    vector<Edge> mst; // Stores the actual edges chosen for MST.

    // Kruskal's Algo
    for(int i = 0; i<E && mst.size() < V-1; i++) 
    // mst.size() < V - 1 means, MST needs exactly V − 1 edges --> Stops early once MST is complete (efficient)
    {
        // edges[i] is the smallest available edge
        int u = edges[i].u; 
        int v = edges[i].v;
        int w = edges[i].w;

        if(findParent(u, parent) != findParent(v, parent)) // If u and v belong to different sets, adding this edge will NOT create a cycle.
        {
            mst.push_back(edges[i]);
            mstWeight += w;
            unionSets(u, v, parent, rank); // Combines the two components
        }
    }

    cout << "\nEdges in MST:\n";
    for(auto e : mst)
    {
        cout << e.u << " --- " << e.v << " (" << e.w << ")\n";
    }

    cout << "\nTotal weight of MST = " << mstWeight << endl;

    return 0;
}

