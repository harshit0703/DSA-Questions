#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;     // differentiating factor in doubly LL

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insert(node* &head, int val){
    if(head == NULL){
        head = new node(val);
        return;
    }
    node* ptr = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->prev = temp;
}

void insertBeg(node* &head, int val){
    if(head == NULL){
        head = new node(val);
        return;
    }

    node* ptr = new node(val);
    ptr->next = head;
    head->prev = ptr;
    head = ptr;

}

void deletenode(node* &head, int key){
    if(head == NULL){
        cout<<"underflow";
        return;
    }

    if(head->data == key){
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            node* ptr = temp;
            temp->prev->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = temp->prev;
            }
            delete ptr;
            return;
        }

        temp = temp->next;
    }
}

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data;
        temp = temp->next;
    }

    cout<<endl;
}

int main()
{
    node* head = NULL;

    return 0;
}