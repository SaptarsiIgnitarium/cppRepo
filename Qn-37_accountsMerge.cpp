#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findUpar(parent[node]);  //to compress the branch length
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)
        {
            return;
        }

        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_u] + size[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_u] + size[ulp_v];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& details)
{
    int n = details.size();
    DisjointSet ds(n);

    unordered_map<string, int> mapMailNode;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<details[i].size(); j++)
        {
            string mail = details[i][j];
            if(mapMailNode.find(mail) == mapMailNode.end())
            {
                mapMailNode[mail] = i;
            }
            else
            {
                ds.unionBySize(mapMailNode[mail], i);
            }
        }
    }

    vector<string> mergedMail[n];
    for(auto it : mapMailNode)
    {
        int node = ds.findUpar(it.second);
        mergedMail[node].push_back(it.first);
    }

    vector<vector<string>> ans;

    for(int i=0; i<n; i++)
    {
        if(mergedMail[i].size() == 0)
            continue;

        sort(mergedMail[i].begin(), mergedMail[i].end());

        vector<string> temp;
        temp.push_back(details[i][0]);
        for(auto it : mergedMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
        {"John", "j4@com"},
        {"Raj", "r1@com", "r2@com"},
        {"John", "j1@com", "j5@com"},
        {"Raj", "r2@com", "r3@com"},
        {"Mary", "m1@com"}
    };

    vector<vector<string>> result = accountsMerge(accounts);

    for(auto acc : result)
    {
        cout << acc[0] << " ";

        int size = acc.size();
        for(int i = 1; i< size; i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }

    return 0;
}