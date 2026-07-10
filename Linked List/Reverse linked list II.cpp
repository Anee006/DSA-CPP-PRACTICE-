// Leetcode 92

// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// NOTE: Here left and right are 1-based indices

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

    int left = 2, right = 4;

    return 0;
}