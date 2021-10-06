#include<iostream>
using namespace std;
#define n 100

class queue{

    int *arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int val){
        if (back == n-1){
            cout<<"queue overflow";
            return;
        }
        back++;
        arr[back] = val;

        if(front == -1){
            front++;  // this will make sure that the front get incremented with the creation of the very first element
        }
    }

    void pop(){
        if (front == -1 || front > back){
            cout<<"queue is empty";
            return;
        }
        front++;
    }

    int peak(){
        if (front == -1 || front > back){
            cout<<"no elements present inside the queue";
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if (front == -1 || front > back){
            cout<<"no elements present inside the queue";
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
    cout<<q.peak()<<endl;
    cout<<q.empty();
    return 0;
}