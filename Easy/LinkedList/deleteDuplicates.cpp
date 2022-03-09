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

node *removeDuplicates(node *head)
{
    node *dummy = new node(0);
    dummy->next = head;
    node *prev = dummy;

    while (head != NULL)
    {

        if (head->next != NULL && head->data == head->next->data)
        {
            while (head->next != NULL && head->data == head->next->data)
            {
                head = head->next;
            }

            prev->next = head->next;
        }

        else
            prev = prev->next;

        head = head->next;
    }

    return dummy->next;
}

int main()
{
    node *head = NULL;
    vector<int> v = {1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7};
    for (auto i : v)
    {
        insert(head, i);
    }
    display(head);

    node *newHead = removeDuplicates(head);

    display(newHead);
    return 0;
}