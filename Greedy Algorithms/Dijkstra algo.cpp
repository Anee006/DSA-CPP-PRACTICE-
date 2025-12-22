// DIJKSTRA ALGORITHM (for single source shortest path)
// used for non -ve (i.e, +ve) edge weights mostly.

// used to find the shortest path from source to all vertices for a weighted graph.

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
using namespace std;

class Edge
{
public:
    int v; // to store neighbors
    int w; // to store weights

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

// reconstruct the path from src to 'v'
void printPath(int v, vector<int>& parent)
{
    if(parent[v] == -1) // is a 'src' node
    {
        cout << v;
        return;
    }        

    printPath(parent[v], parent);
    cout << " -> " << v;
}

void dijkstra(int src, vector<vector<Edge>> g, int V)
{
    vector<int> dist(V, INT_MAX); // stores the shortest dis from src to each vertex. Initially, each dis is infinity.
    dist[src] = 0; // distance of src = 0

    vector<int> parent(V, -1); // parent[i] stores the previous vertex on the shortest path to i
 
    // in priority queue (min-heap), we store dis[u] before u, so that dis[u] has more priority. 
    // So now sorting happens on basis of dis[u] i.e, the shortest distance.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // stores <dis[u], u>.
    pq.push({0, src});

    while(pq.size() > 0)
    {
        int u = pq.top().second;  // to extract vertex
        pq.pop();

        // loop through neighbors of u
        for(Edge e : g[u])
        {
            // edge relaxation step:
            if(dist[u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[u] + e.w;
                parent[e.v] = u; // track the prev vertex
                pq.push({dist[e.v], e.v});
            }
        }
    }

    // shortest distance from src to each vertex
    for(int i=0; i<V; i++)
    {
        cout << "Shortest distance to " << i << " = " << dist[i] << " , Path: ";
        printPath(i, parent);
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int V = 6; // no. of vertices
    vector<vector<Edge>> g(V);

    // create directed edges
    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[3].push_back(Edge(5,1));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    

    dijkstra(0, g, V); // starting vertex = 0
    return 0;
}

/*
    TC = O((V+E) * log V),  where V = no. of vertices and E = no. of edges
    TC = O( (V* log V) + (E* log V) ), when we open the brackets in above step
    TC = O(E* log V), when we ignored (V* log V)
*/