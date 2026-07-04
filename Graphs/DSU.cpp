// Disjoint Set Union or Union-Find

// DSU is used to track those elements that are in non-overlapping (disjoint) sets.

// DSU Functions:
// 1. Union(a,b) --> merge 2 sets 'a' and 'b'
// 2. Find(x) --> returns the parent of the set in which 'x' belongs to

// WORKING:
// We assign a parent to each set which is used to represent that set.
// When we try to union (merge) 2 sets together, we try to put the set with lower rank (priority or height) below the set with higher rank.
// The parent of the new merged set will be the parent which belongs to the set having higher rank.

// We use Path Compression as an optimization in "find" fn.
// We try to reduce the depth of the tree so that find fn can find the parent faster.
// In practical case, Path Compression makes the TC of "union" and "find" fn as O(1).

#include <iostream>
#include <vector>
using namespace std;

class DisjointSetUnion { 
public:

    int n;
    vector<int> parent, rank;

    DisjointSetUnion(int n) {
        this->n = n;

        for(int i=0; i<n; i++) {
            parent.push_back(i); // each element will be its own parent
            rank.push_back(0); 
        }
    }

    void unionByRank(int a, int b) {
        int parA = find(a); // parent of A
        int parB = find(b); // parent of B

        if(parA == parB) return; // both elements belong to the same set 

        if(rank[parA] == rank[parB]) { // either of 'a' or 'b' can be the parent
            parent[parB] = parA; // 'a' is the parent of 'b'
            rank[parA]++; // height of 'a' increases
        }

        else if(rank[parA] > rank[parB]) {
            parent[parB] = parA; // b comes under a
        }

        else parent[parA] = parB; // a comes under b
    }

    int find(int x) {
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]); // path compression
    }

    // additional fn
    void getInfo() {
        for(int i=0; i<n; i++) cout << parent[i] << " ";
        cout << endl;

        for(int i=0; i<n; i++) cout << rank[i] << " ";
        cout << endl;
    }
};

int main() {
    DisjointSetUnion dsu(6); // there will be 6 elements

    dsu.unionByRank(0,2);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(0,4);

    dsu.getInfo();

    return 0;
}

// TC = O(n)
// SC = O(n)