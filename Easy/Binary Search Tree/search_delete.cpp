#include<iostream>
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

node* insert(node*root, int n){
    if(root == NULL){
        node* root = new node(n);
        return root;
    }
    if(root->data < n){
        root->right = insert(root->right, n);
    }else{
        root->left = insert(root->left, n);
    }
}

bool search(node* root, int key){
    if(root == NULL){
        return false;       // base condition
    }
    if(root->data == key){
        return true;
    }
    if(key > root->data){
        return search(root->right, key);
    }
    return search(root->left, key);
}

node* minValue(node* root){
    node* temp = root;
    while(root != NULL && root->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* deleteInBST(node* root, int key){
    if(root == NULL){
        return root;        // base condition
    }
    if(key > root->data){
        root->right = deleteInBST(root->right, key);
    }
    else if(key < root->data){
        root->left = deleteInBST(root->left, key);
    }
    else{
       if(root->left == NULL && root->right == NULL){
           return NULL;     // root with no child
       }
       else if(root->left == NULL){
           node*temp = root->right;
           free(root);
           return temp;     // root with only right child
       }
       else if(root->right == NULL){
           node*temp = root->left;
           free(root);
           return temp;     // root with only left child
       }
       else{
           node*temp = minValue(root->right);   // inorder successor will be the min value in the right subtree
           root->data = temp->data;     
           root->right = deleteInBST(root->right, temp->data);  //after we overwrite the root win inorder successor we need to delete it
       }
    }
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
    node* root = NULL;
    root = insert(root,5);
    insert(root,3);
    insert(root,4);
    insert(root,1);
    insert(root,7);
    insert(root,9);
    inorder(root);
    cout<<endl;
    if(search(root, 7)){
        cout<<"Key is present in the tree."<<endl;
    }else{
        cout<<"Key is not present in the tree."<<endl;
    }
    deleteInBST(root,7);
    inorder(root);
    return 0;
}