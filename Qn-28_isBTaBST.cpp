#include <iostream>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(Node*);

bool isValidBST(Node*, int, int);

int main()
{
    // //creating the binary tree
    // Node* root = new Node(2);
    // root->left = new Node(6);
    // root->right = new Node(3);

    Node* root = NULL;
    root = buildTree(root);      //buiding tree from user input

    if(isValidBST(root, INT_MAX, INT_MIN))
    {
        cout << "It is a valid BST" << endl;
    }
    else
        cout << "It is not a valid BST" << endl;

    return 0;    
}

bool isValidBST(Node* root, int Max, int Min)
{
    if(root == NULL)
    {
        return true;  //base condition
    }

    if(root->data > Max || root->data < Min)
    {
        return false;   //if the node value is out of limits
    }

    bool leftIsValid = isValidBST(root->left, root->data, Min);
    bool rightIsValid = isValidBST(root->right, Max, root->data); 

    return leftIsValid && rightIsValid;  //is one size returns false then return false

}

Node* buildTree(Node* root)  //for building BT from user input
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
    root->left = buildTree(root->left);
    cout << "Enter the data for inserting in the right of "<< data << endl;
    root->right = buildTree(root->right);

    return root;
}
