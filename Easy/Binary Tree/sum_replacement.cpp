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

void sumReplacement(node* root){
    if(root == NULL){
        return ;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left != NULL){
        root->data += root->left->data;
    }

    if(root->right != NULL){
        root->data += root->right->data;
    }

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

    inorder(root);
    cout<<endl;
    sumReplacement(root);
    inorder(root);

    return 0;   
}