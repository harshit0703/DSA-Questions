#include<stack>
#include<iostream>
using namespace std;

void reverseStack(stack<int> st){

    if(st.empty()){
        return ;
    }

    int ele = st.pop();
    reverseStack(st);
    st.push(ele);

}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
}