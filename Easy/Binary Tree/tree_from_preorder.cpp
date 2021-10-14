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

int findPos(int inorder[], int start, int end, int val){
    for(int i = start; i<=end; i++){
        if(inorder[i] == val){
            return i;
        }
    }
    return -1;
}

node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if(start > end){
        return NULL;        // base condition
    }
    int val = preorder[idx];
    idx++;

    node* n = new node(val);
    if(start == end){
        return n;           // only one element remaining we dont need to find the left and right subtree
    }

    int pos = findPos(inorder, start, end, val);

    n->left = buildTree(preorder, inorder, start, pos-1);
    n->right = buildTree(preorder, inorder, pos+1, end);

    return n;

}

void inorderPrint(node* root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    node* root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}
