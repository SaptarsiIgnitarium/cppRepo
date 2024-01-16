#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, int vis[], stack<int>& st, vector<int> adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])   //will give the nodes connected to adj[node]
    {
        if(!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}

bool isPossible(int V, vector<pair<int, int>>& prerequisites)
{
    vector<int> adj[V];
    for (auto it : prerequisites)
    {
        adj[it.first].push_back(it.second);
    }

    int vis[V] = {0};
    stack<int> st;
    for(int i=0; i<V; i++)
    {
        if(!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    if(ans.size() == V)
    {
        return true;
    }else   
    { 
        return false;
    }
}

int main()
{
    int numTasks = 2;
 
    vector<pair<int, int>> prerequisites = {{1,0},{0,1}};
 
    if (isPossible(numTasks, prerequisites)) {
        cout << "Possible to finish all tasks";
    }
    else {
        cout << "Impossible to finish all tasks";
    }
 
    return 0;
}