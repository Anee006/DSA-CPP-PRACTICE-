// Huffman Coding (encoding part only)

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// 1. Define a structure for a Huffman Tree node.
/*
    Each node contains:
    - a character (data)
    - frequency of that char
    - left and right child pointers
*/

struct Node
{
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) // constructor for node
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// 2. Comparator for priority_queue (min-heap)
struct compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq; // to sort char in increasing order of their freq
    }
};

// 3. Recursively traverse the Huffman Tree
/*
    - To left edge of a node -> add '0'
    - To right edge -> add '1'
    When a leaf node is reached, store the code
*/
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode)
{
    if(root == NULL) return; // base case

    // if leaf node, store the code
    if(root->left == NULL && root->right == NULL)
    {
        huffmanCode[root->ch] = code;
    }

    // traverse left & right
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main()
{
    // string (message) we need to compress
    string message = "BCCABBDDAECCBBAEDDCC";

    // count freq of each char. Using unordered_map for O(1) average lookup.
    unordered_map<char, int> freq; // for char and its freq
    for(char ch : message)
    {
        freq[ch]++;
    }

    // create a min-heap. Each char becomes a leaf node.
    priority_queue<Node*, vector<Node*>, compare> pq;

    for(auto pair: freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // build the Huffman Tree
    /*
        - Remove two nodes with smallest frequency
        - Create a new internal node with frequency of new node = sum of the two removed nodes
        - Push it back into the heap
        Repeat until only one node remains (root)
    */

    while(pq.size() > 1)
    {
        Node* left = pq.top(); // smallest of the two nodes, comes in left
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Internal node has no character ('\0'). It has only freq
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top(); // root of Huffman tree

    // generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for(auto pair: huffmanCode)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    // encode the input string
    string encoded = "";
    for(char ch : message)
    {
        encoded += huffmanCode[ch];
    }

    cout << "\nOriginal string: " << message << endl;
    cout << "\nEncoded string: " << encoded << endl; 

    return 0;
}

// TC = O(n log n)

/*
    NOTE:
    Huffman codes are not unique.
    Different Huffman trees can produce different but valid prefix codes.
    If decoding works correctly → encoding is correct.
*/