#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack<int>s1;
    stack<int>s2;

    public:
    
    void push(int val){
        s1.push(val);
    }
    
    int pop(){
        if (s1.empty() && s2.empty()){
            cout<<"queue is empty.";
            return -1;
        }
        
        if(s2.empty()){
            while(!s1.empty()){
                int topval = s1.top();
                s1.pop();
                s2.push(topval);
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }

    bool empty(){
        if (s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    // queue functionality can be achieved by using 2 stacks
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty();

    return 0;
}