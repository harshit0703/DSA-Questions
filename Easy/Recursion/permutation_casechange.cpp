#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void permutation(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    char ch_upper = toupper(ch);
    str = str.substr(1);
    permutation(str, ans + ch_upper);
    permutation(str, ans + ch);
    
}

int main(){
    string str; 
    cin>>str;
    permutation(str, "");
    return 0;
}