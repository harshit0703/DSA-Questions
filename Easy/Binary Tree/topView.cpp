#include <bits/stdc++.h>
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

vector<int> topView(node* root){
    if(root == NULL){
        return {};
    }

    queue<pair<node*, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while(!q.empty()){
        auto i = q.front();
        q.pop();
        node* temp = i.first;
        int lvl = i.second;

        if(mp.find(lvl) == mp.end()){
            mp[lvl] = temp->data;
            // since we only need the top value of every column
        }

        if(temp->left != NULL){
            q.push({temp->left, lvl - 1});
        } 

        if(temp->right != NULL){
            q.push({temp->right, lvl + 1});
        }
    }

    vector<int> ans;
    for(auto i : mp){
        ans.push_back(i.second);
    }

    return ans;

}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    vector<int> ans = topView(root);

    for(int i : ans){
        cout<<i<<" ";
    }

    return 0;
}