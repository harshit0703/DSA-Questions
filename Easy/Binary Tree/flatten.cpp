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
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;     // if single element is present in the tree there is no need to flatten it
    }

    if(root->left != NULL){
        flatten(root->left);

        node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }
        t->right = temp;

    }

    flatten(root->right);

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