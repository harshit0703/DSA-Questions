#include<iostream>
#include<algorithm>
#include<climits>
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

int maxPathUtil(node*root, int& ans){
    
    if(root == NULL){
        return 0;
    }

    int left = maxPathUtil(root->left, ans);
    int right = maxPathUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;

}

int maxSumPath(node* root){

    int ans = INT_MIN;
    maxPathUtil(root, ans);
    return ans;

}

int main(){
    // here we can see the importance of recursion
    /* 
                1
               / \
              2   3
             /     \
            4       7
     */
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->right = new node(3);
    root->right->right = new node(7);

    cout<<maxSumPath(root);

    return 0;   
}