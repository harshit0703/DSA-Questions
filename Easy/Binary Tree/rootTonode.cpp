#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

bool getPath(node* root, vector<int> &ans, int key){
    if(root == NULL){
        return false;
    }

    ans.push_back(root->data);

    if(root->data == key){
        return true;
    }

    if(getPath(root->left, ans, key) || getPath(root->right, ans, key)){
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> rootToNode(node* root, int key){
    vector<int> ans;
    if(root == NULL){
        return {};
    }

    getPath(root, ans, key);
    return ans;
}

int main(){
    // here we can see the importance of recursion
    /* 
                1
               / \
              2   3
             /\   /\
            4  5  6 7
     */
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<int> ans = rootToNode(root, 6);

    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;   
}