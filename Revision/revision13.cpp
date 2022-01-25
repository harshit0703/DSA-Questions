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

bool searchBST(node* root, int key){
    // TC = O(logN)
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data < key){
        return searchBST(root->right, key);
    }

    return searchBST(root->left, key);
}

node* deleteBST(node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data){
        root->left = deleteBST(root->left, key);
    }

    else if(key > root->data){
        root->right = deleteBST(root->right, key);
    }

    else{
        // since the root is now equal to the given key we have 3 possible cases

        // root is a leaf node

        // if(root->left == NULL && root->right == NULL){
        //     free(root);
        // }

        if(root->left == NULL ){
            node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL ){
            node* temp = root->left;
            free(root);
            return temp;
        }

        else{
            node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;  // inorder successor    
            }
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
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
    createBST(root, 6);
    createBST(root, 5);
    createBST(root, 7);
    // printBST(root);
    // inorder of bst is a sorted array
    // cout<<searchBST(root, 7);
    printBST(root);
    root = deleteBST(root, 1);
    printBST(root);
    return 0;
}