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

node* createBST(node* root, int val){
    if(root == NULL){
        node* root = new node(val);
        return root;
    }

    if(val < root->data){
        root->left = createBST(root->left, val);
    }

    else{
        root->right = createBST(root->right, val);
    }

    return root;

}

void printBST(node* root){
    if(root == NULL){
        return ;
    }

    printBST(root->left);
    cout<<root->data<<" ";
    printBST(root->right);
}

int main()
{
    node* root = NULL;
    root = createBST(root, 3);
    createBST(root, 2);
    createBST(root, 1);
    createBST(root, 4);
    createBST(root, 5);
    printBST(root);
    // inorder of bst is a sorted array
    return 0;
}