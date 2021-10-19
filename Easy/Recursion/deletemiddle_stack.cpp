#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int> &st, int idx){
    if(idx == 1){
        st.pop();
        return;
    }
    int val = st.top();
    st.pop();
    deleteMiddle(st, idx-1);
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
    deleteMiddle(st, st.size()/2 + 1);
    cout<<endl;
    printStack(st);
    return 0;
}