#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertHead(node* &head, int val){
    node* n = new node(val);
    n->next = head; 
    if (head != NULL){
        head->prev = n;
    }
    head = n;
}

void insertTail(node* &head, int val){
    node* n = new node(val);
    if (head == NULL){
        insertHead(head, val);
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}

void deletion(node* &head, int pos){
    node* temp = head;
    if (pos == 1){
        deleteAtHead(head);
    }
    int cnt = 1;
    while(cnt<pos && temp != NULL){
        temp = temp->next;
        cnt++;
    }
    if (temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    delete temp;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertHead(head, 5);
    insertHead(head, 6);
    display(head);
    deletion(head, 2);
    display(head);
    return 0;
}