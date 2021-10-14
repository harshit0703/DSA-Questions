#include <iostream>
#include<algorithm>
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

int findHeight(node* root){
    if(root == NULL){
        return 0;
    }
    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);
    int height = max(left_height, right_height);
    return height + 1;      // taking the current node in consideration
}

int findDiameter(node* root){
    // since in this function we are using another function for finding the height the TC = O(n^2)
    if(root == NULL){
        return 0;
    }
    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);
    int curr_diameter = left_height + right_height + 1;

    int left_diameter = findDiameter(root->left);
    int right_diameter = findDiameter(root->right);

    return max(curr_diameter, max(left_diameter, right_diameter));
}

int findDiameterOptimized(node* root, int* height){
    // since here we are calculating the height within the same function using the pointer TC = O(n)
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int left_height = 0 , right_height = 0;
    int left_diameter = findDiameterOptimized(root->left, &left_height);
    int right_diameter = findDiameterOptimized(root->right, &right_height);

    *height = max(left_height, right_height) + 1;
    int curr_diameter = left_height + right_height + 1;

    return max(curr_diameter, max(left_diameter, right_diameter));
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
                     \
                      8
     */
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(8);
    
    cout<<findHeight(root)<<endl;

    // diameter is the longest path between the two leaf nodes and it can be formed by both including as well as excluding the root node

    cout<<findDiameter(root)<<endl;
    
    int height = 0;
    cout<<findDiameterOptimized(root, &height);

    return 0;
}