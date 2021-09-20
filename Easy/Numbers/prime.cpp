#include<iostream>
using namespace std;

int main(){
    //check for prime
    int n;
    cin>>n;
    int flag = 0;
    for(int i=2; i*i<n; i++){
        // factors repeat themselves after perfect square
        if(n%i == 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout<<"Not Prime";
    }else{
        cout<<"Prime";
    }
    return 0;
}