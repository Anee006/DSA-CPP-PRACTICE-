// Leetcode 82

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
// Return the linked list sorted as well.

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// LOGIC:
// We need to remove every value that appears more than once. So, skip all the duplicates and keep only the unique nodes in the list.
// Create a dummy node that has value = 0. This allows us to delete the head if head is a duplicate.
// Create two pointers prev and curr. prev points to the last node known to be unique and curr is used to traverse the list.
// If duplicate is found i.e, curr->val == curr->next->val then, the current node is a duplicate.
// Skip all duplicates. Then connect prev->next = curr.
// If not a duplicate then, update both the pointers.

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

Node* deleteDuplicates(Node* head) {
    if(head == NULL) return head;

    Node* dummy = new Node(0); // create a dummy node with val = 0
    dummy->next = head;

    Node* prev = dummy;
    Node* curr = head;

    while(curr != NULL) {
        // if is a duplicate
        if(curr->next != NULL && curr->val == curr->next->val) {
            int duplicate = curr->val; // current node is a duplicate 

            while(curr != NULL && curr->val == duplicate) {
                curr = curr->next; // skip all duplicates (remove them)
            }
            prev->next = curr;
        }

        else {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
}

void printList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(5);

    cout << "Original List:\n";
    printList(head);

    Node* newHead = deleteDuplicates(head);

    cout << "\nModified List:\n";
    printList(newHead);

    return 0;
}


// TC = O(n), where n = no. of nodes
// SC = O(1)