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

bool balancedHeight(node* root){
    if(root == NULL){
        return true;
    }

    if(balancedHeight(root->left) == false){
        return false;
    }

    if(balancedHeight(root->right) == false){
        return false;
    }

    int left_nodes = countNodes(root->left);
    int right_nodes = countNodes(root->right);

    int diff = abs(left_nodes - right_nodes);

    if(diff <= 1){
        return true;
    }
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

    cout<<balancedHeight(root);

    return 0;   
}