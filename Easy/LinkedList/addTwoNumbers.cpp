
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

node *solve(node *h1, node *h2, int carry)
{

    if (h1 == NULL && h2 == NULL)
    {
        if (carry == 0)
            return NULL;
        node *ptr = new node(carry);
        return ptr;
    }

    int val = 0;
    val += carry;
    if (h1)
        val += h1->data;
    if (h2)
        val += h2->data;

    int temp = 0;

    if (val >= 10)
    {
        val -= 10;
        temp = 1;
    }

    node *ptr = new node(val);

    if (!h1)
    {
        ptr->next = solve(h1, h2->next, temp);
    }

    else if (!h2)
    {
        ptr->next = solve(h1->next, h2, temp);
    }

    else
    {
        ptr->next = solve(h1->next, h2->next, temp);
    }

    return ptr;
}

int main()
{
    node *h1 = NULL;
    vector<int> v1 = {9};
    node *h2 = NULL;
    vector<int> v2 = {9};

    for (int i : v1)
    {
        insert(h1, i);
    }

    for (int i : v2)
    {
        insert(h2, i);
    }

    display(h1);
    display(h2);

    node *ans = solve(h1, h2, 0);

    display(ans);

    return 0;
}