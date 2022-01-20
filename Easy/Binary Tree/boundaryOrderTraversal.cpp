#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(node* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}

void leftBoundary(node* root, vector<int> &res){
    node* temp = root->left;

    while(temp != NULL){
        if(!isLeaf(temp)){
            res.push_back(temp->data);
            if(temp->left != NULL){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
    }
}

void rightBoundary(node* root, vector<int> &res){
    node* temp = root->right;
    vector<int> ans;

    while(temp != NULL){
        if(!isLeaf(temp)){
            ans.push_back(temp->data);
            if(temp->right != NULL){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
    }

    for(int i = ans.size() - 1; i >= 0; i--){
        res.push_back(ans[i]);  // right boundary should be added in reverse
    }
}

void leaves(node* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left != NULL){
        leaves(root->left, res);
    }

    if(root->right != NULL){
        leaves(root->right, res);
    }

}

vector<int> boundaryTraversal(node* root){
    if(root == NULL){
        return {};
    }

    vector<int> res;
    res.push_back(root->data);
    // we need to travel anticlockwise 

    // left boundary
    leftBoundary(root, res);

    // leaves
    leaves(root, res);

    // right boundary in reverse order
    rightBoundary(root, res);

    return res;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    vector<int> ans = boundaryTraversal(root);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}