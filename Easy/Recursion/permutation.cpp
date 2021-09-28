#include<iostream>
#include<string>
using namespace std;

// TC = O(n*2^n)

void print_permutations(string str, string ans){
    if(str.length() == 0){
        cout<<ans<<endl;
        return ;
    }

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        string prev_str = str.substr(0, i); // string before the ith char
        string after_str = str.substr(i + 1);   // string after the char
        string rem_str = prev_str + after_str;
        
        print_permutations(rem_str, ans + ch);
    }
}

int main(){
    // we need to print all the permutations of a string using recursion
    string str;
    cin>>str;
    print_permutations(str, "");
    return 0;
}