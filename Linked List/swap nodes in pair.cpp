//SWAP NODES IN PAIRS

//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's 
//nodes (i.e., only nodes themselves may be changed.)

//Input: head = [1,2,3,4]
//Output: [2,1,4,3]

//Input: head = [1,2,3]
//Output: [2,1,3]

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

//to swap nodes in pairs:
Node* swapNodes(Node* head)
{
    //base case:
    if(head == NULL || head->next == NULL) //if no node exists or one node exists, in either case we will return head
    {
        return head; 
    }

    //creating prev, first and second pointer
    Node* first = head;
    Node* second = head->next;
    Node* prev = NULL;

    while(first != NULL && second != NULL) //both first and second should be valid nodes for it to be swapped
    {
        Node* third = second->next; //to preserve address of third node

        second->next = first; //to swap first and second nodes
        first->next = third;  //to make connection of first and third node, after swapping

        if(prev != NULL)
        {
            prev->next = second; //to make the connection of prev and second node after swapping first and second
        }
        else //means prev is NULL (happens at the beginning, when we run the loop for first time)
        {
            head = second; //second becomes the new head after swapping
        }

        //updations for next iterations
        prev = first;
        first = third;
        if(third != NULL)
        {
            second = third->next;
        }
        else //means if third points to NULL, we will point the second also to NULL, to stop swapping
        {
            second = NULL;
        }
    }

    return head;
}

//to print list:
void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{ 
    //list 1 :   1->2->3->4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout<<"List 1 before swapping: " ;
    print(head);
    cout<<endl;

    Node * newHead = swapNodes(head);
    cout<<"List 1 after swapping: ";
    print(newHead);

    //list 2: 1->2->3
    cout<<endl<<"-----------------------------------------------"<<endl <<endl;

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    cout<<"List 2 before swapping: ";
    print(head2);
    cout<<endl;

    Node* HEAD = swapNodes(head2);
    cout<<"List 2 after swapping: ";
    print(HEAD);
    cout <<endl;


    
    return 0;
}

//TC = O(n)
//SC = O(1)