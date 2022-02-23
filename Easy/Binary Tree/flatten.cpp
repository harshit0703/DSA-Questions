#include<iostream>
#include<algorithm>
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


void flatten(node*root){
    
    if(!root) return;

    static node *prev = NULL;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;

    prev = root;

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
             /     \
            4       7
     */
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    root->right->right = new node(7);

    inorder(root);
    cout<<endl;
    flatten(root);
    inorder(root);

    return 0;   
}