#include<iostream>
using namespace std;

int main(){
    //pyramind with numbers
    int rows;
    cin>>rows;
    for(int i=1; i<=rows; i++){
        for(int j=rows; j>=1; j--){
            if(j<=i){
                cout<<i<<" ";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}