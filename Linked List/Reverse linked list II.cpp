// Leetcode 92

// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// NOTE: Here left and right are 1-based indices

// LOGIC:
// Move prev to the node just before left node
// Move curr to the next node i.e, curr = prev->next
// But instead of running until curr == NULL, only run: (right - left + 1) times
// Then use the exact same logic as was used to reverse an entire linked list

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

Node* reverseBetween(Node* head, int left, int right) {
    if(head == NULL || left == right) return head;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;

    for(int i = 1; i < left; i++) prev = prev->next; // move prev to just before the left node

    Node* curr = prev->next;
    Node* next = NULL;

    Node* connect = prev;
    Node* tail = curr;

    // reverse the portion between (right-left+1)
    for(int i = 0; i < right-left+1; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // restablish connections
    connect->next = prev;
    tail->next = curr;

    return dummy->next;
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

    int left = 2, right = 4;

    Node* newHead = reverseBetween(head, left, right);
    
    cout << "\nModified List:\n";
    printList(newHead);

    return 0;
}

// TC = O(n) where n = no. of nodes
// SC = O(1)