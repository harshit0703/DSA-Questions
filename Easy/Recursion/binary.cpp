#include<iostream>
#include<string>
using namespace std;

void binary(int n, int one, int zero, string ans){
    if(one + zero == n){
        cout<<ans<<endl;
        return;
    }
    binary(n, one+1, zero, ans + '1');
    if(zero  < one){
        binary(n, one, zero+1, ans + '0');
    }
}

int main(){
    int n;
    cin>>n;
    binary(n, 0, 0, "");
    return 0;
}