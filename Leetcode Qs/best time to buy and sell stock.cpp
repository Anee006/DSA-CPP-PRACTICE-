// Leetcode 121

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

// If the price keeps on decreasing everyday, we will never get any profit, as the profit will be -ve, so in such cases return 0 profit.

// LOGIC: 
// consider everyday as selling day. And then try to imagine which day would have been the best to buy the stock 
// (the day on which the price is least would have been the best day to buy stock).
// So, for any index "i" , the min value from index 0 to i-1, will be the best day to buy or bestBuy.
// idx=0 can never be the selling day, as we need to buy the stock first. so the loop starts from idx=1.
//If price[i]<=bestBuy, then we won't get any profit, so do nothing in this case other than updating bestBuy.

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int max_Profit = 0;
    int bestBuy = prices[0]; // asuming that the price on day 1 is our best buy (for now).

    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] > bestBuy) { // means profit can be found
            max_Profit = max(max_Profit, prices[i] - bestBuy); // "prices[i]-bestBuy" is the current day profit
        }
        bestBuy = min(bestBuy, prices[i]); // checking for which day is the best to buy the stock
    }
    return max_Profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    cout << "Max profit: " << maxProfit(prices) << endl;
    return 0;
}

// TC = O(n)