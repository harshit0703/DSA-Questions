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

bool balanced(node* root){
    // O(n^2)
    if(root == NULL){
        return true;
    }

    if(balanced(root->left) && balanced(root->right)){
        int lHeight = heightBT(root->left);
        int rHeight = heightBT(root->right);
        int ans = abs(rHeight - lHeight);
        return ans <= 1;
    }

    return false;
}

int balancedOpt(node* root){
    // O(n)
    if(root == NULL){
        return 0;
    }
    int lHeight = balancedOpt(root->left);
    int rHeight = balancedOpt(root->right);
    if(lHeight == -1 || rHeight == -1){
        return -1;
    }
    if(abs(rHeight - lHeight) > 1){
        return -1;
    }

    return max(lHeight, rHeight) + 1;
}

int diameter(node* root, int &dia){
    if(root == NULL){
        return 0;
    }

    // diameter = lheight + rheight + 1

    int lHeight = diameter(root->left, dia);
    int rHeight = diameter(root->right, dia);

    dia = max(dia, lHeight + rHeight + 1);
    // we included the current node and make a complete path

    return 1 + max(lHeight, rHeight);
    // did not make a complete path
}

int maxPathSum(node* root, int &sum){
    if(root == NULL){
        return 0;
    }

    int lPath = max(0, (root->left, sum));
    int rPath = max(0, (root->right, sum));

    sum = max(sum, root->data + lPath + rPath);

    return root->data + max(lPath, rPath);
}

bool identicalTrees(node* root1, node* root2){
    if(root1 == NULL || root2 == NULL){
        return (root1 == root2);
    }

    if(identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right)){
        return (root1->data == root2->data);
    }

    return false;

}

vector<int> zigZag(node* root){
    vector<int> v;
    stack<int> st;
    queue<node*> q;
    int lvl = 0;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp != NULL){
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }

            if(lvl % 2 == 0){
                v.push_back(temp->data);
            }
            else{
                st.push(temp->data);
            }
        }
        else{
            if(q.empty()){
                break;
            }
            if(lvl % 2 != 0){
                while(!st.empty()){
                    int data = st.top();
                    st.pop();
                    v.push_back(data);
                }
            }
            q.push(NULL);
            lvl++;
        }
    }

    return v;
}

vector<int> leftView(node* root){
    if(root == NULL){
        return {};
    }

    vector<int>ans;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    node* prev = NULL;

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp != NULL){
            if(prev == NULL){
                ans.push_back(temp->data);
            }

            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }           

        }

        else{
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }

        prev = temp;

    }

    return ans;
}


vector<int> rightView(node* root){
    if(root == NULL){
        return {};
    }

    vector<int>ans;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    node* prev = NULL;

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp != NULL){

            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }           

        }

        else{
            ans.push_back(prev->data);
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }

        prev = temp;

    }

    return ans;
}


node* LCA(node* root, node* p, node* q){
    if(root == NULL || root == p || root == q){
        return root;
    }

    node* left = LCA(root->left, p, q);
    node* right = LCA(root->right, p, q);

    if(left && right){
        return root;
    }
    else if (left == NULL){
        return right;
    }

    return left;
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

    // vector<int> ans = iterativePostorder(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    
    // cout<<heightBT(root)<<endl;

    // if(balanced(root)){
    //     cout<<"the given tree is a balanced tree"<<endl;
    // }

    // cout<<balancedOpt(root)<<endl;
    // // if balancedOpt == -1 then the tree is not balanced

    // int dia = 0;
    // diameter(root, dia);
    // cout<<dia<<endl;

    // int sum = 0;
    // maxPathSum(root, sum);
    // cout<<sum<<endl;

    // vector<int> spiral = zigZag(root);

    // for(int i : spiral){
    //     cout<<i<<" ";
    // }

    // vector<int> left = leftView(root);

    // for(int i : left){
    //     cout<<i<<" ";
    // }

    vector<int> right = rightView(root);

    for(int i : right){
        cout<<i<<" ";
    }

    node* ans = LCA(root, root->left, root->right);
    cout<<ans->data;

    return 0;
}