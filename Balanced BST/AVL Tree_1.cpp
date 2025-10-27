//To create an AVL tree (insertion only)

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int val)
        {
            data = val;
            left = right = NULL;
            height = 1; // new node will be a leaf node, hence height is 1
        }
};

class AVLTree
{
    private:
        Node* root;

        // to get height of a node
        int getHeight(Node* node)
        {
            if(node == NULL) return 0;

            return node->height;
        }

        // to get balance factor of a node
        int getBalanceFactor(Node* node)
        {
            if(node == NULL) return 0;

            return getHeight(node->left) - getHeight(node->right);
        }

        /* Rotation functions */

        // right rotation on subtree rooted with y
        Node* rightRotate(Node* y)
        {
            Node* x = y->left;
            Node* T2 = x->right;

            // performing rotations
            x->right = y;
            y->left = T2;

            // Update heights
            y->height = 1 + max(getHeight(y->left), getHeight(y->right));
            x->height = 1 + max(getHeight(x->left), getHeight(x->right));

            return x; //x is the new root now after rotating, hence return that
        }

        // left rotation on subtree rooted with x
        Node* leftRotate(Node* x)
        {
            Node* y = x->right;
            Node* T2 = y->left;

            // performing rotations
            y->left = x;
            x->right = T2;

            // Update heights
            x->height = 1 + max(getHeight(x->left), getHeight(x->right));
            y->height = 1 + max(getHeight(y->left), getHeight(y->right));

            return y; //y is the new root now after rotating, hence return that
        }

        //to insert nodes into the AVL tree one by one
        Node* insert(Node* node, int val)
        {
            // 1. Normal BST insertion
            if(node == NULL)
            {
                return new Node(val);
            }

            if(val < node->data)
            {
                node->left = insert(node->left, val);
            }
            else if(val > node->data)
            {
                node->right = insert(node->right, val);
            }
            else
            {
                return node;
            }

            // 2. Updating heights
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));

            // 3. Get Balance Factor
            int BF = getBalanceFactor(node);

            // 4. Balance the node, if unbalanced

            // Left Left (LL) case:
            if(BF > 1 && val < node->left->data)
                return rightRotate(node);


            // Right Right (RR) case:
            if(BF < -1 && val > node->right->data)
                return leftRotate(node);


            // Left Right (LR) case:
            if(BF > 1 && val > node->left->data)
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            
            // Right Left (RL) case:
            if(BF < -1 && val < node->right->data)
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }

        //to print inorder sequence of created AVL Tree
        void inorder(Node* root)
        {
            if(root == NULL) 
            {
                return;
            }

            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }

        //to print preorder sequence of created AVL Tree
        void preorder(Node* root)
        {
            if(root == NULL)
            {
                return;
            }

            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }

    public:

        AVLTree()
        {
            root = NULL;
        }

        void insert(int key)
        {
            root = insert(root, key);
        }

        void inorder()
        {
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
        }

        void preorder()
        {
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
        }
};

int main()
{
    AVLTree tree1;

    cout << " ---- LR Rotation ---- " << endl;
    tree1.insert(30);
    tree1.insert(10);
    tree1.insert(20);
    tree1.inorder(); //Output: 10, 20, 30
    tree1.preorder(); //Output: 20, 10, 30
    cout << "\n ------------------------------------------------ \n" << endl;


    // to create an AVL tree from a given array:
    AVLTree tree2;

    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(arr)/ sizeof(arr[0]);

    for(int i = 0; i<n; i++)
    {
        tree2.insert(arr[i]);
    }

    tree2.inorder(); // Output: 10, 20, 25, 30, 40, 50
    tree2.preorder(); // Output: 30, 20, 10, 25, 40, 50

    return 0;
}
