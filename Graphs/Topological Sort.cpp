// #newnotes
// Topological sorting
// Using DFS

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V;
    list<int>* l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) // for directed graph
    {
        l[u].push_back(v);
    }

    void printAdjList()
    {
        for(int i=0; i<V; i++)
        {
            cout << i << " : ";
            for(int neigh : l[i])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // contains core logic for topological sorting using DFS
    void DFS(int curr, vector<bool>& vis, stack<int>& s)
    {
        vis[curr] = true;

        // neighbors of "curr"
        for(int v : l[curr])
        {
            if(!vis[v]) // if neighbor is unvisited
            {
                DFS(v, vis, s);
            }
        }
        s.push(curr); // the order inside stack will be the req. topological sort order
    }

    void topologicalSort()
    {
        vector<bool> vis(V, false);
        stack<int> s;

        // we may have disconnected graphs, so run this loop
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                DFS(i, vis, s);
            }
        }

        // now stack contains the topological sort order --> so print el of stack
        while(s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    // TC = O(V+E)
};

int main()
{
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);

    g.printAdjList();

    cout << "Topological Sort order = "; // 5 4 2 3 1 0 
    g.topologicalSort();

    return 0;
}
