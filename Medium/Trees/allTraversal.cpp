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

void allTraversal(node* root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder){

    stack<pair<node*, int>>st;
    st.push({root, 1});

    while(!st.empty()){

        // 3 cases depending upon the second value of the pair at the top of the stack

        if(st.top().second == 1){
            
            // preorder
            st.top().second++;
            preorder.push_back(st.top().first->data);

            if(st.top().first->left != NULL){
                st.push({st.top().first->left, 1});
            }

        }

        else if(st.top().second == 2){

            //inorder
            st.top().second++;
            inorder.push_back(st.top().first->data);

            if(st.top().first->right != NULL){
                st.push({st.top().first->right, 1});
            }

        }

        else{
            
            //postorder

            postorder.push_back(st.top().first->data);
            st.pop();
        }

    }

}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->left->right = new node(4);
    root->left->left->right->right = new node(5);
    root->left->left->right->right->right = new node(6);
    root->right = new node(7);
    root->right->left = new node(8);

    vector<int> preorder, inorder, postorder;

    allTraversal(root, preorder, inorder, postorder);
    
    for(auto i : preorder)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    for (auto i : inorder)
    {
        cout << i << " ";
    }

    cout<<endl;

    for (auto i : postorder)
    {
        cout << i << " ";
    }

    return 0;
}