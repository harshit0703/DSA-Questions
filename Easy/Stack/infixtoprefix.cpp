#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
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

string infixToPrefix(string str){

    reverse(str.begin(), str.end());
    string ans = "";
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        if ((str[i] >= 'a' && str[i]<='z') || (str[i] >= 'A' && str[i] <= 'Z')){
            ans += str[i];
        }
        else if(str[i] == ')'){
            st.push(str[i]);
        }
        else if (str[i] == '('){
            while(!st.empty() && st.top() != ')'){
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

    reverse(ans.begin(), ans.end());
    return ans;

}

int main(){
    // the basic approach is exactly similar to the postfix conversion we just need to reverse the whole string first and then solve also making the brackets reverse 

    string str = "(a-b/c)*(a/k-l)";
    cout<<infixToPrefix(str);
    
    return 0;
}