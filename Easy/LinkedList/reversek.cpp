#include<iostream>
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
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertTail(node* &head, int val){
    if (head == NULL){
        insertHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverseK(node* &head, int k){
    node* currptr = head;
    node* prevptr = NULL;
    node* nextptr;
    int cnt = 0;
    while(currptr != NULL && cnt<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        cnt++;
    }
    if (nextptr != NULL){
        head->next = reverseK(nextptr, k);
    }
    return prevptr;
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
    node* newhead = reverseK(head, 2);
    display(newhead);
    return 0;
}