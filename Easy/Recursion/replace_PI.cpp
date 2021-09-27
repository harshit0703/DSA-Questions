#include<iostream>
#include<string>
using namespace std;

// TC = O(n^2)

string replace_pi(string str){

    if(str.length() == 0){
        return "";
    }
    char ch = str[0];
    string ans = replace_pi(str.substr(1));
    if(ch == 'p' && ans[0] == 'i'){
        return ("3.14" + ans.substr(1));
    }
    return (ch + ans);

}

int main(){
    // replace PI with 3.14 in the string
    string str;
    cin>>str;
    string ans = replace_pi(str);
    cout<<ans;
    return 0;
}