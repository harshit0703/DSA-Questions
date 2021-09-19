#include<iostream>
using namespace std;

int main(){
    //half pyramind 180 rotated
    int rows;
    cin>>rows;

    for(int i=1; i<=rows; i++){
        for(int j=rows; j>=1; j--){
            if(j<=i){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}