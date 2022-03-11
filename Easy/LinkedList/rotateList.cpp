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

int findLen(node *&head)
{

    node *temp = head;

    int len = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

node *rotateList(node *head, int k)
{

    if (head == NULL || head->next == NULL)
        return head;

    int len = findLen(head);

    // since the ll will repeat itself after len rotations

    k = k % len;
    if (k == 0)
        return head;

    int travel = len - k;

    node *curr = head;
    node *temp = head->next;

    while (travel > 1)
    {
        curr = curr->next;
        temp = temp->next;
        travel--;
    }

    curr->next = NULL;
    node *newHead = temp;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;

    return newHead;
}

int main()
{
    node *head = NULL;
    vector<int> v = {1, 2, 3, 4, 5};
    for (int i : v)
    {
        insert(head, i);
    }
    display(head);

    node *newHead = rotateList(head, 7);
    display(newHead);
    return 0;
}