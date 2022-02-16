#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val){
    if(head == NULL){
        head = new node(val);
        return;
    }

    node* temp = head;
    node* ptr = new node(val);

    while(temp->next != NULL) temp = temp->next;
    temp->next = ptr;

}

void display(node* &head){
    if(head == NULL) return;
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* reverse(node* head){
    if(head == NULL || head->next == NULL) return head;
    node* currptr = head;
    node* prevptr = NULL;
    node* nextptr;
    // we completely reverse the whole ll using single traversal without any extra space
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node* reversePair(node* head){
    if(head == NULL || head->next == NULL) return head;
    int cnt = 0;
    node* currptr = head;
    node* prevptr = NULL;
    node* nextptr;
    // our task is to reverse just a pair and then call this function recursively for the remaining ll

    while(currptr != NULL && cnt < 2){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        cnt++;
    }

    head->next = reversePair(currptr);

    return prevptr;

}

int main()
{
    node* head = new node(1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    display(head);
    // node* newHead = reverse(head);
    // display(newHead);
    node* revHead = reversePair(head);
    display(revHead);
    return 0;
}