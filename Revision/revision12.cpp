#include<bits/stdc++.h>
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

node* LCA(node* root, node* n1, node* n2){
    if(root == NULL || root == n1 || root == n2){
        return root;
    }

    node* left = LCA(root->left, n1, n2);
    node* right = LCA(root->right, n1, n2);

    if(left && right){
        return root; 
    }

    if(left == NULL && right == NULL){
        return NULL;
    }

    if(left == NULL){
        return right;
    }

    return left;
}

int findDistance(node* lca, node* p, int dis){
    if(lca == NULL){
        return -1;
    }

    if(lca == p){
        return dis;
    }

    int Ldis = findDistance(lca->left, p, dis + 1);

    if(Ldis != -1){
        return Ldis;
    }

    return findDistance(lca->right, p, dis + 1);

}

// distance between any two nodes is their distance sum from the LCA

int distance(node* lca, node* n1, node* n2){
    if(lca == NULL){
        return -1;
    }

    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2;

}

void flatten(node* root){
    if (root == NULL){
        return ;
    }

    flatten(root->left);
    flatten(root->right);

    if(root->left != NULL){
        node* temp = root->left;
        root->left = NULL;

        node* ptr = root->right;
        root->right = temp;

        while(temp->right != NULL){
            temp = temp->right;
        }

        temp->right = ptr;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);

    node* n1 = new node(4);
    node* n2 = new node(5);

    node* ans = LCA(root, n1, n2);

    cout<<ans->data;

    return 0;
}