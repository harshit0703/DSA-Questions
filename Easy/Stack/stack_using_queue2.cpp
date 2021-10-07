#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;

    public:

    void push(int val){
        q1.push(val);
    }

    int pop(){
        // in this method we will make the pop function costly
        if(q1.empty()){
            cout<<"stack is empty";
            return -1;
        }
        while(q1.front() != q1.back()){
            int frontval = q1.front();
            q1.pop();
            q2.push(frontval);
        }
        // now only the last element will be remaining in q1
        int ans = q1.front();
        q1.pop();

        // before returning we need to swap the queues back
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

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