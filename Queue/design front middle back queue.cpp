// Leetcode 1670
// using two deques

/*
Design a queue that supports push and pop operations in the front, middle, and back.

Implement the FrontMiddleBack class:
FrontMiddleBack() Initializes the queue.
void pushFront(int val) Adds val to the front of the queue.
void pushMiddle(int val) Adds val to the middle of the queue.
void pushBack(int val) Adds val to the back of the queue.
int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.

When there are two middle position choices, the operation is performed on the frontmost middle position choice.
E.g: Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
*/

// LOGIC:
// If we have a queue: [1 2 3 4 5 6] then instead of storing it in 1 deque, we use 2 deques: left = [1 2 3], right = [4 5 6].
// queue = left + right. The middle will be at the "end of left deque".
// Always keep: left.size() == right.size() OR left.size() == right.size() + 1.
// After every operation (push, pop), balance the size.
// If left becomes big --> move element to front of right.
// If right becomes big --> move element to back of left.

#include <iostream>
#include <deque>
using namespace std;

class FrontMiddleBackQueue {
    deque<int> left, right;

    void balance() {
        if(left.size() > right.size() + 1) { // left can have at most 1 extra element than right
            right.push_front(left.back()); // adjust the extra element by adding it at front of right
            left.pop_back(); // pop the extra element from left
        }

        else if(left.size() < right.size()) {
            left.push_back(right.front()); // add the extra element at back of left
            right.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) { // TC = O(1)
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) { // TC = O(1)
        if(left.size() > right.size()) { // push new element in front of right (middle)
            right.push_front(left.back());
            left.pop_back();
        }

        left.push_back(val); // push element at end of left (middle)
    }

    void pushBack(int val) { // TC = O(1)
        right.push_back(val);
        balance();
    }

    int popFront() { // TC = O(1)
        if(left.empty() && right.empty()) return -1;

        int ans = left.front(); // element at front of queue
        left.pop_front(); 
        balance();
        return ans;
    }

    int popMiddle() { // TC = O(1)
        if(left.empty() && right.empty()) return -1;

        int ans = left.back(); // middle element = back of left --> removes the front-most middle (if there are 2 middles)
        left.pop_back();
        balance();
        return ans;
    }

    int popBack() { // TC = O(1)
        if(left.empty() && right.empty()) return -1;

        int ans;

        if(!right.empty()) {
            ans = right.back();
            right.pop_back();
        }

        else {
            ans = left.back();
            left.pop_back();
        }

        balance();
        return ans;
    }
};

int main() {
    FrontMiddleBackQueue* q = new FrontMiddleBackQueue();

    q->pushFront(1);   // [1]
    q->pushBack(2);    // [1, 2]
    q->pushMiddle(3);  // [1, 3, 2]
    q->pushMiddle(4);  // [1, 4, 3, 2]
    cout << q->popFront() << endl;     // return 1 -> [4, 3, 2]
    cout << q->popMiddle() << endl;    // return 3 -> [4, 2]
    cout << q->popMiddle() << endl;    // return 4 -> [2]
    cout << q->popBack() << endl;      // return 2 -> []
    cout << q->popFront() << endl;     // return -1 -> [] (The queue is empty)

    return 0;
}

// SC = O(n)