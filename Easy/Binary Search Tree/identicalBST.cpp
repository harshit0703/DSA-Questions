#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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

node *createBST(node *root, int n)
{
    if (root == NULL)
    {
        root = new node(n);
        return root;
    }
    if (n < root->data)
    {
        root->left = createBST(root->left, n);
    }
    else
    {
        root->right = createBST(root->right, n);
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isIdentical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right)){
        if(root1->data == root2->data){
            return true;
        }else{
            return false;
        }
    }
    return false;
}

int main()
{
    node *root1 = NULL;
    root1 = createBST(root1, 5);
    createBST(root1, 3);
    createBST(root1, 4);
    createBST(root1, 6);
    createBST(root1, 8);

    node*root2 = NULL;
    root2 = createBST(root2, 5);
    createBST(root2, 3);
    createBST(root2, 4);
    createBST(root2, 6);
    createBST(root2, 9);

    if(isIdentical(root1, root2)){
        cout<<"Identical binary search trees";
    }else{
        cout<<"Non-Identical binary search trees";
    }
    return 0;
}