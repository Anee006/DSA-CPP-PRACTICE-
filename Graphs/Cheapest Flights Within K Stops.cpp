// Leetcode 787

// There are n cities connected by some number of flights. You are given an array flights where 
// flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
// If there is no such route, return -1.

/*
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The optimal path with at most 1 stop from city 0 to 3 has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

#include <iostream>
#include <vector>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
}

int main() {
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int n = 4, src = 0, dst = 3, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}