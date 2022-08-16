#include<bits/stdc++.h>
using namespace std;

class Node{
    public : int value;
    Node* next;
};

Node* reverse(Node* head){

    Node* curr = head, *prev = NULL, *nextPtr;

    while(curr){

        nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;


    }

    return prev;

}

Node* middle(Node* head){

    Node* slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}

Node* update_linked_list(Node* head){

    if(head == NULL || head->next == NULL) return head;

    Node* temp = reverse(head);
    Node* mid = middle(head);

    Node* curr = head;

    while(curr){
        if(curr != mid){
            curr->value += temp->value;
        }

        curr = curr->next;
        temp = temp->next;

    }

    return head;


}

int main()
{
    
    return 0;
}