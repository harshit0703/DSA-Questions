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

node* stringToBt(string str){
    if(str.length() == 0) return NULL;
    char ch = str[0];
    int val = ch - '0';
    node* root = new node(val);
    if(str.length() == 1) return root;

    int i = 1;
    while(str[i] != ')') i++;
    string left = str.substr(2, i);
    root->left = stringToBt(left);
    if(i+2 < str.length()){
        string right = str.substr(i + 2, str.length()-1);
        root->right = stringToBt(right);
    }

    return root;
    
}

void preorder(node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    node* root = stringToBt("4(2(3)(1))(6(5))");
    preorder(root);
    return 0;
}