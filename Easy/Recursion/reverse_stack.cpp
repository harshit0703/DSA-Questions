#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack <int> &st){
    if(st.size() == 1){
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertStack(st, temp);
}

void insertStack(stack <int> &st, int temp){
    if(st.size() == 0){
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insertStack(st, temp);
    st.push(val);
}

void printStack(stack<int> st){
    if(st.size() == 0){
        return;
    }
    cout<<st.top()<<" ";
    st.pop();
    printStack(st);
}

int main(){
    stack<int> st;
    int arr[] = {4, 3, 1, 0, 5};
    for(int i=0; i<5; i++){
        st.push(arr[i]);
    }
    printStack(st);
    cout<<endl;
    reverseStack(st);
    printStack(st);
    return 0;
}