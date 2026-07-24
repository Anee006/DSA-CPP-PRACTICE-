// Leetcode 2

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
// and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807 => 807 reversed = 7 -> 0 -> 8

// LOGIC:
// The digits are stored in reverse order in the linked list, so we can process from head to tail.
// Addition is performed normally using: digit1+ digit2+ carry.
// Traverse both the lists while:
// list1 != NULL i.e, list1 still has nodes OR list2 != NULL i.e, list2 still has nodes OR carry exists
// In each iteration:
//     Initialize sum with current carry
//     If l1 != NULL add l1->val to sum and move to next node. If l2 != NULL add l2->val to sum and move to next node
//     Calculate the new carry: carry = sum / 10. Calculate the new digit: digit = sum % 10
//     Create a new node containing digit and attach it to end of list. Move tail pointer to this new node

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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(0); // serves as the start of the result linked list
    Node* tail = dummy; // points to the last node in the ans

    int carry = 0;

    while(l1 || l2 || carry) { // loop runs till l1 has nodes OR l2 has nodes OR carry exists
        int sum = carry;

        if(l1) { // add current digit from 1st list, if present
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2) { // add current digit from 2nd list, if present
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10; // new carry for next position
        int digit = sum % 10; // to store current digit

        tail->next = new Node(digit); // create new node
        tail = tail->next;
    }
    return dummy->next; // points to the head of the resulting linked list
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
    Node* head1 = new Node(2);
    head1->next = new Node(4);
    head1->next->next = new Node(3);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node* head = addTwoNumbers(head1, head2);
    printList(head);

    return 0;
}

// TC = O(max(m, n)) , where m = no. of nodes in l1, n = no. of nodes in l2
// SC = O(1)