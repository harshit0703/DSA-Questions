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


void calcNodes(node* root, node** prev, node** start, node** mid, node** last){       //double asterict is pointer to another pointer
    if(root == NULL){
        return;
    }
    calcNodes(root->left, prev, start, mid, last);

    if(*prev && root->data < (*prev)->data){
        if(!*start){
            *start = *prev;
            *mid = root;                       //in this case this is the first encounter with the misplaced value in the BST
        }
        else{
            *last = root;
        }
    }

    *prev = root;
    calcNodes(root->right, prev, start, mid, last);

}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restoreBST(node* root){
    if(root == NULL){
        return;
    }
    node* prev, *start, *mid, *last;
    prev = NULL;
    start = NULL;
    mid = NULL;
    last = NULL;
    
    calcNodes(root, &prev, &start, &mid, &last);

    if(start && last){
        swap(&(start->data), &(last->data));        //if non-adjacent nodes are swapped
    }
    else if(start && mid){
        swap(&(start->data), &(mid->data));         //if adjacent nodes are swapped
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

int main(){
    node* root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);

    inorder(root);
    restoreBST(root);
    cout<<endl;
    inorder(root);

    return 0;
}