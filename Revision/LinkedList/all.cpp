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
    node* ptr = new node(val);
    node* temp = head;

    while(temp ->next != NULL){
        temp = temp->next;
    }

    temp->next = ptr;

}


void insertBeg(node* &head, int val){
    if(head == NULL){
        head = new node(val);
        return;
    }

    node* temp = new node(val);
    temp->next = head;
    head = temp;
}


void deletenode(node* &head, int key){
    if(head == NULL){
        cout<<"underflow"<<endl;
        return;
    }

    // two possible cases key either be at the head or inside the linkedlist

    if(head->data == key){
        node* temp = head;
        head = head->next;
        delete temp;
        cout<<"deleted at the head"<<endl;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){  // we will only reach till second last node
        if(temp->next->data == key){
            node* ptr = temp->next;
            temp->next = temp->next->next;
            delete ptr;
            cout<<" deleted from the middle"<<endl;
            return;
        }
        temp = temp->next;
    }

}

node* reverseLL(node* &head){
    if(head == NULL){
        return NULL;
    }

    node* prev = NULL;
    node* temp = head;
    node* nextptr;

    while(temp != NULL){
        nextptr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextptr;
    }
    return prev;

}


node* reverseK(node* &head, int k){
    if(head == NULL){
        return NULL;
    }

    // we cannot reverse the group if it contains nodes less than k
    int cnt = 1;
    node* check = head;

    while(check->next != NULL){
        cnt++;
        check = check->next;
    }

    if(cnt < k){
        return head;
    }


    cnt = 0;
    node* curr = head;
    node* prev = NULL;
    node* nextptr;
    while(curr != NULL && cnt < k){
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        cnt++;
    }

    if(nextptr != NULL){
        head->next = reverseK(nextptr, k);      // head being the starting ptr
    }
    
    return prev;            // at the prev becomes the new tail of LL

}


bool detectCycle(node* &head){
    if(head == NULL){
        return false;
    }

    node* turtle = head;
    node* rabbit = head;

    while(rabbit != NULL && rabbit->next != NULL){
        turtle = turtle->next;
        rabbit = rabbit->next->next;
        if (turtle == rabbit)
        {
            return true;
        }
    }

    return false;

}


void removeCycle(node* head){
    node* turtle = head;
    node* rabbit = head;

    while(rabbit != NULL && rabbit->next != NULL){
        turtle = turtle->next;
        rabbit = rabbit->next->next;
        if(turtle == rabbit){
            rabbit = head;
            break;
        }
    }

    while(turtle->next != rabbit->next){
        turtle = turtle->next;
        rabbit = rabbit->next;
    }

    turtle->next = NULL;
}


node* appendk(node* &head, int k){
    if(head == NULL){
        return head;
    }

    node* ptr = head;
    int cnt = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        cnt++;
    }

    if(k > cnt){
        return head;
    }

    cnt = 1;
    node* temp = head;
    node* newhead = NULL;
    node* newtail = NULL;

    while(temp->next != NULL){
        if(cnt == k){
            newtail = temp;
            newhead = temp->next;
        }
        cnt++;
        temp = temp->next;
    }

    newtail->next = NULL;
    temp->next = head;
    return newhead;

}

int length(node* head){
    node* ptr = head;
    int cnt = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        cnt++;
    }

    return cnt;
}

int intersection(node* &h1, node* &h2){
    int l1 = length(h1);
    int l2 = length(h2);

    // given length of h1 > h2
    node* initial = h1;
    while(l1 != l2){
        initial = initial->next;
        l1--;
    }

    // main catch of the question is to find a starting point from which the lenght of both the ll will be same

    while(initial != NULL && h2 != NULL){
        if(initial == h2){
            return initial->data;
        }
        initial = initial->next;
        h2 = h2->next;
    }

    return -1;

}


node* mergeSortedLL(node* h1, node* h2){
    
    node* dummynode = new node(-1);
    node* ptr = dummynode;

    while(h1 != NULL && h2 != NULL){
        if(h1->data <= h2->data){
            ptr->next = h1;
            h1 = h1->next;
        }else{
            ptr->next = h2;
            h2 = h2->next;
        }
        ptr = ptr->next;
    }

    while(h1 != NULL){
        ptr->next = h1;
        ptr = ptr->next;
        h1 = h1->next;
    }

    while(h2 != NULL){
        ptr->next = h2;
        ptr = ptr->next;
        h2 = h2->next;
    }

    return dummynode->next;

}


node* mergeRecursive(node* &h1, node* &h2){

    if(h1 == NULL){
        return h2;
    }

    if(h2 == NULL){
        return h1;
    }

    node* ptr;

    if(h1->data <= h2->data){
        ptr = h1;
        ptr->next = mergeRecursive(h1->next, h2);
    }else{
        ptr = h2;
        ptr->next = mergeRecursive(h1, h2->next);
    }

    return ptr;

}


void evenodd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenstart = even;

    while(odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenstart;

    if(odd->next == NULL){
        even->next = NULL;
    }

}


void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 5);
    insert(head, 6);
    // print(head);
    // insertBeg(head, 5);
    // print(head);
    // deletenode(head, 5);
    // print(head);
    // deletenode(head, 3);
    // print(head);
    // deletenode(head, 4);
    // print(head);


    // print(head);
    // node* newHead = reverseLL(head);
    // node* newHead = reverseK(head, 2);
    // print(newHead);

    // cout<<detectCycle(head);

    // node* newhead = appendk(head, 3);
    // print(newhead);

    // node* head2 = NULL;
    // insert(head2, 3);
    // insert(head2, 4);

    // node* newhead = mergeRecursive(head, head2);
    // print(newhead);
    evenodd(head);
    print(head);

    return 0;
}