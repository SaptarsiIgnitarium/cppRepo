#include <iostream>
using namespace std;

struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

treeNode* lowestCommonAncestor(treeNode* root, treeNode* p, treeNode* q);


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

    treeNode* node1 = root->left->right->left;
    treeNode* node2 = root->left->right->right;

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

treeNode* lowestCommonAncestor(treeNode* root, treeNode* p, treeNode* q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    treeNode* left = lowestCommonAncestor(root->left,p,q);
    treeNode* right = lowestCommonAncestor(root->right,p,q);

    if(left == NULL)
    {
        return right;
    }
    else if(right == NULL)
    {
        return left;
    }
    else{             //if both left and right are not null we found our lca
        return root;
    }

}