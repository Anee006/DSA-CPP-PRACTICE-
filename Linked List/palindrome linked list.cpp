// Leetcode 234

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

/*
Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false
*/

// LOGIC:
// find the middle of the list using slow-fast pointer. slow will pt to the middle
// reverse the second half (from where slow is pointing)
// compare the 1st half and the reversed 2nd half to check if it's a palindrome

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

bool isPalindrome(Node* head) {
    if(head == NULL || head->next == NULL) return true; // single element is a valid palindrome

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) { // find the middle of the list
        slow = slow->next;
        fast = fast->next;
    }

    Node* prev = NULL;
    Node* curr = slow;
    Node* next = NULL;

    // reverse the 2nd part
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // compare 1st half and reversed the 2nd half
    Node* first = head;
    Node* second = prev;

    while(second != NULL) {
        if(first->data != second->data) return false;

        first = first->next;
        second = second->next;
    }
    return true;
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
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    if(isPalindrome(head)) cout << "TRUE";
    else cout << "FALSE";

    return 0;
}

// TC = O(n) where n = no. of nodes
// SC = O(1)