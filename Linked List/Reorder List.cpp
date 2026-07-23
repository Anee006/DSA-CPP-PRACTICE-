// Leetcode 143

// You are given the head of a singly linked-list. The list can be represented as: L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form: L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// LOGIC:
// Find the middle of the list using slow-fast pointers.
// Split the list in two halves.
// Reverse the second half using the reverse() function created.
// Merge the two halves alternatively because the pattern is like: first node, last node, second node, second last node ....
// first->next = second links the first node to the last node of list.
// second->next = next1 links the second node to the second last node.

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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(Node* head) {
    if(head == NULL || head->next == NULL) return;

    // find middle of list
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split list
    Node* second = slow->next;
    slow->next = NULL;

    second = reverse(second); // reverse 2nd half

    // merge the 2 halves alternately
    Node* first = head;

    while(second != NULL) {
        Node* next1 = first->next;
        Node* next2 = second->next;

        first->next = second; // link 1st node to 2nd node
        second->next = next1; // link 2nd node to next node of 1st half

        first = next1;
        second = next2;
    }
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List:\n";
    printList(head);

    reorderList(head);

    cout << "Modified List:\n";
    printList(head);

    return 0;
}

// TC = O(n)
// SC = O(1)