//LINKED LIST CYCLE II (on leetcode)
//To find the "start" of a cycle in a linked list
//using slow-fast pointer approach

//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
//Do not modify the linked list.

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
//Note that pos is not passed as a parameter.

//Input: head = [3,2,0,-4], pos = 1
//Output: tail connects to node index 1
//Explanation: There is a cycle in the linked list, where tail connects to the second node.

//Input: head = [1], pos = -1
//Output: no cycle
//Explanation: There is no cycle in the linked list.
 

//TC = O(n)
//SC = O(1)
 
#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

//to detect starting node of the cycle in linked list
Node* detectCycle(Node* head)
{
    Node* slow = head; //slow ptr
    Node* fast = head; //fast ptr

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next; //slow moves by +1
        fast = fast->next->next; //fast moves by +2

        if(slow == fast) //means cycle is present
        {
            slow = head; //reinitialise slow
            while(slow != fast)
            {
                slow = slow->next; //updating both slow and fast by +1
                fast = fast->next;
            }
            return slow; //can also return fast here, as slow and fast both point to same node
            //returns the position of start of the cycle
        }
    }
    return NULL; //means no cycle is present, so start value is NULL
}


int main()
{
    //creating nodes:
    Node* head = new Node(3);
    Node* second = new Node(2); //pos = 1
    Node* third = new Node(0);
    Node* fourth = new Node(-4);

    //linking nodes normally:
    head->next = second;
    second->next = third;
    third->next = fourth;

    //creating a cycle from fourth to second node (as given in Q)
    fourth ->next = second;

    //checking for cycle:
    Node* start = detectCycle(head);
    if(start != NULL)
    {
        cout<<"cycle is detected at node with value: " << start->data <<endl;
    }
    else
    {
        cout<<"No cycle detected." <<endl;
    }
    cout<<endl;

    //-------------------------------------------------------------------------------
    Node* Head = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);

    Head->next = two;
    two->next = three;

    //checking for cycle:
    Node* s = detectCycle(Head);
    if(s != NULL)
    {
        cout<<"cycle is detected at node with value: " << s->data <<endl;
    }
    else
    {
        cout << "No cycle detected in the list" <<endl;
    }
    
    return 0;
}
//NOTE:
//You can't print a list with a cycle in a normal loop — it will result in an infinite loop.
//So, while printing, you have to limit the number of nodes you print or detect the cycle.