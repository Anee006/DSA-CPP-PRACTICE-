//IMPLEMENT QUEUE USING TWO STACKS

//Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue 
//(push, peek, pop, and empty).

/* 
Input:
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]

Output = [null, null, null, 1, 1, false]

Explanation:
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

//LOGIC:
//create two stacks s1 and s2. s1 is the primary stack and s2 is the helper.
//map the top element of s1 so that it becomes the front el of the queue.
//so front() is, front = s1.top()

//STEPS TO IMPLEMENT push(int x):
//copy all elements of s1 to s2.
//s1.push(x)
//copy all elements of s2 back to s1.

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    stack <int> s1;
    stack <int> s2;

    MyQueue()
    {

    }

    //Pushes element x to the back of the queue. //TC = O(n)
    void push(int x)
    {
        //copy elements of s1 to s2:
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        //insert data in s1
        s1.push(x);

        //copy elements from s2 to s1:
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    //Removes the element from the front of the queue and returns it. //TC = O(1)
    int pop()
    {
        int ans = s1.top(); //to preserve the val of top
        s1.pop();
        return ans;
    }

    //Returns the element at the front of the queue. //TC = O(1)
    int peek()
    {
        return s1.top();
    }

    //Returns true if the queue is empty, false otherwise. //TC = O(1)
    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue* q = new MyQueue();
    q->push(1); //is front of the queue
    q->push(2); 
    cout << q->peek() << endl;
    cout << q->pop() << endl;
    cout << q->empty() << endl;


    return 0;
}