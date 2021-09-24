#include<iostream>
#include<string>
using namespace std;

int main(){
    // convert whole string to upper/lower case
    // ascii value A=65 a=32
    string str;
    cin>>str;
    for(int i=0; i<str.size(); i++){
        if(str[i] >='a' || str[i] <= 'z'){
            str[i] -= 32;// for lower case only the sign changes
        }
    }
    cout<<str;
    return 0;
}