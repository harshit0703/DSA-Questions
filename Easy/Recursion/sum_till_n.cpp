#include<iostream>
using namespace std;

int sum_nat(int n){
    if(n==0){// base condition
        return 0;
    }
    int prev_sum = sum_nat(n-1);
    return prev_sum + n;
}

int main(){
    // print the sum till n using recursion
    int n;
    cin>>n;
    int ans = sum_nat(n);
    cout<<ans;
    return 0;
}