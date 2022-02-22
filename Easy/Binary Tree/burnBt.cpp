#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *mapParents(node *root, int target, map<node *, node *> &childToParent)
{
    queue<node*> q;
    q.push(root);
    childToParent[root] = NULL;
    node* ans = NULL;

    while(!q.empty()){
        node* temp = q.front(); q.pop();
        if(temp->data == target) ans = temp;
        if(temp->left){
            q.push(temp->left);
            childToParent[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            childToParent[temp->right] = temp;
        }
    }

    return ans;
}

int calcTime(node *target, map<node *, node *> &childToParent)
{
    int time = 0;
    queue<node*> q; q.push(target);
    map<node*, bool> isVisited;
    isVisited[target] = true;

    while(!q.empty()){
        // we have to check for three neighbors left right and parent
        bool flag = false;
        for(int i = 0; i < q.size(); i++){
            node* temp = q.front(); q.pop();
        if(temp->left && !isVisited[temp->left]){
            q.push(temp->left);
            isVisited[temp->left] = true;
            flag = true;
        }

        if(temp->right && !isVisited[temp->right]){
            q.push(temp->right);
            isVisited[temp->right] = true;
            flag = true;
        }

        if(childToParent[temp] && !isVisited[childToParent[temp]]){
            q.push(childToParent[temp]);
            isVisited[childToParent[temp]] = true;
            flag = true;
        }
        }
        if(flag == true) time++;
    }

    return time;
}

int burnBt(node* root,int target){
    if(root == NULL) return 0;

    // the whole problem is divided into three steps
    // first to keep a track for all the parents
    // finding the target node
    // burning the binary tree and calculating the time accordingly
    map<node*, node*> childToParent;
    node* res = mapParents(root, target, childToParent);
    int ans = calcTime(res, childToParent);
    for (auto i : childToParent)
    {
        cout << i.first << " " << i.second << endl;
    }
    return ans;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(5);
    root->right->right->right = new node(6);
    map<node *, node *> x;
    x[root] = root->right;
    x[root->right] = root->left;
    for(auto i : x){
        cout<<i.first->data<<" "<<i.second->data<<endl;
    }
    cout<<burnBt(root, 4);
    return 0;
}