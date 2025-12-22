// HUFFMAN ENCODING + DECODING

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare
{
    bool operator() (Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode)
{
    if(root == NULL) return;

    // if leaf node -> store code
    if(root->left == NULL && root->right == NULL)
    {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0" , huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// decode and encode the string using Huffman tree
string decode(Node* root, string& encoded)
{
    string decoded = "";
    Node* curr = root;

    for(char bit: encoded)
    {
        if(bit == '0')
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }

        // if reached a leaf node
        if(curr->left == NULL && curr->right == NULL)
        {
            decoded += curr->ch;
            curr = root; // restart for next character
        }
    }
    return decoded;
}

int main()
{
    string text = "Ayeeeiooo";

    // calc frequency
    unordered_map<char, int> freq;
    for(char ch : text)
    {
        freq[ch]++;
    }

    // create min-heap of nodes
    priority_queue<Node*, vector<Node*>, compare> pq;

    for(auto pair: freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // build Huffman tree
    while(pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    Node* root = pq.top(); // root of tree

    // generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // encode the string
    string encoded = "";
    for(char ch : text)
    {
        encoded += huffmanCode[ch];
    }

    string decoded = decode(root, encoded);

    cout << "Hiffman Codes:\n";
    for(auto pair: huffmanCode)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    cout << "\nOriginal String: " << text << endl;
    cout << "\nEncoded String: " << encoded << endl;
    cout << "\nDecoded String: " << decoded << endl;

    return 0;
}

