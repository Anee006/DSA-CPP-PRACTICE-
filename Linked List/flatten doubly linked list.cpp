// #notes
//FLATTEN MULTILEVEL DOUBLY LINKED LIST 
//using recursion

//You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This 
//child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or 
//more children of their own, and so on, to produce a multilevel data structure.

//Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. 
//Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

//Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

//Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
//Output: [1,2,3,7,8,11,12,9,10,4,5,6]

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node* child; //child ptr

        Node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
            child = NULL;
        }
};

//to flatten the multilevel list;
Node* flatten(Node* head)
{
    //base case
    if(head == NULL)
    {
        return head;
    }

    Node*curr = head; //to access each node of doubly linked list

    while(curr != NULL)
    {
        if(curr->child != NULL) //means a valid child node exists
        {
            //to flatten the child nodes
            Node* next = curr->next; //points to the node after curr
            curr->next = flatten(curr->child);  //curr->child becomes the head for the recursive call

            curr->next->prev = curr; //to establish the backward connection of the flattened list
            curr->child = NULL; //we can now remove the child node

            //to find tail of linked list
            while(curr->next != NULL)
            {
                curr = curr->next;
            }

            //to attach tail with next ptr
            if(next != NULL)
            {
                curr->next = next; //to establish forward connection
                next->prev = curr;  //to establish backward connection
            }
        }

        curr = curr->next; //if no valid child node exists
    }
    return head;
}

//to print the flattened list:
void printFlattenedList(Node* head)
{
    Node* curr = head;
    while (curr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

//to create a multilevel doubly list;
Node* createMultiLevelList()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);
    Node* seventh = new Node(7);
    Node* eight = new Node(8);
    Node* ninth = new Node(9);
    Node* tenth = new Node(10);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    third->child = sixth;

    sixth->next = seventh;
    seventh->prev = sixth;

    seventh->next = eight;
    eight->prev = seventh;

    seventh->child = ninth;

    ninth->next = tenth;
    tenth->prev = ninth;

    return head;
}


int main()
{
    Node* head = createMultiLevelList();

    head = flatten(head); // Call your flatten function here

    cout << "Flattened List: ";
    printFlattenedList(head);

    return 0;
}

//TC = O(n)
//SC = O(1)
