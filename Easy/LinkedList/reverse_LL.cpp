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

node* reverse(node* &head){
    node* curr_ptr = head;
    node* prev_ptr = NULL;
    node* next_ptr;

    while(curr_ptr != NULL){
        next_ptr = curr_ptr->next;
        curr_ptr->next = prev_ptr;

        prev_ptr = curr_ptr;
        curr_ptr = next_ptr;
    }
    
    return prev_ptr;
}

node* reverseRecursive(node* &head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    node* new_head = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main(){
    node *head = NULL;
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtHead(head, 99);
    display(head);
    node* new_head = reverseRecursive(head);
    display(new_head);
    return 0;
}