//to create a linked list WITHOUT USING STL.
//implementing insert(value, position)  in LL.

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
                {
                    temp=temp->next;
                }
                temp->next =NULL;
                delete tail; //data of the value at the tail node is being deleted from memory
                tail=temp;
            }
        }

        //insert(value, index position) : used to insert in middle of LL
        void insert(int val, int pos)
        {
            if(pos<0)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            if(pos==0)
            {
                push_front(val);
                return;
            }

            Node *temp=head;
            for(int i=0; i<pos-1; i++) //to get the address of the (pos-1) node
            {
                if(temp==NULL)
                {
                    cout<<"Invalid position."<<endl;
                    return;
                }
                temp=temp->next;
            }

            Node* newNode= new Node(val);
            newNode->next = temp->next; //(temp->next) right now points to the position where we want to insert the value
            temp->next =newNode;
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
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.printLL();

    l1.insert(4,1); //0 based indexing is there. Inserts 4 at 2nd place (i.e 1st idx)
    l1.printLL();

    
    return 0;  
}

