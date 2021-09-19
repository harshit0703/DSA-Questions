#include<iostream>
using namespace std;

int main(){
    //inverted half pyramind

    int rows;
    cin>>rows;
    for(int i=rows; i>=1; i--){
        for(int j=i; j>=1; j--){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}