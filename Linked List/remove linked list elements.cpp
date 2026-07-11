// Leetcode 203

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that 
// has Node.val == val, and return the new head.

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// LOGIC:
// Create a dummy node (so that if the node to be removed is the head of the list, we can remove it easily).
// Create a curr pointer which will point to the node just before the one that has to be removed.
// If curr->next->val == val means curr->next is the node that has to be removed.
// Skip that node by doing: curr->next = curr->next->next.
// Else, update the curr pointer.

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int data) {
        val = data;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

Node* removeElements(Node* head, int val) {
    Node* dummy = new Node(0); 
    dummy->next = head;

    Node* curr = dummy;

    while(curr->next != NULL) {
        if(curr->next->val == val) { 
            curr->next = curr->next->next; // skip the elements that have to be removed
        }
        else curr = curr->next;
    }
    return dummy->next;
}


// 1,2,6,3,4,5,6
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(6);

    cout << "Original List:\n";
    printList(head);

    int val = 6;
    Node* newHead = removeElements(head, val);

    cout << "\nModified List:\n";
    printList(newHead);

    return 0;
}

// TC = O(n) where n = no. of nodes
// SC = O(1)

