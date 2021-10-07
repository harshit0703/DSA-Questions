#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;

    public:

    void push(int val){
        // in this method we will make the push menthod costly
        q2.push(val);
        while(!q1.empty()){
            int backval = q1.front();
            q1.pop();
            q2.push(backval);
        }
        // now we need to swap the queues
        queue <int>temp  = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop(){
        if(q1.empty()){
            cout<<"stack is empty";
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    bool empty(){
        if(q1.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    // stack functionality can be achieved by using 2 queues
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}