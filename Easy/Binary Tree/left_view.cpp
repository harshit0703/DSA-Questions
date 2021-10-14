#include<iostream>
#include<queue>
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

void leftView(node* root){
    // we will be using level order traversal and show the rightmost element at each level
    if(root == NULL){
        return ;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            node* curr = q.front();
            q.pop();
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
            if(i == 0){
                cout<<curr->data<<" ";
            }
        }
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

    leftView(root);

    return 0;   
}