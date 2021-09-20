#include<iostream>
using namespace std;

int main(){
    //pyramind using numbers-2
    int rows;
    cin>>rows;
    int cnt=1;
    for(int i=1; i<=rows; i++){
        for(int j=rows; j>=1; j--){
            if(j<=i){
                cout<<cnt++<<" ";
            }else{
                cout<<" ";
            }
        }
        cnt = 1;
        cout<<endl;
    }
    return 0;
}