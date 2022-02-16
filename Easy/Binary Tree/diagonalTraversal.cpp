#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> diagonal(node* root){
    if(root == NULL) return {};

    map<int, map<int, multiset<int>>> mp;
    queue<pair<node*, pair<int, int>>>q;

    q.push({root, {0, 0}});
    vector<vector<int>> res;

    while(!q.empty()){
        auto i = q.front(); q.pop();
        node* temp = i.first;
        int x = i.second.first;
        int y = i.second.second;
        int diff = abs(x - y);
        if(temp->left) q.push({temp->left, {x-1, y+1}});
        if(temp->right) q.push({temp->right, {x+1, y+1}});

        mp[diff][y].insert(temp->data);
    }

    for(auto i : mp){
        vector<int> ans;
        for(auto j : i.second){
            ans.insert(ans.end(), j.second.begin(), j.second.end());
        }
        res.push_back(ans);
    }

    return res;

}

int main()
{
    node *root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    root->right->left = new node(6);
    root->right->left->left = new node(4);
    root->right->left->right = new node(7);

    vector<vector<int>> v = diagonal(root);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}