#include<iostream>
using namespace std;

void print_fibonacci(int n, int a, int b){
    if(n == 0){
        return ;
    }
    int c = a+b;
    cout<<a<<" ";
    print_fibonacci(n-1, b, c) ;
}

int main(){
    int terms;
    cin>>terms;
    print_fibonacci(terms, 0, 1); // 0 and 1 are the constant first two terms rest are the sum of the previous 2 terms
    return 0;
}