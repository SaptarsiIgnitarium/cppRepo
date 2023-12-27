#include <iostream>
using namespace std;

struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int x)
    {
        this -> data = x;
        this -> left = NULL;
    }
};

treeNode* lowestCommonAncestor(treeNode* root, treeNode* p, treeNode* q)
{
    if (root == NULL)
    {
        return NULL;    //root is null
    }

    else if(p->data < root->data && q->data < root->data)
    {
        return lowestCommonAncestor(root->left,p,q); //both nodes are in left subtree
    }
    else if(p->data > root->data && q->data > root->data)
    {
        return lowestCommonAncestor(root->right,p,q);  //both nodes are in the right subtree
    }
    else
    {
        return root;
    }   
}

int main()
{
    treeNode* root = new treeNode(6);
    root->left = new treeNode(2);
    root->right = new treeNode(8);
    root->left->left = new treeNode(0);
    root->left->right = new treeNode(4);
    root->right->left = new treeNode(7);
    root->right->right = new treeNode(9);
    root->left->right->left = new treeNode(3);
    root->left->right->right = new treeNode(5);

    treeNode* node1 = root->left->left;
    treeNode* node2 = root->left->right;

    treeNode* result = lowestCommonAncestor(root, node1, node2);

    if (result)
    {
        cout << "Lowest Common Ancestor: "<<result->data <<endl;
    }
    else
    {
        cout << "No common Ancestor" <<endl;
    }

    return 0;
}