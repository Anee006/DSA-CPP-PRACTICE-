#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> coins = {1,2,5,10};
    int amount = 28;

    sort(coins.rbegin(), coins.rend()); // sort in desc order

    for(int coin : coins) {
        while(amount >= coin) {
            cout << coin << " ";
            amount -= coin;
        }
    }

    return 0;
}

// TC = O(nlog n + k), where n = number of coin types , k = number of coins used