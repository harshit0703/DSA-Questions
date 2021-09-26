#include<iostream>
using namespace std;

int fact(int n){
    if (n == 0){
        return 1; // as 0! = 1
    }
    int prev_fact = fact(n-1);
    return prev_fact * n;
}

int main(){
    int n;
    cin>>n;
    int ans = fact(n);
    cout<<ans;
    return 0;
}