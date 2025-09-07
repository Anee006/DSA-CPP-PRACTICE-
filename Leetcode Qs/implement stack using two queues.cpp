//IMPLEMENT STACK USING TWO QUEUES

//Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack 
//(push, top, pop, and empty).

//Input:
/*
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]

Output:[null, null, null, 2, 2, false]

Explanation:
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*/

//LOGIC:
//create two queues- q1 and q2.
//q1 will be the primary data structure and q2 will be the helper data structure.
//map the elements in such a way that the front element of queue becomes the top element of the stack.
//So, for top(), top = q1.front()
//And, for pop() do q1.pop(), (as our front el which will be the top el for stack exists in q1).

//STEPS TO IMPLEMENT push(int x):
//1. Copy elements of q1 into q2. So now, q1 becomes empty.
//2. q1.push(data).
//3. copy elements of q2 back to q1.

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    MyStack()
    {
    }

    //Pushes element x to the top of the stack. //TC = O(n)
    void push(int x)
    {
        //copy all elements of q1 to q2.
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        //push el into q1
        q1.push(x);

        //copy elements of q2 back to q1.
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    //Removes the element on the top of the stack and returns it. //TC = O(1)
    int pop()
    {
        int ans = q1.front(); //storing the el we need to pop as we need to return it later
        q1.pop();
        return ans;
    }

    //Returns the element on the top of the stack. //TC = O(1)
    int top()
    {
        return q1.front();
    }

    //Returns true if the stack is empty, false otherwise. //TC = O(1)
    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyStack* s = new MyStack();
    s->push(1);
    s->push(2); //is the top el
    cout << s->top() << endl;
    cout << s->empty() << endl;

    return 0;

}