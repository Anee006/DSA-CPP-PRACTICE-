//MIDDLE OF A LINKED LIST
//Using slow-fast pointer approach (helps in finding the middle node using a single loop)

//Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes (in case of even no. of nodes), return the second middle node.

//Input: head = [1,2,3,4,5]
//Output: [3,4,5]
//Explanation: The middle node of the list is node 3.

//Input: head = [1,2,3,4,5,6]
//Output: [4,5,6]
//Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

//Constraints:
//The number of nodes in the list is in the range [1, 100].


//LOGIC of slow-fast pointer approach:
//Create two ptr - slow and fast. Both are initialised with "head".
//slow is updated by +1 each time and fast is updated by +2 each time.
//i.e, (slow = slow -> next) and (fast = fast -> next -> next).
//We'll keep moving fast and slow ptr till our fast ptr covers the whole linked list.
//As soon as fast crosses the linked list, our slow ptr will point to the middle of the linked list.

//So, one stopping condition is: (fast != NULL), in case of even sized linked list.

//In case of odd sized linked list, stopping condition is: (fast -> next != NULL). Here, we stop at the last node of the linked list, whose 
//"next" points to NULL.


//SC = O(1)
//TC = O(n) , where n = no. of nodes in linked last.

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

class List
{
    public:
        Node* head;
        Node* tail;

        List()
        {
            head = tail = NULL;
        }

        //push_back
        void push_back(int val)
        {
            Node* newNode = new Node(val);
            if(head == NULL)
            {
                head = tail = newNode;
                return;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void printLL()
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout<< temp->data <<" -> ";
                temp = temp->next;
            }
            cout<<"NULL" <<endl;
        }
};

//to calculate middle of linked list
class Middle
{
    public:
        Node* middleNode(Node* head) //fn to find middle node
        {
            Node* slow = head; //slow ptr
            Node* fast = head; //fast ptr

            while(fast != NULL && fast->next != NULL) 
            //using && here bcoz we want to ensure that neither our fast should be NULL nor its next should be NULL
            {
                slow = slow->next; //slow is updated by +1
                fast = fast->next->next; //fast is updated by +2
            }

            return slow; //after coming out of loop, slow now points to the middle of the list.
        }
};

int main()
{
    List l1;
    //n = 5. i.e, odd sized linked list
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);

    l1.printLL();

    //to find middle of l1:
    Middle mid_1;
    Node* mid = mid_1.middleNode(l1.head);

    if(mid != NULL)
    {
        cout<< "Middle element = " << mid->data <<endl;
    }
    else
    {
        cout<<"List is empty" <<endl;
    }
    cout<<endl;
   
    //------------------------------------------------------------------------------

    //n = 6 i.e, even sized linked list
    List l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);

    l2.printLL();

    //to find middle of l2:
    Middle mid_2;
    Node* m = mid_2.middleNode(l2.head);

    if(m != NULL)
    {
        cout<<"Middle element = " << m->data <<endl;
    }
    else
    {
        cout<<"List is empty" <<endl;
    }

}

