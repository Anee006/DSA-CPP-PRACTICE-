//to build max priority queue (i.e, for max heap)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue <int> p;

    //to insert elements in priority_queue:
    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    //to find size of priority_queue:
    cout << "Size: " << p.size() << endl;

    //to find the element at top of heap -->should give the max element of heap
    cout << "\nMax element: " << p.top() << endl; //prints 20

    //to delete an element from heap
    p.pop(); //pops 20
    cout << "Max element: " << p.top() << endl; //prints 18

    return 0;
}