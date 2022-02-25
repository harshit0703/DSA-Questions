#include <iostream>
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

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return root;
    }

    if (root->data > val)
    {
        // update root->left
        root->left = insert(root->left, val);
    }
    else
    {
        // else update root right
        root->right = insert(root->right, val);
    }
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

node* inorderSucc(node* root, node* p){
    node* ans = NULL;

    while(root != NULL){
        if(p->data >= root->data){
            root = root->right;
        }else{
            // current node may be a possible candidate
            ans = root;
            root = root->left;
        }
    }

    return ans;

}

node* inorderPre(node* root, node* p){
    node* ans = NULL;

    while(root != NULL){
        if(root->data < p->data){
            ans = root;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }

    return ans;
}

int main()
{
    node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);
    insert(root, 7);
    insert(root, 6);
    insert(root, 9);
    insert(root, 8);
    insert(root, 10);

    node* p = new node(5);

    node* succ = inorderSucc(root, p);
    cout<<succ->data<<endl;

    node* pre = inorderPre(root, p);
    cout<<pre->data<<endl;

    inorder(root);
    // inorder traversal of bst will always provide sorted data members

    return 0;
}