#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "((1+2))"; // only checking for +,-,*,/ operations
    stack<char> st;
    bool ans = false;
    for(int i=0; i<str.length(); i++){
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            if(st.top() == '('){
                ans = true;
                break;
            }
            while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/' ){
                st.pop();
            }
            st.pop();
        }
    }

    cout<<ans;

    return 0;
}