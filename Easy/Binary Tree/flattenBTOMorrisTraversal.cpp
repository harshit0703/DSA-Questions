#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flattenBT(node* root){

    if(!root) return;

    node* curr = root;
    node* prev;

    while(curr){

       if(curr->left){
           prev = curr->left;
           while(prev->right) prev = prev->right;
           prev->right = curr->right;
           curr->right = curr->left;
           curr->left = NULL;
       }

       curr = curr->right;

    }

}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);

    inorder(root);
    cout << endl;
    flattenBT(root);
    inorder(root);

    return 0;
}