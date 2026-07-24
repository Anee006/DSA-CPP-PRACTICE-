// Leetcode 328

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
// The first node is considered odd, and the second node is even, and so on. 
// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]

// LOGIC:
// Store first odd node as odd (first odd node will be the head).
// Store first even node as even (first even node will be head->next).
// Store the head of the even list as evenHead (as we need to attach the even list at the end of odd list).
// Traverse the list while: even and even->next exists.
//     Link the current odd node to next odd node (1 -> 3). Move odd pointer forward
//     Link current even node to next even node (2 -> 4). Move even pointer forward
// Connect the last node (of odd list) to evenHead.
// Return the original head of the list.

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

Node* oddEvenList(Node* head) {

}

void printList(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(7);

    cout << "Original List:\n";
    printList(head);

    head = oddEvenList(head);
    printList(head);

    return 0;
}

// TC = O(n)
// SC = O(n)