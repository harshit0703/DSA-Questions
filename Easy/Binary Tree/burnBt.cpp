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

unordered_map<node*, node*> childToParent;

node* mapParents(node* root, node* target){
    queue<node*> q;
    q.push(root);
    childToParent[root] = NULL;
    node* ans;

    while(!q.empty()){
        node* temp = q.front(); q.pop();
        if(temp == target) ans = temp;
        if(temp->left){
            q.push(temp->left);
            childToParent[temp->left] = root;
        }
        if(temp->right){
            q.push(temp->right);
            childToParent[temp->right] = root;
        }
    }

    return ans;
}

int calcTime(node* target){
    int time = 0;
    queue<node*> q; q.push(target);
    unordered_map<node*, bool> isVisited;
    isVisited[target] = true;

    while(!q.empty()){
        // we have to check for three neighbors left right and parent
        bool flag = false;
        for(int i = 0; i < q.size(); i++){
            node* temp = q.front(); q.pop();
        if(temp->left && isVisited.find(temp->left) != isVisited.end()){
            q.push(temp->left);
            isVisited[temp->left] = true;
            flag = true;
        }

        if(temp->right && isVisited.find(temp->right) != isVisited.end()){
            q.push(temp->right);
            isVisited[temp->right] = true;
            flag = true;
        }

        if(childToParent.find(temp) != childToParent.end() && isVisited.find(childToParent[temp]) != isVisited.end()){
            q.push(childToParent[temp]);
            isVisited[childToParent[temp]] = true;
            flag = true;
        }
        }
        if(flag == true) time++;
    }

    return time;
}

int burnBt(node* root,node* target){
    if(root == NULL) return 0;

    // the whole problem is divided into three steps
    // first to keep a track for all the parents
    // finding the target node
    // burning the binary tree and calculating the time accordingly

    node* res = mapParents(root, target);
    int ans = calcTime(res);
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
    node* target = new node(4);
    cout<<burnBt(root, target);
    return 0;
}