#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;
    
    vector<int> adj[nodes];
    vector<int> visited(nodes + 1, 0);

    int x, y;

    for(int i = 0; i < edges; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= nodes; i++){
        if(!visited[i]){
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()){
                int temp = q.front(); q.pop();
                cout<<temp<<endl;
                for(auto it : adj[temp]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }

    return 0;
}