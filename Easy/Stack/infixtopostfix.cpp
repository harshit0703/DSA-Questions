#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precedence(char ch){
    if (ch == '^'){
        return 3;
    }else if (ch == '*' || ch == '/'){
        return 2;
    }else if (ch == '+' || ch == '-'){
        return 1;
    }else{
        return -1;
    }
}

string infixToPostfix(string str){

    string ans = "";
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        if ((str[i] >= 'a' && str[i]<='z') || (str[i] >= 'A' && str[i] <= 'Z')){
            ans += str[i];
        }
        else if(str[i] == '('){
            st.push(str[i]);
        }
        else if (str[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop(); // this will remove the opening bracket from the stack
            }
        }
        else{
            while(!st.empty() && (precedence(st.top()) > precedence(str[i]))){
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        
    }

    while(!st.empty()){
            ans += st.top();
            st.pop();
        }
    return ans;

}

int main(){
    string str = "(a-b/c)*(a/k-l)";
    cout<<infixToPostfix(str);
    
    return 0;
}