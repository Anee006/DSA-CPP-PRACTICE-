//MIN STACK

//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

//Implement the MinStack class:
/*
1. MinStack() initializes the stack object.
2. void push(int val) pushes the element val onto the stack.
3. void pop() removes the element on the top of the stack.
4. int top() gets the top element of the stack.
5. int getMin() retrieves the minimum element in the stack.
*/

//You must implement a solution with O(1) time complexity for each function.

/*
Input=
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output=
[null,null,null,null,-3,null,0,-2]

Explanation:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/


//LOGIC:
//create stack <pair<int, int>>. 
//the minValue gets updated each time we find a val which is smaller than the current el. 

#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class MinStack
{
    public:
    stack <pair<int,int>> s; //the first int i.e "val" stores the values normally in the stack, the second int stores "minValue" in the stack.
        MinStack()
        {

        }

        void push(int val)
        {
            if(s.empty()) //if stack is empty
            {
                s.push({val, val}); //current el will be the minValue in the beginning since, its the first el of stack
            }
            else
            {
                int minValue = min(val, s.top().second); //s.top().second means the "minValue" that we had stored in the pair. //the value at top gives us the current minValue present in the stack.
                //whichever of the two values- the current el or the minValue we had stores, is smaller, that value becomes the new minValue.

                s.push({val, minValue});
            }
        }

        void pop()
        {
            s.pop();
        }

        int top()
        {
            return s.top().first; //s.top().first returns the value that we had stored in the pair
        }

        int getMin()
        {
            return s.top().second; //returns the minValue present in the stack
        }
};

int main()
{
    MinStack * obj = new MinStack();
    obj ->push(-2);
    obj ->push(-0);
    obj ->push(-3);
    int minElement = obj->getMin();
    obj->pop();
    int top = obj->top();
    int min = obj->getMin();

    cout << "MinVal = " << minElement << endl << "Top Element = " << top << endl << "MinVal = " << min << endl;
    return 0;
}

//TC = O(1)
//SC = O(n) 
//actually SC = O(2 * n) because in each push operation we are pushing double values (val and minValue) into the stack.