#include<iostream>
#include<vector>
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
}

node* bstSortedArr(vector<int>sorted_arr, int st, int end){
    int mid = (st + end) / 2;       // similar to binary search approach
    if(st > end){
        return NULL;
    }
    node* root = new node(sorted_arr[mid]);
    root->left = bstSortedArr(sorted_arr, st, mid-1);
    root->right = bstSortedArr(sorted_arr, mid+1, end);
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
    vector<int> sorted_arr = {1, 3, 5, 6, 9};
    node* root = bstSortedArr(sorted_arr, 0, 4);
    inorder(root);

    return 0;
}