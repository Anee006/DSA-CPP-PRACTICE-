//To create an AVL tree (insertion and deletion)

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
            height = 1;
        }
};

class AVLTree
{
    private:
        Node* root;

        //to count no. of each rotations
        int LLcount = 0;
        int RRcount = 0;
        int LRcount = 0;
        int RLcount = 0;

        int getHeight(Node* node)
        {
            if(node == NULL) return 0;

            return node->height;
        }

        int getBalanceFactor(Node* node)
        {
            if(node == NULL) return 0;

            return getHeight(node->left) - getHeight(node->right);
        }

        // Right rotation fn
        Node* rightRotate(Node* y)
        {
            Node* x = y->left;
            Node* T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = 1 + max(getHeight(y->left), getHeight(y->right));
            x->height = 1 + max(getHeight(x->left), getHeight(x->right));

            return x;
        }

        // Left rotations fn
        Node* leftRotate(Node* x)
        {
            Node* y = x->right;
            Node* T2 = y->left;
            
            y->left = x;
            x->right = T2;

            x->height = 1 + max(getHeight(x->left), getHeight(x->right));
            y->height = 1 + max(getHeight(y->left), getHeight(y->right));

            return y;
        }

        Node* insert(Node* node, int val)
        {
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

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));

            int BF = getBalanceFactor(node);

            //LL case:
            if(BF > 1 && val < node->left->data)
            {
                LLcount++;
                return rightRotate(node);
            }   

            //RR case:
            if(BF < -1 && val > node->right->data)
            {
                RRcount++;
                return leftRotate(node);
            }

            //LR case:
            if(BF > 1 && val > node->left->data)
            {
                LRcount++;
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            //RL case:
            if(BF < -1 && val < node->right->data)
            {
                RLcount++;
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            return node;
        }

        // Delete Functions

        //to find the Inorder Successor of a node  (IS is the smallest val in RST)
        Node* getInorderSucc(Node* node)  
        {
            Node* curr = node;

            while(curr->left != NULL)
            {
                curr = curr->left;
            }
            return curr;
        }

        //to delete a node from AVL tree
        Node* deleteNode(Node* root, int key)
        {
            // 1. Standard BST delete
            if(root == NULL) return root;

            if(key < root->data)
            {
                root->left = deleteNode(root->left, key);
            }
            else if(key > root->data)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {
                //case 1 and 2 combined: when node has 0 or 1 child 
                if(root->left == NULL)
                {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                }

                else if(root->right == NULL)
                {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                else
                {
                    //case 3: node has 2 children
                    Node* IS = getInorderSucc(root->right);
                    root->data = IS->data;
                    root->right = deleteNode(root->right, IS->data);
                }
            }

            // 2. updating height of root
            root->height = 1 + max(getHeight(root->left), getHeight(root->right));

            // 3. get balance factor
            int BF = getBalanceFactor(root);

            // 4. rebalance (4 cases)

            // LL case:
            if(BF > 1 && getBalanceFactor(root->left) >= 0)
            {
                LLcount++;
                return rightRotate(root);
            }
                
            
            // RR case:
            if(BF < -1 && getBalanceFactor(root->right) <= 0)
            {
                RRcount++;
                return leftRotate(root);
            }
                
            
            // LR case:
            if(BF > 1 && getBalanceFactor(root->left) < 0)
            {
                LRcount++;
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // RL case:
            if(BF < -1 && getBalanceFactor(root->right) > 0)
            {
                RLcount++;
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }


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

        void deleteKey(int key)
        {
            root = deleteNode(root, key);
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

        void printNumberOfRotations()
        {
            cout << endl;
            cout << "Number of LL Rotations: " << LLcount << endl;
            cout << "Number of RR Rotations: " << RRcount << endl;
            cout << "Number of LR Rotations: " << LRcount << endl;
            cout << "Number of RL Rotations: " << RLcount << endl;
        }
};

int main()
{
    AVLTree tree;

    tree.insert(30);
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);

    tree.inorder(); // 5 10 20 30 40 50 60
    tree.preorder(); // 20 10 5 40 30 50 60 
    tree.printNumberOfRotations();

    cout << "\n\nAfter deleting 60 and 30\n\n";

    tree.deleteKey(60);
    tree.deleteKey(30);

    tree.inorder(); // 5 10 20 40 50
    tree.preorder(); // 20 10 5 40 50
    tree.printNumberOfRotations();

    return 0;
}

