#include <bits/stdc++.h>
using namespace std;

struct TNode
{
    char data;
    struct TNode *left;
    struct TNode *right;
};

struct TNode *newNode(char data);

struct TNode *arrayToTree(char arr[], int st, int en)
{
    if (st > en)
        return NULL;

    int mid = st + (en - st) / 2;
    struct TNode *root = newNode(arr[mid]);

    root->left = arrayToTree(arr, st, mid - 1);
    root->right = arrayToTree(arr, mid + 1, en);

    return root;
}

struct TNode *newNode(char data)
{
    struct TNode *node = (struct TNode *)malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preOrder(struct TNode *node)
{
    if (node == NULL)
        return;
    printf("%C", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void reverseArray(char *arr, int st, int en)
{
    while (st < en)
    {
        char x = arr[st];
        arr[st++] = arr[en];
        arr[en--] = x;
    }
}

void updateArray(char *arr, int n)
{
    int size;
    for (size = 0; arr[size] != '\0'; ++size)
    {
        reverseArray(arr, 0, size - 1);
        reverseArray(arr, 0, n - 1);
        reverseArray(arr, n, size - 1);
    }
}

int main()
{
    char arr[] = "jaaen*zrdpm";

    int n;
    for (n = 0; arr[n] != '\0'; ++n)
        ;

    struct TNode *root = arrayToTree(arr, 0, n - 1);
    preOrder(root);
    printf("-");

    updateArray(arr, 4);
    root = arrayToTree(arr, 0, n - 2);
    preOrder(root);
    printf("-");

    updateArray(arr, 2);
    root = arrayToTree(arr, 0, n - 1);
    preOrder(root);
    printf("-");

    updateArray(arr, 1);
    root = arrayToTree(arr, 0, n - 3);
    preOrder(root);

    return 0;
}