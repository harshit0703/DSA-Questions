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

vector<vector<int>> verticalOrder(node* root){
    queue<pair<node*, pair<int, int>>> q;
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> mp;

    q.push({root, {0, 0}});

    while(!q.empty()){

        auto temp = q.front();
        q.pop();
        node* ptr = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;

        if(ptr->left != NULL){
            q.push({ptr->left, {x - 1, y + 1}});
        }

        if(ptr->right != NULL){
            q.push({ptr->right, {x + 1, y + 1}});
        }

        mp[x][y].insert(ptr->data);

    }

    for(auto i : mp){
        vector<int> res;
        for(auto j : i.second){
            res.insert(res.end(), j.second.begin(), j.second.end());
        }
        ans.push_back(res);
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

    vector<vector<int>> v = verticalOrder(root);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}