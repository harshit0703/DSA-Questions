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

int sum(node* root){
    if(root == NULL) return 0;
    int left = sum(root->left);
    int right = sum(root->right);
    return left + right + root->data;
}

void sumTree(node* root){
    if(root == NULL) return;

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    root->data = leftSum + rightSum;
    sumTree(root->left);
    sumTree(root->right);
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void sumTreeOpt(node* root, int* ans){
    if(root == NULL){
        *ans = 0;
        return;
    }

    int leftSum = 0;
    int rightSum = 0;

    sumTreeOpt(root->left, &leftSum);
    sumTreeOpt(root->right, &rightSum);

    *ans = leftSum + rightSum + root->data;
    root->data = leftSum + rightSum;
    
}

int main()
{
    node* root = new node(10);
    root->left = new node(-2);  
    root->left->left = new node(8);  
    root->left->right = new node(-4);
    root->right = new node(6);  
    root->right->left = new node(7);  
    root->right->right = new node(5);

    inorder(root);
    cout<<endl;
    int temp = 0;
    sumTreeOpt(root, &temp);
    inorder(root);

    return 0;
}