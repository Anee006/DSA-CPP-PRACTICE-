//BUY AND SELL STOCK PROBLEM

//Input: prices = [7,1,5,3,6,4]. These are the stock prices that we have been given.
//7 is the stock price on day 1, 1 is the stock price on day 2 and so on...

//You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
//Return the maximum profit you can achieve from this transaction.
//Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

//In this case, the output will be 5.
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

//If the price keeps on decreasing everyday, we will never get any profit, as the profit will be -ve, so in such cases return 0 profit.

#include <iostream>
#include <vector>
using namespace std;

//consider everyday as selling day. And then try to imagine which day would have been the best to buy the stock 
//(the day on which the price is least would have been the best day to buy stock).

//So, for any index "i" , the min value from index 0 to i-1, will be the best day to buy or bestBuy.

//idx=0 can never be the selling day, as we need to buy the stock first. so the loop starts from idx=1.
//If price[i]<=bestBuy, then we won't get any profit, so do nothing in this case other than updating bestBuy.

int maxProfit( vector <int>& prices)
{
    int max_Profit=0;
    int bestBuy= prices[0]; //asuming that the price on day 1 is our best buy (for now).

    for(int i=1; i<prices.size(); i++)
    {
        if(prices[i]>bestBuy) //means profit can be found
        {
            max_Profit= max(max_Profit, prices[i]-bestBuy); //"prices[i]-bestBuy" is the current day profit
        }

        bestBuy= min(bestBuy, prices[i]); //checking for which day is the best to buy the stock
    }
    return max_Profit;
}
//Time complexity for this is o(n).

int main()
{
    vector <int> prices= {7,1,5,3,6,4};

    cout<<"Max profit: "<<maxProfit(prices)<<endl;
    return 0;
}