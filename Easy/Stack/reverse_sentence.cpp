#include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string str){
    stack<string> s;

    for(int i=0; i<str.length(); i++){
        string word = "";
        while(str[i] != ' ' && i<str.length()){
            word += str[i];
            i++;
        }
        s.push(word);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}

int main(){
    string str = "My name is Harshit.";
    reverseSentence(str);
    return 0;
}