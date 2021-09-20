#include<iostream>
using namespace std;

int main(){
    // verifying the pythagoras theorem
    int p,b,h;
    cin>>p>>b>>h;
    if(p*p == b*b + h*h){
        cout<<"verified you can make a right triangle.";
    }else{
        cout<<"cannot form a right triangle.";
    }
    return 0;
}