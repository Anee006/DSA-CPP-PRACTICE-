// Disjoint Set Union or Union-Find

// DSU is used to track those elements that are in non-overlapping (disjoint) sets.

// DSU Functions:
// 1. Union(a,b) --> merge 2 sets 'a' and 'b'
// 2. Find(x) --> returns the parent of the set in which 'x' belongs to

// WORKING:
// We assign a parent to each set which is used to represent that set.
// When we try to union (merge) 2 sets together, we try to put the set with lower rank (priority or height) below the set with higher rank.
// The parent of the new merged set will be the parent which belongs to the set having higher rank.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    DisjointSetUnion dsu(6); // there will be 6 elements

    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);

    cout << dsu.find(2) << endl;

    dsu.unionByRank(0,4);

    return 0;
}