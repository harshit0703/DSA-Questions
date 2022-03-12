#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert(node *&head, int n)
{

    if (head == NULL)
    {
        head = new node(n);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node *ptr = new node(n);
    temp->next = ptr;
}

void display(node *&head)
{
    if (head == NULL)
        return;

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

node *copyLL(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *newHead = NULL;

    while (head != NULL)
    {
        int val = head->data;
        insert(newHead, val);
        head = head->next;
    }

    return newHead;
}

int main()
{
    vector<int> v = {1, 4, 5, 6};
    node *head = NULL;
    for (int i : v)
    {
        insert(head, i);
    }

    display(head);

    node *newHead = copyLL(head);

    display(newHead);

    return 0;
}