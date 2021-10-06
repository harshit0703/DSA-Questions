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

class queue{
    node* front;
    node* back;

    public:

    queue(){
        front = NULL;
        back = NULL;
    }

    void push(int data){
        // since it is a linked list there will be no condition for overflow
        node* n = new node(data);
      
        if (front == NULL){
            back = n;
            front = n; 
            return ; // to make the first point to the first node at the start
        }
        back->next = n;
        back = n;
    }

    void pop(){
        if(front == NULL){
            cout<<"Queue is empty.";
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek(){
        if (front == NULL){
            cout<<"no element present in the queue";
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if (front == NULL){
            cout<<"no element present in the queue";
            return true;
        }
        return false;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;
    return 0;
}