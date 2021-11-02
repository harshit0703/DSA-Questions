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

node* insert(node* root, int n){
    if(root == NULL){
        root = new node(n);
        return root;
    }
    if(n > root->data){
        root->right = insert(root->right, n);
    }
    else{
        root->left = insert(root->left, n);
    }
}

bool checkBST(node* root, node* min, node* max){
    if(root == NULL){
        return true;
    }
    
    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool left = checkBST(root->left, min, root);
    bool right = checkBST(root->right, root, max);

    return left && right;
}

int main(){
    node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 4);
    insert(root, 7);
    insert(root, 8);
    insert(root, 1);
    if(checkBST(root, NULL, NULL)){
        cout<<"valid bst";
    }else{
        cout<<"invalid bst";
    }
    return 0;
}