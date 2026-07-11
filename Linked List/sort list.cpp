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

Node* sortList(Node* head) {
        
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