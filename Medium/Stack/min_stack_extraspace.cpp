#include<iostream>
#include<stack>
using namespace std;

stack<int>st;
stack<int>ss;  // here we are making the use of a supporting stack which only stores the min ele of the stack
                // TC = O(n)

void push(int n){
    if(ss.empty()){
        ss.push(n);
    }
    else if(n<=ss.top()){
        ss.push(n);
    }
    st.push(n);
}

void pop(){
    int n = st.top();
    st.pop();
    if(n == ss.top()){
        ss.pop();
    }
}

int minele(){
    if(ss.empty()){
        return -1;
    }
    return ss.top();
}

int main(){
    int arr[] = {18, 19, 29, 15, 16};
    for(int i: arr){
        push(i);
    }

    cout<<minele();

    return 0;
}