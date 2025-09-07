// #notes
//STOCK SPAN PROBLEM 
//using stack

//prices = [100, 80, 60, 70, 60, 75, 85]

//for the given stock prices, we need to return the span for each day:
//ans = [1, 1, 1, 2, 1, 4, 6]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main()
{
    //given prices vector:
    vector <int> prices = {100, 80, 60, 70, 60, 75, 85};

    vector <int> ans(prices.size(), 0); // to store the span for each day //the size of "ans" is same as that of "prices" and initialised it with 0
    stack <int> s;

    for(int i=0; i<prices.size(); i++)
    {
        //to find "prevHigh", pop the smaller values from the stack as our stack should only contain values greater than current day.
        //the while loop removes values <= current from stack:
        while(s.size() > 0 && prices[s.top()] <= prices[i]) //s.top() gives an idx, to find the value it stores write: prices[s.top()]
        {
            s.pop();
        }

        if(s.size() == 0) //stack becomes empty //i.e, if no prevHigh exists
        {
            ans[i] = i + 1; //ans[i] means span value
        }
        else //the idx at top is that of the val greater than current
        {
            ans[i] = i - s.top(); //calculating span value
            //s.top() is the prevHigh value
        }

        s.push(i);
    }

    //to print ans:
    for(int val: ans)
    {
        cout << val << "\t";
    }
    cout <<endl;

    return 0;
}

//TC = O(n)
//SC = O(n)  ,[due to the extra stack used, we can ignore the ans vector here]