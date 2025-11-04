//In max priority queue, elements are placed in decreasing order of their values and the first
//element represents the largest of all the inserted elements.

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue <int> p;

    p.push(100); //inserts element at end of queue
    p.push(90);
    p.emplace(80);
    p.emplace(70);

    cout<<"top element of queue is: "<<p.top()<<endl; //prints 100

    //to print the heap elements:
    while(!p.empty())
    {
        cout << p.top() << "\t";
        p.pop();  //pop deletes first element of queue 
    }
    cout << endl;

    return 0;
}

