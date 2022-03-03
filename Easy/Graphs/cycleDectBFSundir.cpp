#include <bits/stdc++.h>
using namespace std;

bool cyclePresent(int n, vector<int> adj[], vector<int> &visited)
{
    queue<pair<int, int>> q;
    q.push({n, -1}); // starting point of the component;
    visited[n] = 1;

    while (!q.empty())
    {

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                q.push({it, node});
            }
            else
            {
                if (parent != it)
                    return true;
            }
        }
    }

    return false;
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

    int flag = 0;

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            if (cyclePresent(i, adj, visited))
            {
                cout << "cycle is present";
                flag = 1;
                break;
            }
        }
    }

    if (flag == 0)
        cout << "no cycle is present";

    return 0;
}