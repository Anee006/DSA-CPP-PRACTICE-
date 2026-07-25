// Leetcode 23
// Using Min Heap (priority queue)

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

/*
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[1->4->5, 1->3->4, 2->6]
merging them into one sorted linked list: 1->1->2->3->4->4->5->6
*/

// LOGIC:
// Always pick the smallest current node among all lists.
// Initially, every list has its smallest element at the head.
// Instead of looking through every list each time, keep the heads inside a min heap (it gives the smallest node)

#include <iostream>
#include <queue>
#include <vector>
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

struct Compare {
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& lists) {
}

void printList(Node* head) {
    Node* temp = head;

    while(temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main() {

    // list 1: 1 -> 4 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    // list 2: 1 -> 3 -> 4
    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    // list 3: 2 -> 6
    Node* l3 = new Node(2);
    l3->next = new Node(6);

    vector<Node*> lists = {l1, l2, l3}; // [[1,4,5],[1,3,4],[2,6]]

    Node* head = mergeKLists(lists);
    printList(head);

    return 0;
}