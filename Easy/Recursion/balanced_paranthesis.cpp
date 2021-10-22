#include<iostream>
#include<string>
using namespace std;

void balPar(int open, int close, string ans){
    if(open == 0 && close == 0){
        cout<<ans<<endl;
        return;
    }
    // case 1 : string is empty
    if(ans.length() == 0){
        balPar(open-1, close, ans + '(');
    }
    else{
        // case 2 : no open brackets remaining
        if(open == 0){
            balPar(open, close-1, ans + ')');
        }
        else{
        // case 4 : both brackets are remaining
            balPar(open-1, close, ans + '(');
            if(open < close){
                // open will never be greater than close since we add it first in the empty string
                // if open == close it means equal pairs are present and then we cannot add a closing bracket
                balPar(open, close - 1, ans + ')');
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    balPar(n, n, "");
    return 0;
}