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

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

node* mirror(node * root){
    if(root == NULL) return root;

    node* left = mirror(root->right);
    node* right = mirror(root->left);

    root->left = left;
    root->right = right;
    
    return root;
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    inorder(root);
    cout<<endl;
    node* root2 = mirror(root);
    inorder(root2);
    return 0;
}