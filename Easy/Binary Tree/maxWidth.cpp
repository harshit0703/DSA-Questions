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

int maxWidth(node* root){
    if(root == NULL) return 0;
    queue<pair<node*, int>> q;
    q.push({root, 0});
    int ans = 0;

    while(!q.empty()){
        int size = q.size();
        int minIdx = q.front().second;
        int first, last;

        for(int i = 0; i < size; i++){
            int currIdx = q.front().second - minIdx;
            node* temp = q.front().first;
            q.pop();
            if(i == 0) first = currIdx;
            if(i == size - 1) last = currIdx;
            if(temp->left) q.push({temp->left, 2*currIdx + 1}); 
            if(temp->right) q.push({temp->right, 2*currIdx + 2}); 
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
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