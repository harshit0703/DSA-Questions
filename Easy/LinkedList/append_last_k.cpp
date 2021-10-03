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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    
    if(head == NULL){
        head = n;
        return;
    }

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
    cout<<endl;
}


int length(node* &head){
    node* temp = head;
    int cnt = 0;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

node* appendk(node* &head, int k){
    node* newhead;
    node* newtail;
    node* tail = head;
    int l = length(head);
    k = k%l;
    int cnt = 1;
    while(tail->next != NULL){
        
        if (cnt == l-k){
            newtail = tail;
        }
        if (cnt == l-k+1){
            newhead = tail;
        }
        tail = tail->next;
        cnt++;
    }
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtHead(head, 99);
    display(head);
    node* newhead = appendk(head, 2);
    display(newhead);
    return 0;
}