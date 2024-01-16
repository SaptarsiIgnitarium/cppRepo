#include <iostream>
#include <vector>
#include <queue>

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

vector<vector<int>> levelOrder(Node* root);

int main()
{
    //creating the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);     
    root->right->right = new Node(5);

    vector<vector<int>> trav = levelOrder(root);

    cout << "Level order traversal is as follows : ";

    for (auto level: trav)
    {
        for(auto val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<vector<int>> levelOrder(Node* root)
{
    vector<vector<int>> result;

    if (root == NULL)
    {
        return result;  //empty
    }

    queue<Node* > que;   //have to try root->data
    que.push(root);

    while(!que.empty())
    {
        int size = que.size();
        vector<int> level;     //temporary vector to make aech level in result vector

        for(int i = 0; i < size; i++)
        {
            Node* node = que.front();
            que.pop();

            if(node->left != NULL)
            {
                que.push(node->left);
            }
            if(node->right != NULL)
            {
                que.push(node->right);
            }
            level.push_back(node->data);
        }
        result.push_back(level);
    }
    return result;
}
