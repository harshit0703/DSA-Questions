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

    // since we are visiting every node one time TC = O(n)

    if(root == NULL){
        return NULL;        // base condition 
    }

    if(root->data == n1 || root->data == n2){
        return root;        // if the current node is one of the two nodes we will return it
    }

    node* left_lca = lca(root->left, n1, n2);       // if not then we will need to check for the left and right subtrees
    node* right_lca = lca(root->right, n1, n2);

    if(left_lca && right_lca){
        return root;
        }               //if both left and right lca exist it means the two nodes are present in the sub tree and hence the 
                        //current node is the lca
    if(left_lca == NULL){
        return right_lca;
    }

    return left_lca;

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

    node*ans = lca(root, n1, n2);

    cout<<ans->data;

    return 0;
}