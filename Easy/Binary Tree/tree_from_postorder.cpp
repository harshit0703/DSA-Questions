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

node* buildTree(int postorder[], int inorder[], int start, int end){
    static int idx = 4;
    if(start > end){
        return NULL;        // base condition
    }
    int val = postorder[idx];
    idx--;

    node* n = new node(val);
    if(start == end){
        return n;           // only one element remaining we dont need to find the left and right subtree
    }

    int pos = findPos(inorder, start, end, val);

    n->right = buildTree(postorder, inorder, pos+1, end);
    n->left = buildTree(postorder, inorder, start, pos - 1);

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
    // post order is exactly opposite to preorder as the root element is present at the end of the postorder array we need to start traversing from the right
    
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    node* root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}
