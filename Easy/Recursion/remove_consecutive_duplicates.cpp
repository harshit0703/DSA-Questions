#include<iostream>
#include<string>
using namespace std;

string remove_dup(string str){
    if(str.length() == 0){
        return "";
    }
    char ch = str[0];
    string ans = remove_dup(str.substr(1));
    if(ch == ans[0]){
        return ans;
    }
    return (ch + ans);

}

int main(){
    // remove all the duplicates from the string using recursion
    string str;
    cin>>str;
    string ans = remove_dup(str);
    cout<<ans;
    return 0;
}