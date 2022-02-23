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

void morrisTraversalPreorder(node *root)
{
    if(root == NULL) return;


    while(root){

        if(root->left == NULL){
            // no inorder successor exist
            cout << root->data << " ";
            root = root->right;
        }

        else{

            node* curr = root->left;
            while (curr->right != NULL && curr->right != root)
            {
                curr = curr->right;
                // finding the inorder successor
            }

            if (curr->right == NULL)
            {
                // change the links
                cout<<root->data<<" ";
                curr->right = root;
                root = root->left;
            }

            else{
                // reverse the links made previously
                curr->right = NULL;
                root = root->right;
            }

        }

    }
}

void preorder(node* root){
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);  
    root->left->left = new node(4);  
    root->left->right = new node(5);
    root->right = new node(3);  

    preorder(root);
    cout<<endl;
    morrisTraversalPreorder(root);

    return 0;
}