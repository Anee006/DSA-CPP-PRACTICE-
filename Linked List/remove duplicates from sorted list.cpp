// Leetcode 83

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
// Return the linked list sorted as well.

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

// LOGIC:
// compare the current node with its neighbor (since list is sorted so duplicates will be adjacent)
// if curr->val == curr->next->val, then the 2nd node is a duplicate, so skip it. 
// Do: curr->next = curr->next->next (this removes the duplicate node from list)
// after removing 1st duplicate if we move, we might miss the rest of the duplicates (eg: 1 -> 1 -> 1 -> 2)
// so, keep curr at the same node and compare again. Update curr only when next node is diff (i.e isn't a duplicate).

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

    Node* curr = head;

    while(curr != NULL && curr->next != NULL) {

        if(curr->val == curr->next->val) { // is a duplicate
            curr->next = curr->next->next; // skip the duplicate
        }

        else curr = curr->next;
    }
    return head;
}

// 1,1,2,3,3
int main() {
    return 0;
}

// TC = O(n) , where n = no. of nodes  (list is traversed once)
// SC = O(1) (only curr pointer is used)