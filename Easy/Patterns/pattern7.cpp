#include<iostream>
using namespace std;

int main(){
    //inverted half pyramind using numbers
    int rows;
    cin>>rows;
    
    for(int i=rows; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}