//To remove cycle from a linked list
//using slow-fast pointer approach

//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
//Note that pos is not passed as a parameter.

//Input: head = [3,2,0,-4], pos = 1

//Input: head = [1], pos = -1

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

//to print the list
void printList(Node* head)
{    
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//to remove cycle from the linked list
Node* detectCycle(Node* head)
{
    Node* slow = head; //slow ptr
    Node* fast = head; //fast ptr

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next; //to detect if cycle is present

        if (slow == fast) //means cycle is present
        {
            slow = head; //to find start of the cycle

            // If the cycle starts at head
            if (slow == fast)
            {
                while (fast->next != slow)
                    fast = fast->next;

                fast->next = NULL; // Break the cycle
                return slow;
            }

            // If cycle starts somewhere else
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL; // Break the cycle
            return slow->next; // Start of cycle
        }
    }
    return NULL;
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

    if (detectCycle(head))
        cout << "Cycle detected and removed successfully." << endl;

    else
        cout << "No cycle detected." << endl;
        
    printList(head); // Should print linear list after cycle removal

    
    
    return 0;
}
