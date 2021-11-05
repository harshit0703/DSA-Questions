#include<iostream>
#include<stack>
#include<queue>
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

node* createBST(node* root, int n){
    if(root == NULL){
        root = new node(n);
        return root;
    }
    if(n<root->data){
        root->left = createBST(root->left, n);
    }
    else{
        root->right = createBST(root->right, n);
    }

}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void zigzag(node* root){
    if(root == NULL){
        return;
    }
    bool leftToRight = true;
    stack<node*>currlvl;
    stack<node*>nextlvl;

    currlvl.push(root);
    while(!currlvl.empty()){
        node* n = currlvl.top();
        currlvl.pop();
        if(n){
            cout<<n->data<<" ";
            if(leftToRight){
                if(n->left){
                    nextlvl.push(n->left);
                }
                if(n->right){
                    nextlvl.push(n->right);
                }
            }
            else{
                if(n->right){
                    nextlvl.push(n->right);
                }
                if(n->left){
                    nextlvl.push(n->left);
                }
            }
        }
        if(currlvl.empty()){
            swap(currlvl, nextlvl);
            leftToRight = !leftToRight;
        }
    }
}

int main(){
    node* root = NULL;
    root = createBST(root, 5);
    createBST(root, 3);
    createBST(root, 4);
    createBST(root, 6);
    createBST(root, 8);
    inorder(root);
    cout<<endl;
    zigzag(root);
    return 0;
}