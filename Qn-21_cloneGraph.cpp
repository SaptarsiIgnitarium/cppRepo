#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    vector<Node* > neighbours;

    Node(int v)
    {
        val = v;
    }
};

Node* cloneGraph(Node* node)
{
    if(node == NULL)
    {
        return NULL;
    }

    unordered_map<Node*, Node*> copied;

    //queue for bfs traversal
    queue<Node* > q;
    q.push(node);

    Node* copiedNode = new Node(node->val);
    copied[node] = copiedNode;

    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();

        //traverse neighbours
        for(auto neighbour : current->neighbours)
        {
            if(copied.find(neighbour) == copied.end())
            {
                Node* copiedNeighbour = new Node(neighbour->val);
                copied[neighbour] = copiedNeighbour;
                q.push(neighbour);
            }

            //for addin the neighbours to copied nodes
            copied[current]->neighbours.push_back(copied[neighbour]);
        }
    }

    return copied[node];
}

void printGraph(Node* node,unordered_map<Node*, bool>& visited)
{
    if(node == NULL || visited[node])
    {
        return;
    }

    visited[node] = true;
    cout << "Node: " << node->val << ", Neighbours: ";
    for (Node* neighbour : node->neighbours) {
        cout << neighbour->val << " ";
    }
    cout << endl;

    for (Node* neighbour : node->neighbours) {
        printGraph(neighbour, visited);
    }
}

int main()
{
    //creating a graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbours = {node2, node4};
    node2->neighbours = {node1, node3};
    node3->neighbours = {node2, node4};
    node4->neighbours = {node1, node3};

    Node* clonedGraph = cloneGraph(node1);

    unordered_map<Node*, bool> visited;
    printGraph(clonedGraph, visited);

    return 0;
}