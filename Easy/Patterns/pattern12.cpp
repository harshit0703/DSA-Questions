#include<iostream>
using namespace std;

int main(){
    //palindromic pattern
    int rows;
    cin>>rows;
    
    // palindromic pattern = half reverse pyramind + half pyramind
    for(int i=1; i<=rows; i++){
        for(int j=rows; j>=1; j--){
            if(j<=i){
                cout<<j<<" ";
            }else{
                cout<<"  ";
            }
        }
        for (int j = 2; j <= i; j++)
        {
            cout << j << " ";
        }
        cout<<endl;
    }
 
}