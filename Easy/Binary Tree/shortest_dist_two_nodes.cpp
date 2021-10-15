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

node* lca(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* left_lca = lca(root->left, n1, n2);
    node* right_lca = lca(root->right, n1, n2);

    if(left_lca && right_lca){
        return root;
    }

    if(left_lca == NULL){
        return right_lca;
    }

    return left_lca;

}

int findDist(node*root, int k, int dist){
    if (root == NULL){
        return -1;
    }
    if(root->data == k){
        return dist;        // it means we have reached the node in the tree
    }

    // if the current node is not the node we need to check in both the sub trees for the node
    int left_dist = findDist(root->left, k, dist+1);
    int right_dist = findDist(root->right, k, dist+1);

    if(left_dist == -1){    
        return right_dist;  // since only one of the subtrees will have the given node one of the distance will be -1
    }

    return left_dist;

}

int shortestDist(node* root, int n1, int n2){
    // to find the shortest distance first we need to find  the lca
    node* Lca = lca(root, n1, n2);

    int d1 = findDist(Lca, n1, 0);
    int d2 = findDist(Lca, n2, 0);

    return d1 + d2;
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int n1 = 7;
    int n2 = 4;

    cout<<shortestDist(root, n1, n2);

    return 0;
}