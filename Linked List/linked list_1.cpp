//to create a linked list WITHOUT USING STL.
//implementing push_front and push_back in LL

#include <iostream>
using namespace std;

class Node  //to create individual nodes of a LL
{
    public:
        int data; //to store the data
        Node *next;   //stores address of next node

        Node(int value)
        {
            data=value;
            next=NULL;
        }
};
class List  //to create the linked list
{
    private:
        Node *head;    //creating a head of type Node*
        Node *tail;    //creating a tail of type Node*

    public:
            List()
            {
                head=tail=NULL;
            }

            //push_front
            void push_front(int val)
            {
                Node *newNode= new Node(val); //creating a new node  //new keyword helps create a dynamic obj.
                if(head==NULL)  //checking if head is NULL
                {
                    head = tail = newNode;
                    return;
                }

                //when head is not NULL. i.e, a node already exists in the LL.
                else
                {
                    newNode->next= head; //the data which is pushed to front, should point to the head.
                    head=newNode; //the newNode now becomes the head as it is the first node of LL.
                }
            }

            //push_back
            void push_back(int val)
            {
                Node * newNode= new Node(val);
                if(head==NULL)
                {
                    head=tail=newNode;
                }
                else
                {
                    tail->next=newNode; //tail stores address of next location i.e, the newly added value
                    tail=newNode;
                }
            }

            //NOTE: If only head ptr is give, write push_back like this:
            /*
            void push_back(int val)
            {
                Node* newNode = new Node(val);
                if(head == NULL)
                {
                    head = newNode;
                    return;
                }
                else
                {
                    Node* temp = head;
                    while(temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
            }
            
            */

            void printLL()
            {
                Node *temp=head; //creating a temp variable which points to head
                while (temp!=NULL)
                {
                    cout << temp->data <<"->";
                    temp = temp->next; //updating the temp to access each node 
                }
                cout<<"NULL"<<endl;
            }
};
int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.printLL();

    l1.push_back(4);
    l1.printLL();

    return 0;

}
