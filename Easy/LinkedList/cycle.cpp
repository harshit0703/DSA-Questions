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

void insertHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startnode;
    int cnt = 1;
    while(temp->next != NULL){
        if (pos == cnt){
            startnode = temp;
        }
        temp = temp->next;
        cnt++;
    }
    temp->next = startnode;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL){
        if (fast == slow){
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int main()
{
    node *head = NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertHead(head, 5);
    insertHead(head, 6);
    display(head);
    makeCycle(head, 3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
    return 0;
}