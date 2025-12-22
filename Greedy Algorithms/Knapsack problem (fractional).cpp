// FRACTIONAL KNAPSACK PROBLEM (using Greedy Approach)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int profit, weight;
    double ratio;
};

// Comparator function to sort items by profit/weight ratio
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio; // to sort in desc order
}

double knapsack(int M, vector<Item>& items)
{
    // Sort items by profit/weight ratio in decreasing order
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;

    for(auto item : items)
    {
        if(M == 0) break; 

        if(item.weight <= M)
        {
            // take the whole item
            totalProfit += item.profit;
            M -= item.weight; // update knapsack capacity
        }
        else
        {
            // take the fraction of the item
            totalProfit += item.ratio * M;
        }
    }
    return totalProfit;
}

int main()
{
    int n = 7; // no. of items in knapsack

    int M = 15; // knapsack capacity

    vector<Item> items = {
        {10, 2}, // profit = 10, weight = 2
        {5, 3},
        {15, 5},
        {7, 7},
        {6, 1},
        {18, 4},
        {3, 1},
    };

    // calc profit/weight ratio
    for(auto &item: items)
    {
        item.ratio = (double)item.profit / item.weight;
    }

    cout << "Max Profit = " << knapsack(M, items) << endl;

    return 0;
}

// TC = O(n log n)