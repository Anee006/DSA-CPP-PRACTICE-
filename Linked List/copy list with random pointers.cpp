//COPY LIST WITH RANDOM POINTERS

//A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

//Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value 
//of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that 
//the pointers in the original list and copied list represent the same list state. 
//None of the pointers in the new list should point to nodes in the original list.

//Return the head of the copied linked list.

//Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* random;


        Node(int val)
        {
            data = val;
            next = NULL;
            random = NULL; //random node
        }
};

//to make deep copy of original list
Node* copyRandomList(Node* head)
{
    if(head == NULL) //means linked list is empty
    {
        return NULL;
    }

    unordered_map <Node* , Node*> m;

    Node* newHead = new Node(head->data); //newHead is a copy of the oldHead 
    m[head] = newHead; //bcoz the head node's mapping is required before setting random links.

    Node* oldTemp = head->next; //we have already made a copy of head hence, starting from head->next.
    Node* newTemp = newHead; //to track the copy list 

    while(oldTemp != NULL)
    {
        Node* copyNode = new Node(oldTemp->data); //making a simple copy of oldNode
        m[oldTemp] = copyNode; //to store the copy in the map as well

        newTemp->next = copyNode; //to establish connection b/w the nodes in the copy list

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    //to copy all the random connections
    oldTemp = head;
    newTemp = newHead;
    while(oldTemp != NULL)
    {
        newTemp->random = m[oldTemp->random]; //to make random connections

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;

    }
    return newHead;
}

//to print list with random connections:
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << "Node data: " << temp->data;

        if (temp->random) //if random connection exists
            cout << ", Random points to: " << temp->random->data;

        else //if no random connection
            cout << ", Random points to: NULL";
        cout << endl;

        temp = temp->next;
    }
}

int main()
{
    // Creating nodes
    Node* head = new Node(7);
    Node* second = new Node(13);
    Node* third = new Node(11);
    Node* fourth = new Node(10);
    Node* fifth = new Node(1);

    // Linking next pointers
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Setting random pointers:
    // head has no random ptr
    second->random = head;     // 13's random -> 7
    third->random = fifth;    // 11's random -> 1
    fourth->random = third;   // 10's random -> 11
    fifth->random = head;     // 1's random -> 7

    // Display the og list:
    cout << "Original List with Random Pointers:" << endl;
    printList(head);


    // Copy the list
    Node* newHead = copyRandomList(head);

    cout << "\nCopied List:" << endl;
    printList(newHead);

}

//TC = O(n)