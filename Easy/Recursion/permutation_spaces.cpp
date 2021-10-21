#include<iostream>
#include<string>
using namespace std;

void permutation(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    str = str.substr(1);
    if(ans.length() == 0){
        permutation(str, ans + ch);         // we dont have to add any spaces at the begining
    }else{
        permutation(str, ans + ch);       // without space
        permutation(str, ans + "_" + ch); // with space
    }
    
}

int main(){
    string str;
    cin>>str;
    permutation(str, "");
    return 0;
}