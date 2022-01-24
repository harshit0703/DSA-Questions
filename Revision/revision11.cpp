#include<bits/stdc++.h>
using namespace std;

// binary tree is a heiarchial data structure in which each node has  a max of 2 children these children are pointed to with the help of two pointers i.e left and right

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

// in order to traverse through a tree we have 4 kind of traversals in which three are recursive and 1 is iterative

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);    
    preorder(root->right);    
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    cout<<root->data<<" ";    
    preorder(root->right);    
}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    preorder(root->left);    
    preorder(root->right);
    cout<<root->data<<" ";    
}

void lvlorder(node* root){
    if(root == NULL){
        return;
    }

    // an external data structure is required here
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        cout<<temp->data<<" ";
    }
}

void allTraversal(node* root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder){
    if(root == NULL){
        return;
    }

    stack<pair<node*, int>> q;
    q.push({root, 1});

    while(!q.empty()){
        auto temp = q.top();
        node* ptr = temp.first;
        int val = temp.second;

        // everything depends on this val

        if(val == 1){
            preorder.push_back(ptr->data);
            q.top().second++;
            if(ptr->left){
                q.push({ptr->left, 1});
            }
        }
        else if (val == 2){
            inorder.push_back(ptr->data);
            q.top().second++;
            if(ptr->right){
                q.push({ptr->right, 1});
            }
        }
        else{
            postorder.push_back(ptr->data);
            q.pop();
        }
    }
}

int search(vector<int> in, int st, int en, int val){
    for(int i = st; i <= en; i++){
        if(in[i] == val){
            return i;
        }
    }
    return -1;
}

node* inpre(vector<int> pre, vector<int> in, int st, int en){
    if(st > en){
        return NULL;
    }
    static int curr = 0;
    int val = pre[curr];
    curr++;
    node* root = new node(val);

    if(st == en){
        return root; // leaf node
    }

    int pos = search(in, st, en, val);

    root->left = inpre(pre, in, st, pos - 1);
    root->right = inpre(pre, in, pos + 1, en);

    return root;

}

node* inpost(vector<int> post, vector<int> in, int st, int en){
    if(st > en){
        return NULL;
    }
    static int curr = 4;
    curr--;
    int val = post[curr];
    node* root = new node(val);

    if(st == en){
        return root;
    }

    int pos = search(in, st, en, val);

    root->right = inpost(post, in, pos + 1, en);
    root->left = inpost(post, in, st, pos - 1);

    return root;

}

int countNodes(node* root){
    if(root == NULL){
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(node* root){
    if(root == NULL){
        return 0;
    }

    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

void sumReplacement(node* root){
    if(root == NULL){
        return;
    }
    sumReplacement(root->left);
    sumReplacement(root->right);
    if(root->left != NULL){
        root->data += root->left->data;
    }

    if(root->right != NULL){
        root->data += root->right->data;
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right = new node(3);
    root->right->left = new node(6);
    root->right->right = new node(7);
    // preorder(root);
    // inorder(root);
    // postorder(root);
    // lvlorder(root);
    // vector<int> pre, post, in;
    // allTraversal(root, pre, in, post);
    // for(auto i : in){
    //     cout<<i<<" ";
    // }
    // cout<<countNodes(root);
    // cout<<sumNodes(root);
    // cout<<height(root);
    // cout<<diameter(root);
    // sumReplacement(root);
    // preorder(root);
    return 0;
}