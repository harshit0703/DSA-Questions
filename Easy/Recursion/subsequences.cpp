#include<iostream>
#include<string>
using namespace std;

void print_subseq(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    string rem_str = str.substr(1);
    print_subseq(rem_str, ans + ch);
    print_subseq(rem_str, ans);
}

int main(){
    // at every stage we have 2 options either to include the element or not
    string str;
    cin>>str;
    print_subseq(str,"");
    return 0;
}