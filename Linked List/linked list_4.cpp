//to create a linked list WITHOUT USING STL.
//implementing  search(key) in LL.
//implementing count() to count no. of nodes in the LL.

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

        //search(key)
        int search(int key)
        {
            Node * temp = head;
            int idx=0;

            while(temp!=NULL)
            {
                if(temp->data==key)
                {
                    cout<<"Found!!"<<endl;
                    return idx;
                }

                temp=temp->next;
                idx++;
            }

            return -1; //to indicate that the key doesn't exist
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

        //to count no. of nodes in list
        int countNodes()
        {
            int count =0;
            Node* temp = head;

            while(temp != NULL)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
};
int main()
{
    List l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.printLL();

    cout<< "\nDoes 2 exist in list? " << l1.search(2) <<endl;
    cout<< "\nDoes 5 exist in list? " << l1.search(5) <<endl;
   

    cout << "\nNo of nodes in this list: " << l1.countNodes() << endl;
    
    return 0;  
}

