// #notes
//REVERSE A LINKED LIST 

//Given the head of a singly linked list, reverse the list, and return the reversed list.

//Input: head = [1,2,3,4,5]
//Output: [5,4,3,2,1]

//SC = O(1)
//TC = O(n)  , where n is the no. of nodes in the linked list

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

class List
{
    public:
        Node* head;
        Node* tail;

    public:
    List()
    {
        head = tail = NULL;
    }

    //push_back
    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head=tail=newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printLL()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL" <<endl;
    }
};

class Reverse
{
    public:

    //to reverse a linked list
    Node* reverseList(Node* head) //only the head is given to reverse the list
    {
        //initialising pointers:
        Node* prev = NULL; //prev ptr
        Node* curr = head; //current ptr //to track the current node we are in
        Node* next = NULL; //next ptr

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; //in the end, the node at which the prev points to is the node which needs to become the new head
    }
};

//to display the reversed list:
void displayReverse(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<" -> ";
        temp = temp->next;
    }
    cout <<"NULL" <<endl;
}


int main()
{
    List l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);

    cout << "Original list: " <<endl;
    l1.printLL();

    //to reverse the list:
    Reverse obj;
    Node* newHead = obj.reverseList(l1.head); //l1.head gives the head of the original list

    l1.head = newHead; //updating the list's head

    cout << "\nReversed list: " << endl;
    l1.printLL(); //can also write: displayReverse(newHead)
   
    return 0;
}