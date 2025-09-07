//to create a linked list WITHOUT USING STL.
//implementing pop_front, pop_back in LL.

#include <iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;

        Node(int val)
        {
            data=val;
            next=NULL;
        }
};
class List
{
    private:
        Node* head;
        Node* tail;
    public:
        List()
        {
            head=tail=NULL;
        }
        
        //push_front
        void push_front(int val)
        {
            Node *newNode= new Node(val); //creating a new node
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
                return;
            }
            else
            {
                tail->next=newNode; //tail stores address of next location i.e, the newly added value
                tail=newNode;
            }
        }

        //pop_front
        void pop_front()
        {
            if(head==NULL)
            {
                cout<<"LL is empty"<<endl;
                return;
            }
            else
            {
                Node *temp=head;
                head=head->next;
                temp->next=NULL;
                delete temp;
            }
        }

        //pop_back
        void pop_back()
        {
            if(head==NULL)
            {
                cout<<"LL is empty"<<endl;
                return;
            }
            else
            {
                Node *temp= head;
                while(temp->next != tail)  //to get the location of prev node. Prev node is the one which will become the new tail after deleting
                {                          //Here if we don't have tail ptr given, we can write: if(temp -> next ->next == NULL). Bcox the next to next value of prev node is NULL
                    temp=temp->next;
                }
                temp->next =NULL;
                delete tail; //data of the value at the tail node is being deleted from memory
                tail=temp;  //here we are simply assigning temp to the tail variable
            }
        }

        void printLL()
        {
            Node *temp=head;
            while(temp!=NULL)
            {
                cout<< temp->data << "->";
                temp=temp->next;
            }
            cout<<"NULL"<< endl;
        }
};
int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_back(4);
    l1.printLL();

    l1.pop_front();
    l1.printLL();

    l1.pop_back();
    l1.printLL();


    return 0;  
}
