// Leetcode 2073

// There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back 
// of the line. You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is 
// tickets[i]. Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the 
// line in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

// Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.

/*
Input: tickets = [2,3,2], k = 2
Output: 6

Explanation:
The queue starts as [2,3,2], where the kth person is underlined.
After the person at the front has bought a ticket, the queue becomes [3,2,1] at 1 second.
Continuing this process, the queue becomes [2,1,2] at 2 seconds.
Continuing this process, the queue becomes [1,2,1] at 3 seconds.
Continuing this process, the queue becomes [2,1] at 4 seconds. Note: the person at the front left the queue.
Continuing this process, the queue becomes [1,1] at 5 seconds.
Continuing this process, the queue becomes [1] at 6 seconds. The kth person has bought all their tickets, so return 6.
*/

// LOGIC:
// Find: How many times will each person buy before person k finishes?
// Before person "k" finishes:
// - Everyone before or at k can buy at most tickets[k] tickets.
// - Everyone after k can buy at most tickets[k] - 1 tickets, bcoz process stops when k buys their last ticket.
// For indices i <= k: contribution = min(tickets[i], tickets[k]), bcoz they can buy in the same round as k.
// For indices i > k: contribution = min(tickets[i], tickets[k]-1), bcoz k finishes before they get their final chance.

#include <iostream>
#include <queue>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;

    for(int i = 0; i < tickets.size(); i++) {
        if(i <= k) time += min(tickets[i], tickets[k]);

        else time += min(tickets[i], tickets[k] - 1);
    }
    return time;
}

int main() {
    vector<int> tickets = {2, 3, 2};
    int k = 2;

    cout << timeRequiredToBuy(tickets, k);

    return 0;
}

// TC = O(n)
// SC = O(1)