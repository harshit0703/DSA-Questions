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

void levelOrder(node* root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    if(q.empty()){
        q.push(root);
        q.push(NULL);  // marking the end of 0th level
    }

    while(!q.empty()){
        node* n = q.front();
        q.pop();
        if(n != NULL){
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
            cout<<n->data<<" ";
        }
        else if(!q.empty()){
            q.push(NULL);
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
    struct node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);

    levelOrder(root);
    return 0;   
}