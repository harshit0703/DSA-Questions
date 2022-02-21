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

node* solve(node* root){
    if(root == NULL) return NULL;
    node* leftDll = solve(root->left);
    if(leftDll){
        node* temp = leftDll;
        while(temp->right) temp = temp->right;
        temp->right = root;
        root->left = temp;
    }else{
        root->left = leftDll;
    }

    node* rightDll = solve(root->right);
    root->right = rightDll;
    if(rightDll) rightDll->left = root;

    node* newRoot = root;
    while(newRoot->left) newRoot = newRoot->left;
    return newRoot;
}

void preorder(node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{   
    node* root = new node(1);
    node* newroot = solve(root);
    preorder(root);
    return 0;
}