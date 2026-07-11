// Leetcode 148
// Use Merge Sort on linked list to sort

// Given the head of a linked list, return the list after sorting it in ascending order.

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// LOGIC:
// find middle of the list (using slow-fast pointers)
// split the list into two halves (1st half is before slow and the second half will be after slow)
// sort each half recursively
// merge the two sorted halves (use logic similar to that of Leetcode 21 --> merging 2 sorted lists)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// to merge 2 sorted lists
Node* merge(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }

        else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if(l1 != NULL) tail->next = l1;

    if(l2 != NULL) tail->next = l2;

    return dummy.next;
}

Node* sortList(Node* head) {
    if(head == NULL || head->next == NULL) return head; // base case

    // find middle of the list
    Node* slow = head;
    Node* fast = head->next; // initialised with head->next as we have to apply merge sort (helps avoid infinite recursion)

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split into two halves
    Node* second = slow->next; // start of 2nd half // 2nd half will start from the node next to where slow is pointing 
    slow->next = NULL; // end of 1st half

    // sort each half
    Node* left = sortList(head);
    Node* right = sortList(second);

    return merge(left, right); // merge the two sorted halves
}

void printList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original List:\n";
    printList(head);

    Node* newHead = sortList(head);

    cout << "\nModified List:\n";
    printList(newHead);

    return 0;
}

// TC = O(n log n) where n = no. of nodes
// SC = O(log n) , due to recursion call stack