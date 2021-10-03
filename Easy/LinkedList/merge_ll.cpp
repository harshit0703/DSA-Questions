#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node* merge(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummynode = new node(-1);
    node* p3 = dummynode;

    while(p1 != NULL && p2 != NULL){
        if (p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while(p1 != NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while(p2 != NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummynode->next;

}

int main()
{
    node *head1 = NULL;
    insertAtTail(head1, 7);
    insertAtTail(head1, 8);
    insertAtTail(head1, 9);
    insertAtTail(head1, 10);
    display(head1);
    node* head2 = NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 5);
    display(head2);

    node* newhead = merge(head1, head2);
    display(newhead);
    return 0;
}