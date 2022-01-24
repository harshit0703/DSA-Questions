#include <iostream>
#include <queue>
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
    if(root == NULL){
        return false;
    }

    if(root->left == NULL && root->right == NULL){
        return true;
    }

    return false;
}



int main()
{
    // here we can see the importance of recursion
    /*
                1
               / \
              2   3
             /\   /\
            4  5  6 7
           /         \
          4           7
     */
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(7);

    cout<<maxWidth(root);

    return 0;
}