//MERGE TWO SORTED LISTS
//using recursion

//You are given the heads of two sorted linked lists list1 and list2.
//Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
//Return the head of the merged linked list.

//Input: list1 = [1,2,4], list2 = [1,3,4]
//Output: [1,1,2,3,4,4]

//LOGIC:
//The smaller of the two heads given (h1 and h2), will become the new head of the merged list since, we are sorting in ascending order.
//Then for the remaining elements in both the linked list, we'll call the recursive fn. The head now returned will be joined with the 
//head we had found in the beginning (while comparing h1 and h2).

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

//to merge two linked lists using their heads:

Node* mergeTwoLists(Node* h1, Node* h2) //here h1 and h2 are the heads of list1 and list2 respectively
{
    //base case:
    if(h1 == NULL || h2 == NULL) //if either one of the two becomes NULL then, we'll return the remaining elememts of the other list
    {
        return h1 == NULL ? h2 : h1; //if our h1 is NULL we'll return h2 and vice versa 
    }


    if(h1->data <= h2->data) //means h1 will become the new head of merged list, since it is smaller
    {
        h1->next = mergeTwoLists(h1->next, h2); //h1 points to the value returned from the recursive fn (hence wrote h1 -> next)
        //we are calling recursive fn for the remaining part of h1. h2 remains as it is. Hence wrote, "mergeTwoLists(h1->next, h2)"

        return h1; //returning head of new sorted list
    }

    else //means h2 will become head of the sorted lists
    {
        h2->next =  mergeTwoLists(h1, h2->next);
        return h2; //returning head of new sorted list
    }
}

//to display the linked list:
void printLL(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<" -> ";
        temp = temp->next;
    }
    cout<< "NULL" <<endl;
}

int main()
{
    //first sorted list: [1,2,4]
    Node* h1 = new Node(1);
    h1->next = new Node(2);
    h1->next->next = new Node(4);

    //second sorted list: [1,3,4]
    Node* h2 = new Node(1);
    h2->next = new Node(3);
    h2->next->next = new Node(4);

    Node* newHead = mergeTwoLists(h1,h2);

    //to display merged list:
    printLL(newHead);

    return 0;
}

//TC = O(n + m) , where 'n' = no. of nodes in list1 and 'm' = no. of nodes in list2.