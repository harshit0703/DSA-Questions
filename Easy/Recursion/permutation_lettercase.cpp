#include<iostream>
#include<string>
using namespace std;

void permutation(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    // now we have two choices if we encounter a number than add it to ans as it is
    char ch = str[0];
    str = str.substr(1);
    if(ch >= '0' && ch <= '9'){
        permutation(str, ans + ch);
    }
    // and if it is a character we need to change its case
    else if(ch >= 'a' && ch <= 'z'){
        char ch_upper = toupper(ch);
        permutation(str, ans + ch_upper);
        permutation(str, ans + ch);
    }
    else{
        char ch_lower = tolower(ch);
        permutation(str, ans + ch_lower);
        permutation(str, ans + ch);
    }
}

int main(){
    string str;
    cin>>str;       // now numbers can be included in the string
    permutation(str, "");
    return 0;
}