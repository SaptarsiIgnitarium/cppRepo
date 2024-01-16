#include <iostream>
using namespace std;

class treeNode
{
public:
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

int count = 0;
int result = -1;

void inorderTrv(treeNode* &root, int& k);

int main()
{
    //simple bst
    treeNode* root = new treeNode(3);
    root->left = new treeNode(1);
    root->right = new treeNode(4);
    root->left->right = new treeNode(2);

    int k = 3;

    inorderTrv(root ,k); //the function to find kth smallest

    cout << "The kth smallest element is :" << result;

    return 0;
}

void inorderTrv(treeNode* &root, int& k)
{
    if( root == NULL || count >= k)
    {
        return;
    }

    inorderTrv(root->left, k);

    count++;
    if (count == k)
    {
        result = root->data;
        return;
    }

    inorderTrv(root->right, k);   
}