#include<iostream>
using namespace std;

void inc_order(int n){
    if(n == 0){
        return ;
    }
    inc_order(n-1); // left call
    cout<<n<<endl;
}

void dec_order(int n){
    if(n == 0){
        return ;
    }
    cout<<n<<endl;
    dec_order(n-1); // right call
}

int main(){
    int n;
    cin>>n;
    inc_order(n);
    dec_order(n);
    return 0;
}