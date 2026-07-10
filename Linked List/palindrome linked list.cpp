// Leetcode 234

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

/*
Input: head = [1,2,2,1]
Output: true

Input: head = [1,2]
Output: false
*/

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