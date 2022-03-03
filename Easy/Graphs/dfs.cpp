#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &visited)
{
    cout << node << endl;
    visited[node] = 1;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int> adj[nodes];
    vector<int> visited(nodes + 1, 0);

    int x, y;

    for (int i = 0; i < edges; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
        }
    }

    return 0;
}