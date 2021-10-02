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
    cout<<"NULL"<<endl;
}

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node* &head, int val){
    
    if (head == NULL){
        return ;      // empty linked list
    }

    if (head->next == NULL && head->data == val){
        deleteAtHead(head); // single element present in the linked list
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

int main(){
    node* head = NULL;
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtHead(head, 99);
    deletion(head, 7);
    display(head);
    return 0;
}