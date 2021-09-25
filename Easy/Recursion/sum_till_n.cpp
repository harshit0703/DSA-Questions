#include<iostream>
using namespace std;

int sum_nos(int n){
    if(n==0){
        return 0;
    }
    int prev_sum = sum_nos(n-1);
    return n + prev_sum;
}

int main(){
    // print the sum of n numbers using recursion
    int n;
    cin>>n;
    int sum = sum_nos(n);
    cout<<sum;
    return 0;
}