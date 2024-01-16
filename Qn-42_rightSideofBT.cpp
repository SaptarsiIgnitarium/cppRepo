#include <iostream>
#include <vector>

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

vector<int> rightSideofBT(Node*);

void dfs(Node*, int, vector<int>& );

int main()
{
    //creating the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);     
    root->right->right = new Node(5);

    vector<int> result = rightSideofBT(root);

    cout << "Nodes visible from the right side are :";
    for (auto var : result)
    {
        cout << var << " ";
    }
    cout << endl;

    return 0;
}

vector<int> rightSideofBT(Node* root)
{
    vector<int> result;
    dfs(root, 0, result);
    return result;
}

void dfs(Node* root, int level, vector<int>& result)
{
    if(root == NULL)
    {
        return;
    }

    if(result.size() == level)
    {
        result.push_back(root->data);
    }
    dfs(root->right, level+1, result);
    dfs(root->left, level+1, result);
}