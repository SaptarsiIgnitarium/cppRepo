#include <iostream>
#include <algorithm>
using namespace std;

class Node 
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in the left of "<< data << endl;
    root->left = buildTree (root->left);
    cout << "Enter the data for inserting in the right of "<< data << endl;
    root->right = buildTree (root->right);

    return root;
}

int depth(Node* root)
{
    //base case
    if(root == NULL)
    {
        return 0;
    }

    int left = depth(root->left);
    int right = depth(root->right);

    int ans = max(left, right) + 1;
    return ans;
}


int main()
{
    Node* root = NULL;

    //Creating a tree
    root = buildTree(root);

    int depthoftree = depth(root);

    cout << "The depth of the binary tree is : "<< depthoftree;

    return 0;
}