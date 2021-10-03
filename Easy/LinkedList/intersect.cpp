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

int length(node* &head){
    node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void makeInersect(node* &head1, node* &head2, int n){
    node* temp = head1;
    while(n>0){
        temp = temp->next;
        n--;
    }
    node* temp2 = head2;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

int intersect(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int diff = 0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        diff = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        diff = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(diff){
        ptr1 = ptr1->next;
        if (ptr1->next == NULL){
            return -1;
        }
        diff--;
    }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;

}

int main()
{
    node *head1 = NULL;
    insertAtTail(head1, 7);
    insertAtTail(head1, 8);
    insertAtTail(head1, 9);
    insertAtHead(head1, 99);
    insertAtHead(head1, 100);
    display(head1);

    node*head2 = NULL;
    insertAtTail(head2, 10);
    insertAtTail(head2, 30);
    insertAtTail(head2, 20);
    display(head2);

    makeInersect(head1, head2, 3);
    cout<<intersect(head1, head2);
    return 0;
}