//insertion in Threaded BST

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        bool leftIsThread, rightIsThread;

        Node(int val)
        {
            data = val;
            left = right = NULL;
            leftIsThread = rightIsThread = true; //new nodes start with threads by default
        }
};

class ThreadedBST
{
    private:
        Node* root; //dummy node

        //to find inorder successor of a node
        Node* inorderSuccessor(Node* ptr)
        {
            //if right pointer is a thread, successor is right
            if(ptr->rightIsThread)
            {
                return ptr->right;
            }

            //otherwise, go to left-most in the right child
            ptr = ptr->right;
            while(!ptr->leftIsThread)
            {
                ptr = ptr->left;
            }
            return ptr;
        }

        //to find the left-most node starting at node
        Node* leftMost(Node* node)
        {
            if(node == NULL) return NULL;

            while(!node->leftIsThread)
            {
                node = node->left;
            }
            return node;
        }

    public:
        
        ThreadedBST()
        {
            root = new Node(INT_MAX); //dummy key
            root->left = root;
            root->right = root;
            root->leftIsThread = true;
            root->rightIsThread = false;
        }

        //to insert a node in threaded BST:
        void insert(int key)
        {
            Node* ptr = root->left;
            Node* parent = root;

            //find parent where new node will be attached
            while(ptr != root)
            {
                if(key == ptr->data)
                {
                    cout << "Key " << key << " already exists." << endl; //duplicates not allowed
                    return;
                }

                parent = ptr;

                if(key < ptr->data)
                {
                    if(!ptr->leftIsThread)
                        ptr = ptr->left;
                    else
                        break; // left is a thread => insertion point
                }
                else
                {
                    if(!ptr->rightIsThread)
                        ptr = ptr->right;
                    else
                        break; // right is a thread => insertion point
                }
            }

            Node* newNode = new Node(key);

            if(parent == root && ptr == root) //means tree is empty
            {
                root->left = newNode;
                root->leftIsThread = false;

                newNode->left = root;
                newNode->right = root;
                newNode->leftIsThread = true;
                newNode->rightIsThread = true;
            }

            //insert as left child of parent
            else if(key < parent->data)
            {
                newNode->left = parent->left;
                newNode->leftIsThread = true;

                newNode->right = parent;
                newNode->rightIsThread = true;

                parent->left = newNode;
                parent->leftIsThread = false;
            }

            //insert as right child of parent
            else
            {
                newNode->right = parent->right;
                newNode->rightIsThread = true;

                newNode->left = parent;
                newNode->leftIsThread = true;

                parent->right = newNode;
                parent->rightIsThread = false;
            }

            cout << "Inserted " << key << endl;
        }

        void printInorder()
        {
            if(root->left == root)
            {
                cout << "Tree is empty\n";
                return;
            }

            cout << "Inorder: ";
            //start as left-most node of real root
            Node* curr = leftMost(root->left);
            while(curr != root)
            {
                cout << curr->data << " ";
                curr = inorderSuccessor(curr);
            }
            cout << endl;
        }
};

int main()
{
    ThreadedBST tree;

    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(16);
    tree.insert(25);
    
    cout << "------------------------------" << endl;
    tree.printInorder(); //5 10 16 20 25 30

    return 0;
}
