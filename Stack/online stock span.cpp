// Leetcode 901

// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which 
// the stock price was less than or equal to the price of that day.

// For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 
// because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.

// LOGIC:
// Store pairs of (price, span) in the stack
// For every new pair, initialize span = 1
// While: (stack is not empty) && (stack.top().price <= current price) --> add top's span to current span --> pop the element
// Push (price, span) into stack

#include <iostream>
#include <stack>
using namespace std;

class StockSpan {
private:
    stack<pair<int, int>> s; // stores {price, span}
 
public:
    StockSpan() {}

    // "next" returns the span of the stock's price given that today's price is "price"
    int next(int price) {
        int span = 1;

        while(!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }
        
        s.push({price, span});
        return span;
    }
};

int main() {
    StockSpan* spanner = new StockSpan();
    cout << spanner->next(100) << endl; // return 1
    cout << spanner->next(80) << endl;  // return 1
    cout << spanner->next(60) << endl;  // return 1
    cout << spanner->next(70) << endl;  // return 2
    cout << spanner->next(60) << endl;  // return 1
    cout << spanner->next(75) << endl;  // return 4
    
    return 0;
}

// Total TC = O(n) for n calls
// Amortized TC per next() = O(1)
// SC = O(n) --> after n calls, stack can contain n elements