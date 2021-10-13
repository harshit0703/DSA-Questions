#include<iostream>
#include<stack>
using namespace std;

int minele;
stack<int> st;

void push(int n){
    if(st.empty()){
        minele = n;
        st.push(n);
    }
    else{
        if(n > minele){
            st.push(n);
        }
        else{
            st.push( 2 * n - minele);  // if the element we are trying to push is less than the current min ele we need to push 
            minele = n;                // a currupt value which will act as a flag variable
        }
    }
}

void pop(){
    if(st.empty()){
        cout<<"stack is empty";
        return;
    }
    if(st.top() < minele){
        minele = 2 * minele -st.top(); // here since the flag variable is encountered which means this is the min ele so we need  to 
                                        // update the new min ele before deleting it
    }
    st.pop();
}

int top(){
    if (st.empty()){
        return -1;
    }
    if(st.top() > minele){
        return st.top();
    }
    else{
        return minele; 
    }

}

int main(){
    // TC = O(1) this is a special problem hence there is only a particular approach to this one
    return 0;
}