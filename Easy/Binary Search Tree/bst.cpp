#include<iostream>
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

node* insert(node* root, int val){
    if(root == NULL){
        root = new node(val);
        return root;
    }

    if(root->data > val){
        // update root->left
        root->left = insert(root->left, val);
    }
    else{
        //else update root right
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 4);
    insert(root, 7);
    insert(root, 8);
    insert(root, 1);

    inorder(root);
    // inorder traversal of bst will always provide sorted data members

    return 0;
}