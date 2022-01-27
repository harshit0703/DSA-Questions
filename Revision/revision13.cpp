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

node* createBST(node* root, int val){
    if(root == NULL){
        node* root = new node(val);
        return root;
    }

    if(val < root->data){
        root->left = createBST(root->left, val);
    }

    else{
        root->right = createBST(root->right, val);
    }

    return root;

}

bool searchBST(node* root, int key){
    // TC = O(logN)
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data < key){
        return searchBST(root->right, key);
    }

    return searchBST(root->left, key);
}

node* deleteBST(node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(key < root->data){
        root->left = deleteBST(root->left, key);
    }

    else if(key > root->data){
        root->right = deleteBST(root->right, key);
    }

    else{
        // since the root is now equal to the given key we have 3 possible cases

        // root is a leaf node

        // if(root->left == NULL && root->right == NULL){
        //     free(root);
        // }

        if(root->left == NULL ){
            node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL ){
            node* temp = root->left;
            free(root);
            return temp;
        }

        else{
            node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;  // inorder successor    
            }
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
    }

    return root;

}

bool isBST(node* root, node* min=NULL, node*max=NULL){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool left = isBST(root->left, min, root);
    bool right = isBST(root->right, root, max);

    return left && right;

}

node* BstSorArr(vector<int> nums, int st, int en){
    if(st > en){
        return NULL;
    }

    int middle = st + (en - st)/2;
    node* root = new node(nums[middle]);

    root->left = BstSorArr(nums, st, middle - 1);
    root->right = BstSorArr(nums, middle + 1, en);

    return root;
}

void printBST(node* root){
    if(root == NULL){
        return ;
    }

    printBST(root->left);
    cout<<root->data<<" ";
    printBST(root->right);
}

pair<int, bool> solve(node* root, int st, int en){
    if(root == NULL){
        return {0, true};
    }

    pair<int, bool>left = solve(root->left, st, root->data);
    pair<int, bool>right = solve(root->right, root->data, en);

    if(root->data > st && root->data < en){
        if(left.second && right.second){
            return {left.first + right.first + 1, true};
        }
    }

    return {max(left.first, right.first), false};

}

int largestBstInBt(node* root){

    if(root == NULL){
        return 0;
    }

    pair<int, bool> ans= solve(root, INT_MIN, INT_MAX);

    return ans.first;

}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(node* root, node** prev, node** first, node** last, node** middle){
    if(root == NULL){
        return;
    }

    calcPointers(root->left, prev, first, last, middle);

    if(prev && (*prev)->data > root->data){
        if(*first == NULL){
            *first = *prev;
            *middle = root; 
        }
        else{
            *last = root;
        }
    }

    *prev = root;

    calcPointers(root->right, prev, first, last, middle);

}

void restoreBst(node* root){
    node* prev, * first, * last, * middle;

    first = last = middle = prev = NULL;

    calcPointers(root, &prev, &first, &last, &middle);

    if(first && last){
        swap(&first->data, &last->data);
    }else{
        swap(&first->data, &middle->data);
    }

}

struct NodeData{
    int maxVal;
    int minVal;
    int size;
};

NodeData recoverBst(node* root){
    if(root == NULL){
        return NodeData{INT_MIN, INT_MAX, 0};
    }

    NodeData left = recoverBst(root->left);
    NodeData right = recoverBst(root->right);

    if(root->data > left.maxVal && root->data < right.minVal){
        // it is a bst
        return {max(root->data, right.maxVal), min(root->data, left.minVal), left.size + right.size + 1};
    }

    // not a bst
    return{INT_MAX, INT_MIN, max(left.size, right.size)};

}

int main()
{
    node* root = NULL;
    root = createBST(root, 3);
    createBST(root, 2);
    createBST(root, 1);
    createBST(root, 6);
    createBST(root, 5);
    createBST(root, 7);
    // printBST(root);
    // inorder of bst is a sorted array
    // cout<<searchBST(root, 7);
    // printBST(root);
    root = deleteBST(root, 1);
    // printBST(root);

    // cout<<isBST(root, NULL, NULL);

    vector<int> nums = {1, 2, 3, 4, 5};
    node* root2 = BstSorArr(nums, 0, nums.size() - 1);
    printBST(root2);

    return 0;
}