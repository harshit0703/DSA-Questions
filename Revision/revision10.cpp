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

vector<int> iterativeInorder(node* root){
    vector<int> inorder;
    node* temp = root;
    stack<node*> st;
    
    while(true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()){
                break;
            }
            temp = st.top();
            st.pop();
            inorder.push_back(temp->data);
            temp = temp->right;
        }
    }

    return inorder;
}

vector<int> iterativePostorder(node* root){
    vector<int> postorder;
    stack<node*>st1, st2;
    st1.push(root);

    while(!st1.empty()){
        node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left != NULL){
            st1.push(temp->left);
        }
        if(temp->right != NULL){
            st1.push(temp->right);
        }
    }

    while(!st2.empty()){
        node* ans = st2.top();
        st2.pop();
        postorder.push_back(ans->data);
    }


    return postorder;
}

int heightBT(node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = heightBT(root->left);
    int rHeight = heightBT(root->right);
    return max(lHeight, rHeight) + 1;
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

    vector<int> ans = iterativePostorder(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    cout<<heightBT(root);

    return 0;
}