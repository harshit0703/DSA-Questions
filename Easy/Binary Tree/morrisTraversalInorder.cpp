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

void morrisTraversalInorder(node* root){
    if(root == NULL) return;

    node* curr = root;
    node* prev;

    while(curr){

        if(curr->left == NULL){
            // no inorder successor exist
            cout<<curr->data<<" ";
            curr = curr->right;
        }

        else{

            prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
                // finding the inorder successor
            }

            if(prev->right == NULL){
                // change the links
                prev->right = curr;
                curr = curr->left;
            }

            else{
                // reverse the links made previously
                prev->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }

        }

    }

}

void inorder(node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);  
    root->left->left = new node(4);  
    root->left->right = new node(5);
    root->right = new node(3);  

    inorder(root);
    cout<<endl;
    morrisTraversalInorder(root);

    return 0;
}