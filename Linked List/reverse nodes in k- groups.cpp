//REVERSE NODES IN K-GROUPS
//using recursion

//Given the head of a linked list, reverse the nodes of the list, k at a time, and return the modified list.
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then 
//left-out nodes, in the end, should remain as it is.

//NOTE: You may not alter the values in the list's nodes, only nodes themselves may be changed.

//Input: head = [1,2,3,4,5], k = 2
//Output: [2,1,4,3,5]

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


//to reverse nodes , according to k value:
Node* reverseKGroup(Node* head, int k)
{
    Node* temp = head;
    int count = 0;

    //to check if k nodes exist:
    while(count < k)
    {
        if(temp == NULL) //means k nodes do not exist
        {
            return head;
        }
        temp = temp->next; //keep moving temp one node forward if k nodes exist
        count++;
    }

    //recursively call for rest of the LL
    Node* prevNode =  reverseKGroup(temp, k); //temp is passed as the head

    //to reverse current group (i.e, the first k group for which we counted)
    temp = head;
    count = 0;

    while(count < k)
    {
        Node* next = temp->next;
        temp->next = prevNode;

        prevNode = temp; //to reverse the next node of the current group
        temp = next;   //to connect the rest of the node to the current group

        count++;
    }
    return prevNode; //this is the new head of the list
}

//to print the reversed list:
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout <<temp->data <<" -> ";
        temp = temp->next;
    }
    cout<<"NULL" <<endl;
}


int main()
{
    //creating the list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2; //to reverse in groups of 2

    cout<<"Original list: ";
    print(head);
    cout<<endl;

    head = reverseKGroup(head, k);

    cout<<"List after reversing in groups of " << k <<": ";
    print(head);

    return 0;
}

//TC = O(n)
//SC = O(1)