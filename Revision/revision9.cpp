#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertHead(node* &head, int val){
    node* temp = new node(val);
    temp->next = head;
    head = temp;
}

void insertTail(node* &head, int val){
    if(head == NULL){
        insertHead(head, val);
    }
    else{
        node* temp = head;
        node* ptr = new node(val);
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void deleteHead(node* &head){
    if(head == NULL){
        cout<<"underflow";
        return;
    }
    else{
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deletion(node* &head, int val){
    if(head == NULL){
        cout<<"underflow";
        return;
    }
    if(head->next == NULL && head->data == val){
        deleteHead(head); // single node in LL
        return;
    }

    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;

}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    node* head = NULL;
    insertHead(head, 3);
    insertHead(head, 4);
    insertHead(head, 5);
    insertTail(head, 7);
    insertTail(head, 8);
    insertTail(head, 9);
    insertHead(head, 1);
    display(head);
    deleteHead(head);
    display(head);
    deletion(head, 7);
    display(head);
    return 0;
}