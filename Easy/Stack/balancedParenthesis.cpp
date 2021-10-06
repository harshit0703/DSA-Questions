#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string str){
    
    stack<char> st;
    for(int i=0; i<str.length(); i++){
        if (str[i] == '[' || str[i] == '(' || str[i] == '{'){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            if(st.top() == '{' || st.top() == '['){
                return false;
            }else{
                st.pop();
            }
        }else if(str[i] == ']'){
            if(st.top() == '{' || st.top() == '('){
                return false;
            }else{
                st.pop();
            }
        }else if(str[i] == '}'){
            if(st.top() == '(' || st.top() == '['){
                return false;
            }else{
                st.pop();
            }
        }
    }

    if(st.empty()){
        return true;
    }

}

int main(){
    string str = "{{[()]}}";
    cout<<isBalanced(str);
    return 0;
}