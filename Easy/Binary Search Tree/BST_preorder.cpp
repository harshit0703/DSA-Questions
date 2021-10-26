#include<iostream>
#include<climits>
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

node* BstFromPreorder(int preorder[], int* preorderIdx, int key, int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }

    node* root = NULL;
    if(key > min && key < max){
        root = new node(key);
        *preorderIdx = *preorderIdx + 1;
        if(*preorderIdx < n){
            root->left = BstFromPreorder(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);   //cap is on the max in left tree
        }
        if(*preorderIdx < n){
            root->right = BstFromPreorder(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);  //cap is on the min in right tre
        }
    }
    return root;
}

void printPreorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

/* 
        10
       /  \
      2    13
     /     /
     1    11
 */

int main(){
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    int key = preorder[0];
    node* root = BstFromPreorder(preorder, &preorderIdx, key, INT_MIN, INT_MAX, n);
    printPreorder(root);
    return 0;
}