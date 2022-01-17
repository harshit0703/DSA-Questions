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

void preorder(node* &root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* &root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void postorder(node* &root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

void levelorder(node* &root){
    if(root == NULL){
        return;
    }
    queue<node*>q;
    if(q.empty()){
        q.push(root);
        q.push(NULL);
    }
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp != NULL){
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            cout<<temp->data<<" ";
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

void iterativePreorder(node* &root){
    if(root == NULL){
        return;
    }
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        if(temp->right != NULL){
            st.push(temp->right);
        }
        if(temp->left != NULL){
            st.push(temp->left);
        }
        cout<<temp->data<<" ";
    }
}

void iterativeInorder(node* root){
    if(root == NULL){
        return;
    }
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        if(temp->left != NULL){
            st.push(temp->left);
        }
        // now topmost node in the stack will be the left most node
        cout<<temp->data;
        if(temp->right != NULL){
            st.push(temp->right);
        }
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(5);
    // preorder(root);
    // inorder(root);
    // postorder(root);

    // levelorder(root);
    // iterativePreorder(root);
    // iterativeInorder(root);

    return 0;
}