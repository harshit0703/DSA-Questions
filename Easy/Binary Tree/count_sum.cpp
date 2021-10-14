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

int countNodes(node* root){
    if(root == NULL){
        return 0;
    }
    int nodes = 0;
    nodes += countNodes(root->left) + countNodes(root->right);
    return nodes + 1;         // for the current node
}

int sumNodes(node* root){
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    sum += sumNodes(root->left) + sumNodes(root->right);
    return sum + root->data;
}

int main(){
    // here we can see the importance of recursion
    /* 
                1
               / \
              2   3
             /\   /\
            4  5  6 7
     */
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<countNodes(root);
    cout<<endl<<sumNodes(root);

    return 0;   
}