//search a node in RB Tree


#include <iostream>
using namespace std;

//defining colors as boolean constants
const bool RED = true;
const bool BLACK = false;

class Node
{
    public:
        int data;
        bool color;  //true = RED, false = BLACK
        Node* parent;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            color = RED; //new node is always RED
            parent = left = right = NULL;
        }
};

class RBTree
{
    private:
        Node* root;
        Node* NIL;   // Sentinel node for all null references (represents null ptr)

        // Left Rotation:
        void leftRotate(Node* x) //Move the right child up, push the current node down to its left
        {
            Node* y = x->right;
            x->right = y->left;
            if(y->left != NIL)
            {
                y->left->parent = x;
            }

            y->parent = x->parent;

            if(x->parent == NIL)
            {
                root = y;
            }
            else if(x == x->parent->left)
            {
                x->parent->left = y;
            }
            else
            {
                x->parent->right = y;
            }

            y->left = x;
            x->parent = y;
        }

        //Right Rotation:
        void rightRotate(Node* y) //Move the left child up, push current node down to its right.
        {
            Node* x = y->left;
            y->left = x->right;
            if(x->right != NIL)
            {
                x->right->parent = y;
            }

            x->parent = y->parent;

            if(y->parent == NIL)
            {
                root = x;
            }
            else if(y == y->parent->left)
            {
                y->parent->left = x;
            }
            else
            {
                y->parent->right = x;
            }

            x->right = y;
            y->parent = x;
        }

        //to fix violations after insertion
        void insertFixup(Node* z)
        {
            Node* uncle;

            while(z->parent->color == RED) //till there is RR violation, fix it
            {
                //Case A: Parent is LEFT child of grandparent
                if(z->parent == z->parent->parent->left)
                {
                    uncle = z->parent->parent->right; //Uncle will be RIGHT child of grandparent

                    // case 1: Uncle is RED --> recolor
                    if(uncle->color == RED)
                    {
                        z->parent->color = BLACK;
                        uncle->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent; //update z to fix any other violations
                    }

                    //case 2: Uncle is BLACK (rotate and recolor)
                    else 
                    {
                        // z is right child --> Left rotate parent
                        if(z == z->parent->right)
                        {
                            z = z->parent;
                            leftRotate(z);
                        }

                        // z is left child --> Right rotate grandparent
                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        rightRotate(z->parent->parent);
                    }
                }

                //Case B: Parent is RIGHT child of grandparent
                else
                {
                    uncle = z->parent->parent->left;

                    if(uncle->color == RED)
                    {
                        z->parent->color = BLACK;
                        uncle->color = BLACK;
                        z->parent->parent->color = RED;
                        z = z->parent->parent;
                    }
                    else //rotate and recolor
                    {
                        if(z == z->parent->left)
                        {
                            z = z->parent;
                            rightRotate(z);
                        }

                        z->parent->color = BLACK;
                        z->parent->parent->color = RED;
                        leftRotate(z->parent->parent);
                    }
                }

                if(z == root) break;
            }
            root->color = BLACK; // Root must always be BLACK
        }

        void inorderHelper(Node* node)
        {
            if(node != NIL)
            {
                inorderHelper(node->left);
                cout << node->data << " (" << (node->color == RED ? "R" : "B") << ") ";
                inorderHelper(node->right);
            }
        }

    public:
        RBTree()
        {
            NIL = new Node(0); // dummy node
            NIL->color = BLACK;
            NIL->left = NIL->right = NIL->parent = NIL;
            root = NIL;
        }

        //to insert nodes in RB tree
        void insert(int val)
        {
            Node* z = new Node(val);
            z->left = z->right = z->parent = NIL;

            Node* y = NIL;  //to track the parent
            Node* x = root;  //start from the root

            //Step 1: Standard BST insertion
            while(x != NIL)
            {
                y = x;
                if(z->data < x->data)
                {
                    x = x->left;
                }
                else
                {
                    x = x->right;
                }
            }

            z->parent = y;
            if(y == NIL)
            {
                root = z; //if tree was empty
            }
            else if(z->data < y->data)
            {
                y->left = z;
            }
            else
            {
                y->right = z;
            }

            // Step 2: Fix violation
            insertFixup(z);
        }

        void inorder()
        {
            cout << "Inorder: ";
            inorderHelper(root);
            cout << endl;
        }

        Node* search(int val)
        {
            Node* curr = root;
            while(curr != NIL && curr->data != val)
            {
                curr = (val < curr->data) ? curr->left : curr->right;
            }
            return (curr != NIL) ? curr : NULL; //returns curr only if node is NOT a NULL value
        }
};

int main()
{
    RBTree tree;

    int arr[] = {10, 20, 30, 15};
    int n = sizeof(arr)/ sizeof(arr[0]);

    for(int i=0; i<n; i++)
    {
        cout << "Inserting " << arr[i] << endl;
        tree.insert(arr[i]);
        tree.inorder();
        cout << "------------------------" << endl;

    }

    cout << endl;

    int val;
    cout << "Enter val to search: ";
    cin >> val;

    Node* result = tree.search(val);

    if(result)
    {
        cout << "Node " << val << " found in the tree!" << endl;
    }
    else
    {
        cout << "Node " << val << " not found in the tree!" << endl;
    }

    return 0;
}