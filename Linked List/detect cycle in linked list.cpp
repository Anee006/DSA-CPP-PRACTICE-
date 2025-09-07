// #notes
//DETECT CYCLE IN A LINKED LIST 
//LINKED LIST CYCLE (on leetcode)
//using slow-fast pointer approach

//Given head, the head of a linked list, determine if the linked list has a cycle in it.
//Return true if there is a cycle in the linked list. Otherwise, return false.

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

//Input: head = [3,2,0,-4], pos = 1
//Output: true
//Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

//Input: head = [1], pos = -1
//Output: false
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

//to detect cycle in linked list
bool hasCycle(Node* head)
{
    Node* slow = head; //slow ptr
    Node* fast = head; //fast ptr

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next; //slow moves by +1
        fast = fast->next->next; //fast moves by +2

        if(slow == fast) //means cycle exists in the linked list
        {
            return true;
        }
    }
    return false; //if after coming out of loop slow is still not equal to fast, means cycle not present
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
    if(hasCycle(head))
    {
        cout << "Cycle detected in linked list" <<endl;
    }
    else
    {
        cout << "No cycle detected in the list" <<endl;
    }

    //-------------------------------------------------------------------------------
    Node* Head = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);

    Head->next = two;
    two->next = three;

    //checking for cycle:
    if(hasCycle(Head))
    {
        cout << "Cycle detected in linked list" <<endl;
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